#include "HeatingMode.h"
#include <Arduino.h>


HeatingMode::HeatingMode()
{
    resetModeChangedStartTime();
}

void HeatingMode::run()
{
    if (mode_ != nextMode_ && millis() - modeChangedStartTime_ > modeChangedDelay_)
    {
        mode_ = nextMode_;
    }
}

void HeatingMode::onHeatingModeChanged()
{
    nextMode_ = ((mode_) + 1) % 3;
    resetModeChangedStartTime();
}

HeatingModeType HeatingMode::getMode()
{
    return mode_;
}

void HeatingMode::resetModeChangedStartTime()
{
    modeChangedStartTime_ = millis();
}
