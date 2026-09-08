#include "AnalogKeyboardImpl.h"
#include "InputBroker.h"
#include "configuration.h"

#ifdef INPUTBROKER_ANALOG_TYPE

AnalogKeyboardImpl *aAnalogKeyboardImpl;

AnalogKeyboardImpl::AnalogKeyboardImpl() : AnalogKeyboard("analogKB") {}

void AnalogKeyboardImpl::init()
{
    if (!INPUTBROKER_ANALOG_TYPE) {
        disable();
        return;
    }

    inputBroker->registerSource(this);
}

#endif // INPUTBROKER_ANALOG_TYPE