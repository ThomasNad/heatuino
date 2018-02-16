#ifndef __HeatingControl_h
#define __HeatingControl_h


class OnOffDevice;
class TemperatureSensor;
class HeatingMode;

class HeatingControl
{
public:
    HeatingControl(OnOffDevice& heating, TemperatureSensor& temperaturSensor, HeatingMode& mode);
    void setup();
    void run();


private:
    OnOffDevice& heating_;
    TemperatureSensor& temperaturSensor_;
    HeatingMode& mode_;

    float lowerTemperatureLimit_ {8};
    float upperTemperatureLimit_ {15};

    void runAutomatic();
};

#endif