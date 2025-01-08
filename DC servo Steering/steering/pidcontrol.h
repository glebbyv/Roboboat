#ifndef PIDCONTROL_H
#define PIDCONTROL_H
#include <Arduino.h>
class PIDController {
public:
    double Kp, Ki, Kd;          // PID constants
    double setpoint, input, output; // Control variables
    double error, lasterror, integral, derivative; // PID terms

    // Constructor
    PIDController(double Kp, double Ki, double Kd);

    // Method to compute PID
    void compute();
};

#endif