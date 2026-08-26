
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define MESHTASTIC_EXCLUDE_BLUETOOTH 1 // currently does not compile with enabled PSRAM

#undef I2C_SDA
#undef I2C_SCL

//#define TX_GAIN_LORA 8
//#define SX126X_MAX_POWER 22

#define HAS_SCREEN 0
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

#define LED_STATE_ON 1
#define LED_POWER 12 // GREEN_2
               // 13 // YELLOW
               // 15 // BUZZER

#define USE_RF95 // SX1278


#define LORA_MISO 19 
#define LORA_SCK 21  
#define LORA_MOSI 23  
#define LORA_CS 5  

#define LORA_DIO0 26  
#define LORA_RESET 27 // RST
#define LORA_DIO1 33 // IRQ
//#define LORA_DIO2 32 // BUSY
#define LORA_BUSY LORA_DIO0

#define LORA_RXEN 14  // RX on E32
#define LORA_TXEN RADIOLIB_NC // connect TXEN to DIO2

// available pins
// 2 avoid strap, pull high OK
// 4
// 22
// 25
// 34 in only
// 35 in only

#define SX126X_DIO3_TCXO_VOLTAGE (1.8)

#define TCXO_OPTIONAL // make it so that the firmware can try both TCXO and XTAL

#ifdef __cplusplus
}
#endif
