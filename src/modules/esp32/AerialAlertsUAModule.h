#pragma once
#include "configuration.h"
#if defined(ARCH_ESP32) && HAS_NETWORKING && (AAUA_USE_MODULE > 0)
#include "SinglePortModule.h"

// As there is no support for this config in APPs or protocol, everything is defined here compile time
// define AAUA_USE_MODULE as 1 in your variant.h
// add "lib_deps = ${esp32_base.lib_deps} bblanchon/ArduinoJson@^7.4.3" to your platformio.ini

// how many times to send same alert; we can't reliably check for ack so just send multiple 
#define AAUA_MAX_LORA_ALERTS 3 
// web api requests interval in seconds; min is 15 to avoid ban
// if AAUA_MAX_LORA_ALERTS > 1 this also is delay between alerts
#define AAUA_API_CHECK_PERIOD 60 
// web api timeout in ms; to avoid stuckage
#define AAUA_API_TIMEOUT 1000 

// parser type 1: no districts - only regions (""states""), in JSON
// this one should be handlable without PSRAM
// "ubilling.net.ua/aerialalerts/?source=default" - most "alive"source is used
//                                      ?source=skog - local, Mørk Skogen.
//                                      ?klimenko - from Vadym Klymenko
//                                      ?jaam - from JAAM data server
//                                      ?aiu - from alerts.in.ua
//                                      ?ual - from ukrainealarm.com
#define AAUA_API_PARSER_TYPE 1
// url without "https://" or "http://", uncoment certificate to explicitly use https, no fallback
#define AAUA_API_URL "ubilling.net.ua/aerialalerts/?source=default"
//#define AAUA_API_MATCH "Вінницька область"
//#define AAUA_API_MATCH "Волинська область"
//#define AAUA_API_MATCH "Дніпропетровська область"
//#define AAUA_API_MATCH "Донецька область"
//#define AAUA_API_MATCH "Житомирська область"
//#define AAUA_API_MATCH "Закарпатська область"
//#define AAUA_API_MATCH "Запорізька область"
#define AAUA_API_MATCH "Івано-Франківська область"
//#define AAUA_API_MATCH "Київська область"
//#define AAUA_API_MATCH "Кіровоградська область"
//#define AAUA_API_MATCH "Луганська область"
//#define AAUA_API_MATCH "Львівська область"
//#define AAUA_API_MATCH "м. Київ"
//#define AAUA_API_MATCH "Миколаївська область"
//#define AAUA_API_MATCH "Одеська область"
//#define AAUA_API_MATCH "Полтавська область"
//#define AAUA_API_MATCH "Рівненська область"
//#define AAUA_API_MATCH "Сумська область"
//#define AAUA_API_MATCH "Тернопільська область"
//#define AAUA_API_MATCH "Харківська область"
//#define AAUA_API_MATCH "Херсонська область"
//#define AAUA_API_MATCH "Хмельницька область"
//#define AAUA_API_MATCH "Черкаська область"
//#define AAUA_API_MATCH "Чернівецька область"
//#define AAUA_API_MATCH "Чернігівська область"

// for https to work this must be root certificate of AAUA_API_URL is signed with
/*
// this is "ISRG Root X1" for "ubilling.net.ua", valid before "Mon, 04 Jun 2035 11:04:38 GMT"
#define AAUA_API_CA_CERT    "-----BEGIN CERTIFICATE-----\n" \
                            "MIIFazCCA1OgAwIBAgIRAIIQz7DSQONZRGPgu2OCiwAwDQYJKoZIhvcNAQELBQAw\n"    \
                            "TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh\n"    \
                            "cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4\n"    \
                            "WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu\n"    \
                            "ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBY\n"    \
                            "MTCCAiIwDQYJKoZIhvcNAQEBBQADggIPADCCAgoCggIBAK3oJHP0FDfzm54rVygc\n"    \
                            "h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+\n"    \
                            "0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U\n"    \
                            "A5/TR5d8mUgjU+g4rk8Kb4Mu0UlXjIB0ttov0DiNewNwIRt18jA8+o+u3dpjq+sW\n"    \
                            "T8KOEUt+zwvo/7V3LvSye0rgTBIlDHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH\n"    \
                            "B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC\n"    \
                            "B5iPNgiV5+I3lg02dZ77DnKxHZu8A/lJBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv\n"    \
                            "KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn\n"    \
                            "OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn\n"    \
                            "jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw\n"    \
                            "qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI\n"    \
                            "rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNV\n"    \
                            "HRMBAf8EBTADAQH/MB0GA1UdDgQWBBR5tFnme7bl5AFzgAiIyBpY9umbbjANBgkq\n"    \
                            "hkiG9w0BAQsFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V9lZL\n"    \
                            "ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ\n"    \
                            "3BebYhtF8GaV0nxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK\n"    \
                            "NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5\n"    \
                            "ORAzI4JMPJ+GslWYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur\n"    \
                            "TkXWStAmzOVyyghqpZXjFaH3pO3JLF+l+/+sKAIuvtd7u+Nxe5AW0wdeRlN8NwdC\n"    \
                            "jNPElpzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc\n"    \
                            "oyi3B43njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq\n"    \
                            "4RgqsahDYVvTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA\n"    \
                            "mRGunUHBcnWEvgJBQl9nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d\n"    \
                            "emyPxgcYxn/eR44/KJ4EBs+lVDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc=\n"    \
                            "-----END CERTIFICATE-----\n"
*/

class AAUAModule : public SinglePortModule, private concurrency::OSThread
{
    bool module_alert_prev = false; // previous state of module
    bool module_alert_now = false; // current state of module
    String source = ""; // source of alert info
    String cachedat = ""; // time of alert info update
    uint8_t module_alerts_lora_sent = AAUA_MAX_LORA_ALERTS; // count of alerts sent to mesh
    
    public:
        AAUAModule() : SinglePortModule("aerialalerts", meshtastic_PortNum_ALERT_APP), OSThread("aerialalerts")
        {
            isPromiscuous = true;
        }

    protected:
        virtual int32_t runOnce() override;
        void aaua_send_lora_alert();
        void aaua_check_state();
        void aaua_get_info();
        void aaua_parse_v1();

};

#endif