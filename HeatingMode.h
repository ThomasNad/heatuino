#ifndef __HeatingMode_h
#define __HeatingMode_h

#include "IHeatingModeChangedListener.h"

enum HeatingModeType
{
    off,
    on,
    automatic
};


class HeatingMode : public IHeatingModeChangedListener
{
public:
    HeatingMode();

    void run();
    void onHeatingModeChanged();
    HeatingModeType getMode();

private:
    HeatingModeType mode_ {HeatingModeType::off};
    HeatingModeType nextMode_ {HeatingModeType::off};

    unsigned long modeChangedStartTime_;
    int modeChangedDelay_  {5000};

    void resetModeChangedStartTime();
};


#endif