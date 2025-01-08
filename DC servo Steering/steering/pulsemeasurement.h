#ifndef PULSEMEASUREMENT
#define PULSEMEASUREMENT

#include <Arduino.h>
class PulseMeasurement {
private:
    int pulsePin;               // Pin to read PWM signal
    volatile unsigned long pulsePeriod; // Measured pulse width
    volatile bool done;         // Indicates if measurement is complete
    unsigned long start;        // Start time of the pulse

public:
    // Constructor
    PulseMeasurement(int pulsePin);

    // Initialize the pin
    void init();

    // Interrupt service routine for measurement
    void measure();

    // Get the measured pulse period
    unsigned long getPulsePeriod() const;

    // Check if measurement is done
    bool isDone() const;

    // Reset the `done` flag
    void resetDoneFlag();
};

#endif