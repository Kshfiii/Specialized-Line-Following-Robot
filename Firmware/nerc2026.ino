#include <Arduino.h>
#include "config.h"
#include "drive.h"
#include "sensors.h"
#include "lift.h"
#include "nav.h"
#include "sm.h"

void setup() {
    Serial.begin(115200);

    pinMode(START_BTN, INPUT_PULLUP);
    pinMode(STATUS_LED, OUTPUT);
    digitalWrite(STATUS_LED, HIGH);

    driveInit();
    liftInit();
    sensorsInit();
    colorInit();
    navInit();
    smInit();

    while (digitalRead(START_BTN) == HIGH) delay(10);
    delay(150);

    digitalWrite(STATUS_LED, LOW);
    smStart();
}

void loop() {
    smTick();
    delay(5);
}
