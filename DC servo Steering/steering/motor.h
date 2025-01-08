#ifndef MOTOR_H
#define MOTOR_H

#include "pidcontrol.h"
#include "init.h"
#include "pulsemeasurement.h"
#include <Arduino.h>
#include "mafilter.h"

class Motor {
private:
    int adcPin;                   // input for reading position of the shaft's POT
    int pwmPin;                   // PWM output pin/ duty cycle pin
    int dirPin;                   // Direction control pin
    double input_shaft_position;  // Current ADC input value
    double setpoint;              // Desired motor setpoint
    double output;                // PID output (duty cycle) value
    int pot_min, pot_max;         // extreme positions of the shaft's POT

    PIDController pid;                      // PID controller
    PulseMeasurement* pulse;       // Pulse measurement instance

    Filter filter;

public:
    // Constructor
    Motor(int adcPin, int pwmPin, int dirPin,int pot_min, int pot_max, double Kp, double Ki, double Kd, PulseMeasurement* pulse);

    // Initialize motor pins and components
    void init();

    // Update motor control logic
    void update();
};
#endif // MOTOR_H