#include "HeatingControl.h"
#include "OnOffDevice.h"
#include "HeatingMode.h"
#include "TemperatureSensor.h"


HeatingControl::HeatingControl(
    OnOffDevice& heating, 
    TemperatureSensor& temperaturSensor,
    HeatingMode& mode)
: heating_(heating)
, temperaturSensor_(temperaturSensor)
, mode_(mode)
{
}

void HeatingControl::setup()
{
}

void HeatingControl::run()
{
    switch (mode_.getMode())
    {
    case HeatingModeType::automatic:
        runAutomatic();
        return;
    case HeatingModeType::on:
        heating_.on();
        return;
    default:
        heating_.off();
        return;
    }
}

void HeatingControl::runAutomatic()
{
    if (temperaturSensor_.temperature() < lowerTemperatureLimit_)
    {
        heating_.on();
    }
    else if (temperaturSensor_.temperature() > upperTemperatureLimit_)
    {
        heating_.off();
    }
}
