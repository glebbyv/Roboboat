#include "PIDControl.h"
#include <Arduino.h>
#include "pulsemeasurement.h"
#include "init.h"

#include "pidcontrol.h"

PIDController::PIDController(double Kp, double Ki, double Kd)
    : Kp(Kp), Ki(Ki), Kd(Kd), setpoint(0), input(0), output(0),
      error(0), lasterror(0), integral(0), derivative(0) {}

void PIDController::compute() {
    error = setpoint - input;
    integral += error;
    derivative = error - lasterror;
    output = Kp * error + Ki * integral + Kd * derivative;
    lasterror = error;
}
