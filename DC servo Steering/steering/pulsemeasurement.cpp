#include "PulseMeasurement.h"
#include "init.h"
#include <Arduino.h>

PulseMeasurement::PulseMeasurement(int pulsePin)
    : pulsePin(pulsePin), pulsePeriod(0), done(false), start(0) {}

void PulseMeasurement::init() {
    pinMode(pulsePin, INPUT);
}

void PulseMeasurement::measure() {
    if (digitalRead(pulsePin) == HIGH) {
        start = micros();
    } else {
        pulsePeriod = micros() - start;
        done = true;
    }
}

unsigned long PulseMeasurement::getPulsePeriod() const {
    return pulsePeriod;
}

bool PulseMeasurement::isDone() const {
    return done;
}

void PulseMeasurement::resetDoneFlag() {
     done = false;
}