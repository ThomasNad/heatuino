#include <OneButton.h>
#include "TemperatureSensor.h"
#include "OnOffDevice.h"
#include "HeatingMode.h"
#include "HeatingControl.h"


int PIN_themperatureSensor = A0;
int PIN_ModeButton = 0;
int PIN_Heating = 6;

OneButton modeButton(PIN_ModeButton, false);
OnOffDevice heating(PIN_Heating);
TemperatureSensor tempSensor(PIN_themperatureSensor);
HeatingMode mode;
HeatingControl heatingControl(heating, tempSensor, mode);


void modeChanged_clicked()
{
    mode.onHeatingModeChanged();
}

void setup()
{
    pinMode(PIN_ModeButton, INPUT);
    modeButton.attachClick(modeChanged_clicked);

    heating.setup();
    heatingControl.setup();
    tempSensor.setup();
}

void loop()
{
    modeButton.tick();
    mode.run();
    tempSensor.run();
    heatingControl.run();
}
