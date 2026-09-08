/*
  "Analog keyboard" - low button count key-pads using only one analog pin;
  Each button corespond to distinct range of values, expecting lowest ~0 level when no key pressed;
  TODO: yet tested and optimised for NRF only, ESP reqires changes in adc read, look how battery code is done;
*/

#pragma once

#include "../input/InputBroker.h"
#include "concurrency/OSThread.h"
#include "graphics/Screen.h"

class AnalogKeyboard : public Observable<const InputEvent *>, public concurrency::OSThread
{
  public:
    explicit AnalogKeyboard(const char *name);

  protected:
    virtual int32_t runOnce() override;

  private:
    const char *_originName;
    bool akb_first_run = 1;
    virtual void akb_setup();

    bool akb_is_idle = 0;   // flag to decrease scan intensity, different then locked
    bool akb_is_locked = 0; // locked keypad functioanlity
    bool akb_is_mute = 0;   // do not produce sounds
    bool akb_is_shift = 0;  // shift level counter
    uint8_t akb_letter_this = 0; // letter level counter
    uint8_t akb_lang_this = 0; // currently selected language

    int32_t adc_raw_this = 0;     // last read adc value
    uint8_t akb_but_preessed = 0; // currently registerd button (0 = no button)
    uint8_t akb_but_prev = 0;     // previously evaluated button    
    uint8_t akb_but_old = 0;      // previous non-0 pressed button
    uint8_t akb_but_max = 0;      // max evaluated button since last instability (pull down)
    uint8_t akb_but_stab = 0;     // stability counter       

    bool akb_hold_is_done = 0; // flag to mark longer press is already triggered
    unsigned long akb_last_press = 0; // time value of last registered press    
    unsigned char akb_char_this = 0x00; // pending character to commit  

    // main runs
    virtual void akb_adc_read(); // segregate adc read logic
    virtual void akb_evaluate(); // adc-to-event logic

    // input events
    virtual void akb_idle(); // decrease scan intensity if nothing pressed
    virtual void akb_wakeup(int8_t but_id); // any button pressed during idle
    virtual void akb_btn_push(int8_t but_id); // any button pressed in active state
    virtual void akb_btn_hold(int8_t but_id); // any button held
    virtual void akb_btn_release(int8_t but_id); // button released
    
    // subs
    virtual void akb_update_state();
    virtual void akb_event_commit(input_broker_event event); // construct event and notify observers
    virtual void akb_event_notify(); // empty commit
    virtual void akb_switch_lang(); // language change sub
    virtual unsigned char akb_get_char(uint8_t ch_but); // load char from keymap
};

extern AnalogKeyboard *globalAnalogKeyboard;