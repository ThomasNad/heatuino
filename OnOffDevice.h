#ifndef __OnOffDevice_h
#define __OnOffDevice_h

class OnOffDevice
{
public:
    OnOffDevice(int pin);

    void setup();
    void on();
    void off();


private:
    bool isOn_;
    int pin_;
};

#endif