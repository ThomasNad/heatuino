#include "OnOffDevice.h"
#include <Arduino.h>


OnOffDevice::OnOffDevice(int pin)
: isOn_(false)
, pin_(pin)
{

}

void OnOffDevice::setup()
{
    pinMode(pin_, OUTPUT);
}

void OnOffDevice::on()
{
    if (!isOn_)
    {
        digitalWrite(pin_, HIGH);
        isOn_ = true;
    }
}

void OnOffDevice::off()
{
    if (isOn_)
    {
        digitalWrite(pin_, LOW);
        isOn_ = false;
    }
}