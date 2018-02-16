#ifndef __IHeatingModeChangedListener_h
#define __IHeatingModeChangedListener_h

class IHeatingModeChangedListener
{
public:
    virtual ~IHeatingModeChangedListener() { }
    virtual void onHeatingModeChanged() = 0;
};

#endif