#ifndef __TemperatureSensor_h
#define __TemperatureSensor_h

class TemperatureSensor
{
public:
    TemperatureSensor(int pin);

    void setup();
    void run();
    float temperature();


private:
    int pin_;
    float temperature_;
};

#endif