// copy from nrf52_promicro_diy_tcxo

#ifndef _A70_NRF52_PROMICRO_
#define _A70_NRF52_PROMICRO_

#define VARIANT_MCK (64000000ul) // Master clock frequency

//#define USE_LFXO // Board uses 32khz crystal for LF
#define USE_LFRC // Board uses RC for LF

#define PROMICRO_DIY_TCXO

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
Custom pin assignement for Siemens A70 build
https://github.com/GIRATOR/meshtastic_firmware

| Pin   | Function      |     | Pin      | Function          |
| ----- | ------------- | --- | -------- | ----------------- |
| Gnd   |               |     | vbat     |                   |
| P0.06 | PIN_VIBRATION |     | vbat     |                   |
| P0.08 | FREE          |     | Gnd      |                   |
| Gnd   |               |     | reset    |                   |
| Gnd   |               |     | ext_vcc  | *see 0.13         |
| P0.17 | FREE          |     | P0.31    | BATTERY_PIN       |*
| P0.20 | I2C SDA       |     | P0.29    | KEYBOARD_PIN      |*
| P0.22 | I2C SCL       |     | P0.02    | PIN_BUZZER        |*
| P0.24 | LORA_DIO1     |     | P1.15    | PIN_PWM_BACKLIGHT |*
| P1.00 | LORA_DIO0     |     | P1.13    | LCD_DAT           |
| P0.11 | LORA_MOSI     |     | P1.11    | LCD_CLK           |
| P1.04 | LORA_MISO     |     | P0.10    | LCD_DC            |
| P1.06 | LORA_RESET    |     | P0.09    | LCD_RES           |
|       |               |     |          |                   |
|       | Mid board     |     |          | Internal          |
| P1.01 | LORA_SCK      |     | 0.15     | LED               |
| P1.02 | LORA_CS       |     | 0.13     | 3V3_EN            |
| P1.07 | RF95_RXEN     |     |          |                   |
*/

// PINS
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (2)
#define NUM_ANALOG_OUTPUTS (0)

// Siemens A70 LCD
#define HAS_SCREEN 1
#define USE_PCF8812 1
#define PCF8812_DAT (32 + 13) // P1.13
#define PCF8812_CLK (32 + 11) // P1.11
#define PCF8812_DC  ( 0 + 10) // P0.10
#define PCF8812_RST ( 0 +  9) // P0.09
#define PCF8812_BL  (32 + 15) // P1.15
#define PCF8812_SCREENSAVER 5 // Set this to 0 for no screensaver (save memory)
#define DISPLAY_FLIP_SCREEN 1

// External notification
#define PIN_PWM_BACKLIGHT (32 + 15) // P1.15
#define KEYBOARD_PIN      ( 0 + 29) // P0.29
#define PIN_BUZZER        ( 0 +  2) // P0.02

// Want some games
#define BASEUI_HAS_GAMES 1

// Enable pin for 3V3 LDO onn VCC pin
#define PIN_3V3_EN (0 + 13) // P0.13

// ADC
#define BATTERY_PIN (0 + 31) // P0.31 Battery ADC
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#undef  AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER (4.6425F)

// I2C (reqired for LCD and KBD code to work)
#define WIRE_INTERFACES_COUNT 1
#define PIN_WIRE_SDA (0 + 20) // P0.20
#define PIN_WIRE_SCL (0 + 22) // P0.22

//TODO: Temporary! LED
#define PIN_LED1 (0 + 15) // P0.15
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1

//TODO: Temporary! button
#define BUTTON_PIN (0 + 8) // P0.08

// Custom keyboard
#define USE_VIRTUAL_KEYBOARD 1
#define INPUTBROKER_ANALOG_TYPE 1

// NO UART
#define PIN_SERIAL1_TX (-1)  //
#define PIN_SERIAL1_RX (-1)  //
#define PIN_SERIAL2_RX (-1)  //
#define PIN_SERIAL2_TX (-1)  //

// NO GPS
#define MESHTASTIC_EXCLUDE_GPS 1
#define MESHTASTIC_EXCLUDE_WAYPOINT 1
#define MESHTASTIC_EXCLUDE_RANGETEST 1
//#define GPS_TX_PIN PIN_SERIAL1_TX // This is data from the MCU
//#define GPS_RX_PIN PIN_SERIAL1_RX // This is data from the GNSS
//#define PIN_GPS_EN (/) // 
//#define GPS_UBLOX
//#define GPS_DEBUG 1

// Serial interfaces
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO  (32 +  4)   // P1.04
#define PIN_SPI_MOSI  ( 0 + 11)   // P0.11
#define PIN_SPI_SCK   (32 +  1)   // P1.01

#define LORA_MISO     PIN_SPI_MISO
#define LORA_MOSI     PIN_SPI_MOSI
#define LORA_SCK      PIN_SPI_SCK
#define LORA_CS       (32 +  2)   // P1.02

// LORA MODULES
#define USE_SX1262
#define USE_RF95
#define USE_SX1268

// RF95 CONFIG
#define LORA_DIO0     (32 +  0)   // P1.00 BUSY
#define LORA_DIO1     ( 0 + 24)   // P0.24 IRQ
#define LORA_RESET    (32 +  6)   // P1.06 NRST

// RX/TX for RFM95/SX127x
#define RF95_RXEN     (32 +  7)   // P1.07
#define RF95_TXEN     RADIOLIB_NC // connect DIO2 to TXEN !

// SX126X CONFIG
#define SX126X_CS     (32 +  2)   // P1.02 FIXME - we really should define LORA_CS instead
#define SX126X_DIO1   ( 0 + 24)   // P0.24 IRQ
#define SX126X_DIO2_AS_RF_SWITCH  // connect DIO2 to TXEN !
#define SX126X_BUSY   (32 +  0)   // P1.00 BUSY
#define SX126X_RESET  (32 +  6)   // P1.06 NRST
#define SX126X_RXEN   (32 +  7)   // P1.07
#define SX126X_TXEN   RADIOLIB_NC // connect DIO2 to TXEN !

#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL // make it so that the firmware can try both TCXO and XTAL

#ifdef __cplusplus
}
#endif

#endif
