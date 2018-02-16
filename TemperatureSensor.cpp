#include "TemperatureSensor.h"
#include <Arduino.h>


TemperatureSensor::TemperatureSensor(int pin)
: pin_(pin)
, temperature_(-273.15)
{

}

void TemperatureSensor::setup()
{
    pinMode(pin_, INPUT);
}

void TemperatureSensor::run()
{
    int analogvalue = analogRead(pin_);
    temperature_ = ((analogvalue * 5.0 / 1024.0) - 0.5) * 100.0;
}

float TemperatureSensor::temperature()
{
    return temperature_;
}

