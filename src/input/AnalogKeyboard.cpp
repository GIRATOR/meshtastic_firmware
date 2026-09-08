#include "AnalogKeyboard.h"

#include "configuration.h"
#include "Nrf52SaadcLock.h"
#include "concurrency/LockGuard.h"
#include "buzz.h"

AnalogKeyboard *globalAnalogKeyboard = nullptr;

#ifdef INPUTBROKER_ANALOG_TYPE

/********************** A70 numeric phone keyboard **********************/

#if INPUTBROKER_ANALOG_TYPE == 1

    #ifndef AKB_DEBUG_ADC // no debug by default
        #define AKB_DEBUG_ADC 0
    #endif
    #ifndef AKB_IDLE_TIMEOUT // decrese scan intencity if no button pressed for this much time
        #define AKB_IDLE_TIMEOUT 10000 // 10 seconds
    #endif
    #ifndef AKB_AKB_DT_ACTIVE // scan interval when active
        #define AKB_DT_ACTIVE 0
    #endif
    #ifndef AKB_AKB_DT_IDLE // scan interval when idle
        #define AKB_DT_IDLE 100
    #endif
    #ifndef AKB_AKB_SC_ACTIVE // stability count when active
        #define AKB_SC_ACTIVE 16
    #endif
    #ifndef AKB_AKB_SC_IDLE // stability count when idle
        #define AKB_SC_IDLE 2
    #endif
    #ifndef AKB_SHORT_DELAY // fast press delay
        #define AKB_SHORT_DELAY 500
    #endif
    #ifndef AKB_LONG_DELAY // long press delay
        #define AKB_LONG_DELAY 1000
    #endif
    #ifndef AKB_LONGER_DELAY // long press delay
        #define AKB_LONGER_DELAY 3000
    #endif    
    
    #define BUTTONS_NUM 18
    // this values are borders between button ranges, assuming near-0 when no buttons pressed
    // aproximate first value and define AKB_DEBUG_ADC to see readings in console
    // calculate borders: AKB_LEVELS[0] = (0 + reading_but_1)/2; AKB_LEVELS[1] = (reading_but_1 + reading_but_2)/2; ...
    // define this as below in your variant.h
    #ifndef AKB_LEVELS
        #define AKB_LEVELS { 115, 305, 498, 685, 868, 1053, 1238, 1425, 1613, 1798, 1985, 2175, 2365, 2555, 2748, 2943, 3135, 3325 }
    #endif    
    uint16_t  adc_levels[BUTTONS_NUM] = AKB_LEVELS;

    // button events
    input_broker_event akb_events[BUTTONS_NUM+1] = {
    /* 0: no butt   */ INPUT_BROKER_NONE,    
    /* 1:  "#"      */ INPUT_BROKER_ANYKEY,
    /* 2:  "9"      */ INPUT_BROKER_ANYKEY,
    /* 3:  "6"      */ INPUT_BROKER_ANYKEY,
    /* 4:  "3"      */ INPUT_BROKER_ANYKEY,
    /* 5:  "CANCEL" */ INPUT_BROKER_CANCEL,
    /* 6:  "RIGHT"  */ INPUT_BROKER_RIGHT,
    /* 7:  "UP"     */ INPUT_BROKER_UP,
    /* 8:  "DOWN"   */ INPUT_BROKER_DOWN,
    /* 9:  "2"      */ INPUT_BROKER_ANYKEY,
    /* 10: "5"      */ INPUT_BROKER_ANYKEY,
    /* 11: "8"      */ INPUT_BROKER_ANYKEY, 
    /* 12: "0"      */ INPUT_BROKER_ANYKEY, 
    /* 13: "*"      */ INPUT_BROKER_ANYKEY, 
    /* 14: "7"      */ INPUT_BROKER_ANYKEY, 
    /* 15: "4"      */ INPUT_BROKER_ANYKEY, 
    /* 16: "1"      */ INPUT_BROKER_ANYKEY, 
    /* 17: "OK"     */ INPUT_BROKER_SELECT,
    /* 18: "LEFT"   */ INPUT_BROKER_LEFT,
    };

    // non-anykey buttons
    #define AKB_BUT_PING     17 // long hold "OK"
    #define AKB_BUT_SHUTDOWN  5 // long hold CANCEL
    
    // anykey buttons
    #define AKB_BUT_SHIFT    13 // push for shift, hold for lang change
    #define AKB_BUT_LOCK      1 // long hold "#"
    #define AKB_BUT_BACK      1 // push for backspace

    // alt text edit mode
    #define AKB_BUT_TAB       7 // up for tab
    #define AKB_BUT_EMO      8 // down for emote

    // translate button id to letter id
    const uint8_t let_id[BUTTONS_NUM+1] = {
    /* 0: no butt   */ 0,    
    /* 1:  "#"      */ 0,
    /* 2:  "9"      */ 9,
    /* 3:  "6"      */ 6,
    /* 4:  "3"      */ 3,
    /* 5:  "CANCEL" */ 0,
    /* 6:  "RIGHT"  */ 0,
    /* 7:  "UP"     */ 0,
    /* 8:  "DOWN"   */ 0,
    /* 9:  "2"      */ 2, 
    /* 10: "5"      */ 5,
    /* 11: "8"      */ 8,
    /* 12: "0"      */ 0,
    /* 13: "*"      */ 0, 
    /* 14: "7"      */ 7,
    /* 15: "4"      */ 4,
    /* 16: "1"      */ 1,
    /* 17: "OK"     */ 0,
    /* 18: "LEFT"   */ 0,
    }; 

    unsigned char ch_secondary = 0x00;
    const unsigned char lang_names[2][3] = {"EN","UA"};
    char report_states[21] = {'a', 'k', 'b', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    // code expects 0 language always to be EN with single byte characters
    // [shift][button][char]
    const unsigned char let_map[2][10][6] = {
        { // no shift
    /* 0 */ {  '+',  '-',  '*',  '/',  '=',  '0' },
    /* 1 */ {  ' ',  '.',  ',',  '!',  '?',  '1' },               
    /* 2 */ {  'a',  'b',  'c',  '2', 0x00, 0x00 },
    /* 3 */ {  'd',  'e',  'f',  '3', 0x00, 0x00 },
    /* 4 */ {  'g',  'h',  'i',  '4', 0x00, 0x00 },
    /* 5 */ {  'j',  'k',  'l',  '5', 0x00, 0x00 },
    /* 6 */ {  'm',  'n',  'o',  '6', 0x00, 0x00 },
    /* 7 */ {  'p',  'q',  'r',  's',  '7', 0x00 },
    /* 8 */ {  't',  'u',  'v',  '8', 0x00, 0x00 },
    /* 9 */ {  'w',  'x',  'y',  'z',  '9', 0x00 },
        },
        { // shift
    /* 0 */ {  '>',  '<', '\\',  '%',  '^',  '#' },
    /* 1 */ {  '_',  '@',  ':',  ';',  '&',  '$' },                
    /* 2 */ {  'A',  'B',  'C', 0x00, 0x00, 0x00 },
    /* 3 */ {  'D',  'E',  'F', 0x00, 0x00, 0x00 },
    /* 4 */ {  'G',  'H',  'I', 0x00, 0x00, 0x00 },
    /* 5 */ {  'J',  'K',  'L', 0x00, 0x00, 0x00 },
    /* 6 */ {  'M',  'N',  'O', 0x00, 0x00, 0x00 },
    /* 7 */ {  'P',  'Q',  'R',  'S', 0x00, 0x00 },
    /* 8 */ {  'T',  'U',  'V', 0x00, 0x00, 0x00 },
    /* 9 */ {  'W',  'X',  'Y',  'Z', 0x00, 0x00 },
        },
    };
    
    // code expects all other languages to use 2-byte characters
    // [languages][shift][button][char][byte]
    const unsigned char let_map_extra[1][2][10][6][2] = {
// UA:
        {
            { // no shift
        /* 0 */ { { 0x00,  '(' },   { 0x00,  ')' },	{ 0x00,  '[' },	{ 0x00,  ']' },	{ 0x00,  '{' },	{ 0x00,  '}' } },
        /* 1 */ { { 0x00,  ' ' },	{ 0x00,  '.' },	{ 0x00,  ',' },	{ 0x00,  '!' },	{ 0x00,  '?' },	{ 0x00,  '1' } },      
        /* 2 */ { { 0xD0, 0xB0 },	{ 0xD0, 0xB1 },	{ 0xD0, 0xB2 },	{ 0xD0, 0xB3 },	{ 0xD2, 0x91 },	{ 0x00,  '2' } },
        /* 3 */ { { 0xD0, 0xB4 },	{ 0xD0, 0xB5 },	{ 0xD1, 0x94 },	{ 0xD0, 0xB6 },	{ 0xD0, 0xB7 },	{ 0x00,  '3' } },
        /* 4 */ { { 0xD0, 0xB8 },	{ 0xD1, 0x96 },	{ 0xD0, 0xB9 },	{ 0xD0, 0xBA },	{ 0xD0, 0xBB },	{ 0x00,  '4' } },
        /* 5 */ { { 0xD0, 0xBC },	{ 0xD0, 0xBD },	{ 0xD0, 0xBE },	{ 0x00,  '5' },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
        /* 6 */ { { 0xD0, 0xBF },	{ 0xD1, 0x80 },	{ 0xD1, 0x81 },	{ 0x00,  '6' },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
        /* 7 */ { { 0xD1, 0x82 },	{ 0xD1, 0x83 },	{ 0xD1, 0x84 },	{ 0xD1, 0x85 },	{ 0x00,  '7' },	{ 0x00, 0x00 } },
        /* 8 */ { { 0xD1, 0x86 },	{ 0xD1, 0x87 },	{ 0xD1, 0x88 },	{ 0xD1, 0x89 },	{ 0xD1, 0x8C },	{ 0x00,  '8' } },
        /* 9 */ { { 0xD1, 0x97 },	{ 0xD1, 0x8E },	{ 0xD1, 0x8F },	{ 0x00,  '9' },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
            },
            { // shift
        /* 0 */ { { 0xC2, 0xB0 },	{ 0xC2, 0xA7 },	{ 0x00,  '|' },	{ 0xC2, 0xB5 },	{ 0xC2, 0xA4 },	{ 0x00, 0x00 } },
        /* 1 */ { { 0x00,  '_' },	{ 0x00,  '@' },	{ 0x00,  ':' },	{ 0x00,  ';' },	{ 0x00,  '&' },	{ 0x00,  '$' } },
        /* 2 */ { { 0xD0, 0x90 },	{ 0xD0, 0x91 },	{ 0xD0, 0x92 },	{ 0xD0, 0x93 },	{ 0xD2, 0x90 },	{ 0x00, 0x00 } },
        /* 3 */ { { 0xD0, 0x94 },	{ 0xD0, 0x95 },	{ 0xD0, 0x84 },	{ 0xD0, 0x96 },	{ 0xD0, 0x97 },	{ 0x00, 0x00 } },
        /* 4 */ { { 0xD0, 0x98 },	{ 0xD0, 0x86 },	{ 0xD0, 0x99 },	{ 0xD0, 0x9A },	{ 0xD0, 0x9B },	{ 0x00, 0x00 } },
        /* 5 */ { { 0xD0, 0x9C },	{ 0xD0, 0x9D },	{ 0xD0, 0x9E },	{ 0x00, 0x00 },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
        /* 6 */ { { 0xD0, 0x9F },	{ 0xD0, 0xA0 },	{ 0xD0, 0xA1 },	{ 0x00, 0x00 },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
        /* 7 */ { { 0xD0, 0xA2 },	{ 0xD0, 0xA3 },	{ 0xD0, 0xA4 },	{ 0xD0, 0xA5 },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
        /* 8 */ { { 0xD0, 0xA6 },	{ 0xD0, 0xA7 },	{ 0xD0, 0xA8 },	{ 0xD0, 0xA9 },	{ 0xD0, 0xAC },	{ 0x00, 0x00 } },
        /* 9 */ { { 0xD0, 0x87 },	{ 0xD0, 0xAE },	{ 0xD0, 0xAF },	{ 0x00, 0x00 },	{ 0x00, 0x00 },	{ 0x00, 0x00 } },
            },
        },
// language 2:

// language 3:

    };    

/********************** A70 numeric phone keyboard **********************/

#endif

// setup
void AnalogKeyboard::akb_setup()
{
#ifndef ARCH_NRF52   
    LOG_ERROR("Analog Keyboard yet implemented for NRF platform only");
    disable();
#else
    pinMode(KEYBOARD_PIN, INPUT);
    LOG_DEBUG("analog keyboard setup");
 
#endif 
}

void AnalogKeyboard::akb_adc_read()
{
    //TODO: implement esp adc related stuff here
    concurrency::LockGuard saadcGuard(concurrency::nrf52SaadcLock);
    adc_raw_this = analogRead(KEYBOARD_PIN);
}

// adc-to-events logic
void AnalogKeyboard::akb_evaluate()
{
    uint32_t time_buffer;

    // evaluate button
    // find first value larger then reading - this is our button index
    // if no match - akb_but_this stays BUTTONS_NUM, which is last button
    int8_t i = 0;    
    int8_t akb_but_this = BUTTONS_NUM;
    while((i < BUTTONS_NUM) && (akb_but_this == BUTTONS_NUM))
    {                  
        if(adc_raw_this < adc_levels[i])
        { 
            akb_but_this = i;
        }
        i = i + 1;
    }
    akb_but_max = max(akb_but_max, akb_but_this);

    if (akb_but_preessed == 0) // no button registered
    {        
        if ((akb_but_this > 0) && (akb_but_this == akb_but_prev)) // check if button is stable
        { 
            akb_but_stab = akb_but_stab + 1; // count stable read
            if (  
                ((akb_is_idle) && (akb_but_stab >= AKB_SC_IDLE)) 
                || 
                ((!akb_is_idle) && (akb_but_stab >= AKB_SC_ACTIVE))
            )
            { // stability level reached, processing push          
                if(!akb_is_idle)
                {    
#if (AKB_DEBUG_ADC == 0) 
                    akb_btn_push(akb_but_max);
#else
                    LOG_DEBUG("adc:%d, push: %d(%d)", adc_raw_this, akb_but_max, akb_but_this);
#endif  
                }
                else
                {
                    akb_wakeup(akb_but_max);
                    akb_is_idle = 0;
                }

                akb_last_press = millis();
                akb_but_preessed = akb_but_max;  
                // reset       
                akb_hold_is_done = 0;
                akb_but_stab = 0;
                akb_but_max = 0;
            }
        }
        else
        { // not stable, as no button pressed
            akb_but_stab = 0; // reset stability counter
            if(!akb_is_idle)
            {
                time_buffer = millis() - AKB_IDLE_TIMEOUT; 
                if(akb_last_press < time_buffer) // check if its time for idle
                {
                    akb_idle();
                    akb_is_idle = 1;
                }                

                time_buffer = millis() - AKB_SHORT_DELAY;
                if(akb_last_press < time_buffer) // check if its time for auto commit
                {
                    akb_but_preessed = 0;
                    //akb_but_old = 0;
                    if((akb_char_this != 0x00) || (ch_secondary != 0x00)) // if has char to commit
                    {
                        akb_event_commit(INPUT_BROKER_ANYKEY); // commit text
                        akb_is_shift = 0; // reset shift
                    }
                }  
            }            
        }

    }
    else
    { // some button is registered
        if ((akb_but_this == 0) && (akb_but_this == akb_but_prev)) // check if no button is stable
        {
            akb_but_stab = akb_but_stab + 1; // count stable read
            if ( 
                ((akb_is_idle) && (akb_but_stab >= AKB_SC_IDLE)) 
                || 
                ((!akb_is_idle) && (akb_but_stab >= AKB_SC_ACTIVE))
            )
            {  // stability level reached, processing release
                
                if(!akb_hold_is_done) // if hold was not triggered
                {
                    time_buffer = millis() - AKB_LONG_DELAY;
                    if (akb_last_press < time_buffer) // check if it was regular hold
                    {
                        akb_btn_hold(akb_but_preessed);
                        // no need to set akb_hold_is_done
                    }
                    else
                    {
                        akb_btn_release(akb_but_preessed);
                    }
                }

                akb_but_old = akb_but_preessed;
                akb_but_preessed = 0;               
                // reset 
                akb_hold_is_done = 0;
                akb_but_stab = 0;
                akb_but_max = 0;
            }
        }
        else
        { // button still pressed to check for stability
            akb_but_stab = 0; // reset stability counter and values
            if (!akb_hold_is_done) // if hold was not triggered yet
            {
                time_buffer = millis() - AKB_LONGER_DELAY; 
                if(akb_last_press < time_buffer){ // check if its time for long hold
                    akb_btn_hold(akb_but_preessed); 
                    akb_hold_is_done = 1;
                }
            }            
        }
    }      
    
    // update buffer
    akb_but_prev = akb_but_this;
}

// events

void AnalogKeyboard::akb_idle()
{
    if(!akb_is_mute) playBoop();

    LOG_DEBUG("analog keyboard idle");     
};

void AnalogKeyboard::akb_wakeup(int8_t but_id)
{
    if ((!akb_is_locked) || (but_id == AKB_BUT_LOCK)){
            if(!akb_is_mute) playBeep();
    }
    
    LOG_DEBUG("analog keyboard active");
};

void AnalogKeyboard::akb_btn_push(int8_t but_id)
{
    uint32_t time_buffer;

    if(!akb_is_locked)
    {
        if (akb_events[but_id] == INPUT_BROKER_ANYKEY) 
        { // digital input here           
            if(!akb_is_mute) playClick();

            time_buffer = millis() - AKB_SHORT_DELAY;

            switch (but_id) {
            case AKB_BUT_BACK:
                akb_event_commit(INPUT_BROKER_BACK);
                break; 
            //case AKB_BUT_LOCK:
            // same button as back in this variant so no different action
            //    break; 
            case AKB_BUT_SHIFT:
                if(akb_char_this != 0x00) // if has char to commit
                    akb_event_commit(INPUT_BROKER_ANYKEY); // dont reset shift here cause goal is to increment it 
                akb_is_shift = !akb_is_shift;
                akb_event_commit(INPUT_BROKER_NONE);
                break;
            default:
                if((but_id == akb_but_old) && (akb_last_press >= time_buffer))
                { // multiclick same button
                    // increment letter
                    akb_letter_this = akb_letter_this + 1;
                    if (akb_letter_this > 5)
                        akb_letter_this = 0;
                    akb_char_this = akb_get_char(but_id);
                }
                else
                { // different button or discrete click
                    if((akb_char_this != 0x00) || (ch_secondary != 0x00)) // if has char to commit
                        akb_event_commit(INPUT_BROKER_ANYKEY);                 
                    akb_letter_this = 0; // start from first letter
                    akb_char_this = akb_get_char(but_id);
                }
                akb_event_notify();
                break;
            }
        }
        // navigation buttons processed on release
    }
    else
    {
        if (but_id != AKB_BUT_LOCK)
        {
            if(!akb_is_mute) playComboTune();
        }
        else  
        {
            if(!akb_is_mute) playClick();
        }
        // TODO: do something for gui to show keyoard is locked

        LOG_DEBUG("hold unlock button to unlock");
    }
    
    LOG_DEBUG("""%d"" key pressed", but_id);     
}

void AnalogKeyboard::akb_btn_hold(int8_t but_id)
{
    uint32_t time_buffer;

    if(!akb_is_locked)
    {
        time_buffer = millis() - AKB_LONGER_DELAY;
        if(akb_last_press < time_buffer) // check what delay it was
        { // longer delay
            switch (but_id) {
            case AKB_BUT_PING:
                if(!akb_is_mute) play4ClickDown();
                akb_event_commit(INPUT_BROKER_SEND_PING);
                break;
            case AKB_BUT_SHUTDOWN:
                akb_event_commit(INPUT_BROKER_SHUTDOWN);
                break;  
            case AKB_BUT_LOCK:
                if(!akb_is_mute) playComboTune();
                akb_is_locked = 1;
                akb_event_commit(INPUT_BROKER_NONE);
                LOG_DEBUG("analog keyboard locked");
                break; 
            case AKB_BUT_SHIFT:
                if(!akb_is_mute) playBoop();
                akb_switch_lang();
                akb_event_commit(INPUT_BROKER_NONE);
                break;
            case AKB_BUT_TAB:
                if(!akb_is_mute) playBoop();
                akb_event_commit(INPUT_BROKER_UP_LONG);
                break;
            case AKB_BUT_EMO:
                if(!akb_is_mute) playBoop();
                akb_event_commit(INPUT_BROKER_DOWN_LONG);
                break;
            default:
                // nothing     
                break;
            }
        } 
        else
        { // regular delay            
            if (but_id == AKB_BUT_SHIFT){
                if(!akb_is_mute) playBoop();
                akb_switch_lang();
                akb_event_commit(INPUT_BROKER_NONE);
            }
        }        
    }
    else
    { // alternate functions when locked
        time_buffer = millis() - AKB_LONGER_DELAY;
        if(akb_last_press < time_buffer) // longest delay only 
        { // longer delay
            switch (but_id) {
            case AKB_BUT_PING: // ping without unlocking
                akb_event_commit(INPUT_BROKER_SEND_PING);
                break; 
            case AKB_BUT_LOCK:
                if(!akb_is_mute) play4ClickUp();
                akb_is_locked = 0;
                akb_event_commit(INPUT_BROKER_NONE);
                LOG_DEBUG("analog keyboard unlocked");
                break; 
            default:
                // nothing     
                break;
            }
        } 
    }
    
    LOG_DEBUG("""%d"" key held", but_id);     
}

void AnalogKeyboard::akb_btn_release(int8_t but_id)
{
    if(!akb_is_locked)
    {
        if (akb_events[but_id] != INPUT_BROKER_ANYKEY)
        {  // any not-digit primary function
            akb_event_commit(akb_events[but_id]);
        }
    }    
       
    LOG_DEBUG("""%d"" key released", but_id);
}

void AnalogKeyboard::akb_update_state()
{
    report_states[3] = akb_is_locked;
    report_states[4] = akb_is_idle;
    report_states[5] = akb_is_shift;
    uint8_t r=0;
    for (uint8_t i=0; i<6; i=i+1)
    {
        if(akb_lang_this == 0)
        {
            if(let_map[akb_is_shift][let_id[akb_but_old]][i] != 0x00)
            {
                report_states[r+6] = let_map[akb_is_shift][let_id[akb_but_old]][i];
                r=r+1;
            }
        }
        else
        {
            if(let_map_extra[akb_lang_this-1][akb_is_shift][let_id[akb_but_old]][i][0] != 0x00)
            {
                report_states[r+6] = let_map_extra[akb_lang_this-1][akb_is_shift][let_id[akb_but_old]][i][0];
                r=r+1;
            }
            if(let_map_extra[akb_lang_this-1][akb_is_shift][let_id[akb_but_old]][i][1] != 0x00)
            {
                report_states[r+6] = let_map_extra[akb_lang_this-1][akb_is_shift][let_id[akb_but_old]][i][1];
                r=r+1;
            }
        }
    }
    for (uint8_t i=r; i<12; i=i+1)
    {
        report_states[i+6] = 0x00;
    }
    
    report_states[18] = akb_lang_this;
    report_states[19] = lang_names[akb_lang_this][0];
    report_states[20] = lang_names[akb_lang_this][1]; 
};

void AnalogKeyboard::akb_event_commit(input_broker_event event){
    InputEvent e = {};
    e.inputEvent = event;
    // substitute pointer for char array with states
    akb_update_state();
    e.source = &report_states[0];
    //e.source = this->_originName;

    if(e.inputEvent == INPUT_BROKER_BACK)
    {
        e.kbchar = 0x08;
    }
    else if(e.inputEvent == INPUT_BROKER_ANYKEY)
    {
        e.kbchar = akb_char_this;
    }    

    akb_char_this = 0x00; // reset pendint text 

    this->notifyObservers(&e);

    if (ch_secondary != 0x00)
    { // if 2-byte char
        InputEvent e2 = {};
        e2.inputEvent = INPUT_BROKER_ANYKEY;
        e2.source = &report_states[0];
        //e2.source = this->_originName;
        e2.kbchar = ch_secondary;
        ch_secondary = 0x00;// reset pendint text no matter what event this was
        this->notifyObservers(&e2);
    }

    LOG_DEBUG("commit: %d", event);
}

void AnalogKeyboard::akb_event_notify(){
    InputEvent e = {};
    e.inputEvent = INPUT_BROKER_NONE;
    akb_update_state();
    e.source = &report_states[0];
    this->notifyObservers(&e);

    LOG_DEBUG("akb notify");
}

void AnalogKeyboard::akb_switch_lang()
{
    uint8_t max_lang = sizeof(lang_names)/sizeof(lang_names[0]) - 1;
    if (akb_lang_this < max_lang)
    {
        akb_lang_this = akb_lang_this + 1;
    }
    else
    {
        akb_lang_this = 0;
    }
    
    akb_is_shift = 0;

    LOG_DEBUG("input lang: ""%s""", lang_names[akb_lang_this]);
}


unsigned char AnalogKeyboard::akb_get_char(uint8_t ch_but)
{
    unsigned char ch_priamry = 0x00;

    if (akb_lang_this == 0)
    { // EN
         ch_priamry = let_map[akb_is_shift][let_id[ch_but]][akb_letter_this];
         if (ch_priamry == 0x00)
         {
            akb_letter_this = 0;
            ch_priamry = let_map[akb_is_shift][let_id[ch_but]][akb_letter_this];
         }
         // if still 0 its not our problem
         ch_secondary = 0x00; 
    }
    else
    { // 2-byte chars...
        //[lang][shift][button][char][byte]
        ch_secondary = let_map_extra[akb_lang_this-1][akb_is_shift][let_id[ch_but]][akb_letter_this][1];
        if (ch_secondary == 0x00)
        {
            akb_letter_this = 0;
            ch_secondary = let_map_extra[akb_lang_this-1][akb_is_shift][let_id[ch_but]][akb_letter_this][1];
        }
        ch_priamry = let_map_extra[akb_lang_this-1][akb_is_shift][let_id[ch_but]][akb_letter_this][0];
    }
 
    return ch_priamry;
}

// main subs

int32_t AnalogKeyboard::runOnce()
{        
    if (!akb_first_run)
    {
        akb_adc_read();
        akb_evaluate();
    }
    else
    {
        // This is the first time the OSThread library has called this function, so do port setup
        if (!INPUTBROKER_ANALOG_TYPE)
        {
            // Input device is not requested.
            return disable();
        }
        akb_setup();
        akb_first_run = 0; 
    }
    
    if (akb_is_idle){
        return AKB_DT_IDLE;
    }else{
        return AKB_DT_ACTIVE;
    }
}

AnalogKeyboard::AnalogKeyboard(const char *name) : concurrency::OSThread(name)
{
    this->_originName = name;

    globalAnalogKeyboard = this;
}


#endif // INPUTBROKER_ANALOG_TYPE