// copy from nrf52_promicro_diy_tcxo

#include "variant.h"
#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[] = {
    // P0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,

    // P1
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};

void initVariant()
{
    // 3V3 Power Rail
    pinMode(PIN_3V3_EN, OUTPUT);
    digitalWrite(PIN_3V3_EN, HIGH);
}

void variant_shutdown()
{
#ifdef INPUTBROKER_ANALOG_TYPE
    // Without power analog keyboard will not work, making it imposibble to wakeup device
    // TODO: update/bodge pcb to feed keyboard divider LDO directly form battery
    // digitalWrite(PIN_3V3_EN, LOW);
    
    // only buttons high on divider will be able to wakeup device
    // TODO: reroute pcb so "power" button has high enough level
    nrf_gpio_pin_sense_t sense = NRF_GPIO_PIN_SENSE_HIGH; // trigger on high edge high edge
    nrf_gpio_cfg_sense_set(KEYBOARD_PIN, sense);          // end sleep interruption
#else
    digitalWrite(PIN_3V3_EN, LOW);
    nrf_gpio_cfg_input(BUTTON_PIN, NRF_GPIO_PIN_PULLUP); // Enable internal pull-up on the button pin
    nrf_gpio_pin_sense_t sense = NRF_GPIO_PIN_SENSE_LOW; // Configure SENSE signal on low edge
    nrf_gpio_cfg_sense_set(BUTTON_PIN, sense);           // Apply SENSE to wake up the device from the deep sleep
#endif    

}
