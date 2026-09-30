#include "configuration.h"
#if defined(ARCH_ESP32) && HAS_NETWORKING && (AAUA_USE_MODULE > 0)

#include "AerialAlertsUAModule.h"
#include "Channels.h"
#include "MeshService.h"
#include "NodeDB.h"
#include "mesh/MeshTypes.h"
#include <Arduino.h>
#include <cctype>
#include <cstring>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <languages.h>

// defaults
#if (AAUA_API_CHECK_PERIOD < 15) // avoid ban
    #undef AAUA_API_CHECK_PERIOD
#endif
#ifndef AAUA_API_CHECK_PERIOD
    #define AAUA_API_CHECK_PERIOD 60
#endif

#ifdef AAUA_API_CA_CERT
#include <WiFiClientSecure.h>
const char *api_ca_cert = AAUA_API_CA_CERT;
#endif
HTTPClient api_client;
JsonDocument api_json;

int32_t AAUAModule::runOnce()
{
    aaua_get_info();
#if (AAUA_API_PARSER_TYPE == 1)
    aaua_parse_v1();
#endif
    aaua_check_state();

    return AAUA_API_CHECK_PERIOD*1000;
}

void AAUAModule::aaua_get_info()
{
    api_json.clear();
#ifdef AAUA_API_CA_CERT
    WiFiClientSecure *secure_client = new WiFiClientSecure;
    if (secure_client)
    {
        secure_client->setCACert(api_ca_cert);
        api_client.begin(*secure_client, "https://" + String(AAUA_API_URL));
    }
    else
    {
        LOG_DEBUG("Failed to create https client");
        return;
    }
#else
    api_client.begin("http://" + String(AAUA_API_URL));
#endif
    api_client.setConnectTimeout(AAUA_API_TIMEOUT);
    int api_http_code = api_client.GET();
    if (api_http_code == HTTP_CODE_OK) {
#if (AAUA_API_PARSER_TYPE == 1) // in case other types are not json here may be something else
        DeserializationError error = deserializeJson(api_json, api_client.getString());
        if (error) {
            LOG_DEBUG("deserializeJson() failed: %s", error.c_str());
        }
#endif
    }else{
        if (api_http_code > 0) 
        {
            LOG_DEBUG("http failed with code: %d", api_http_code);
        }
        else 
        {
            LOG_DEBUG("http failed with error: %s", api_client.errorToString(api_http_code).c_str());
        }
    } 
    api_client.end();
#ifdef AAUA_API_CA_CERT
    delete secure_client;
#endif
}

void AAUAModule::aaua_parse_v1()
{
    for (JsonPair state : api_json["states"].as<JsonObject>()) {
        if (state.key() == AAUA_API_MATCH){
            module_alert_now  = state.value()["alertnow"];
            source = String(api_json["source"]);
            cachedat = String(api_json["cachedat"]);
            LOG_DEBUG("%s, %s : %d", source.c_str(), cachedat.c_str(), module_alert_now);
        }
    }
}

void AAUAModule::aaua_check_state()
{
    if (module_alert_now != module_alert_prev)
    {
        module_alerts_lora_sent = 0;
        module_alert_prev = module_alert_now;
    }
    if (module_alerts_lora_sent < AAUA_MAX_LORA_ALERTS)
    {
        aaua_send_lora_alert();
        module_alerts_lora_sent = module_alerts_lora_sent + 1;
    }
}

void AAUAModule::aaua_send_lora_alert()
{
    String alert_text = "";
    if(module_alert_now)
    {
        alert_text = alert_text + str_aaua_start;
    }
    else
    {
        alert_text = alert_text + str_aaua_end;
    }
    alert_text = alert_text + AAUA_API_MATCH + "\n";
    alert_text = alert_text + "( " + cachedat + ",\n";
    alert_text = alert_text + source + " )";

    LOG_DEBUG("Sending aerial alert to lora");

    meshtastic_MeshPacket *p = allocDataPacket();
    p->to = NODENUM_BROADCAST;
    p->want_ack = false;
    p->decoded.want_response = false;
    p->priority = meshtastic_MeshPacket_Priority_ALERT;
    size_t len = strlen(alert_text.c_str());
    if (len > sizeof(p->decoded.payload.bytes)) {
        len = sizeof(p->decoded.payload.bytes);
    }
    p->decoded.payload.size = len;
    memcpy(p->decoded.payload.bytes, alert_text.c_str(), len);
    service->sendToMesh(p, RX_SRC_LOCAL, true);
}

#endif