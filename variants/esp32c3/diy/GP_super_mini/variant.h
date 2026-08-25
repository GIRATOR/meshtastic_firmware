#ifndef _VARIANT_ESP32C3_SUPER_MINI_
#define _VARIANT_ESP32C3_SUPER_MINI_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define HAS_SCREEN 0
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

#define LED_STATE_ON 1
#define LED_POWER 8         // built in LED
#define BUTTON_PIN 9        // BOOT button

#define USE_RF95            // SX1278

#define LORA_RESET 3        // RST
#define LORA_DIO0 10 
#define LORA_DIO1 20        // IRQ
#define LORA_DIO2 21        // BUSY
#define LORA_BUSY LORA_DIO2

#define LORA_SCK   4 
#define LORA_MISO  5 
#define LORA_MOSI  6 
#define LORA_CS    7   

#define SX126X_DIO3_TCXO_VOLTAGE (1.8)

#define TCXO_OPTIONAL // make it so that the firmware can try both TCXO and XTAL

#ifdef __cplusplus
}
#endif

#endif
