#ifndef __HeatingControlButton_h
#define __HeatingControlButton_h

class IHeatingModeChangedListener;
class OneButton;

class HeatingControlButton
{
public:
    HeatingControlButton(int pin);

    void setup();
    void run();

    void addListener(IHeatingModeChangedListener& listener);


private:
    int pin_;
    OneButton& button_;
};

#endif