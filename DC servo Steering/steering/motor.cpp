#include "motor.h"


Motor::Motor(int adcPin, int pwmPin, int dirPin,int pot_min,int pot_max, double Kp, double Ki, double Kd,PulseMeasurement* pulse)
    : adcPin(adcPin), pwmPin(pwmPin), dirPin(dirPin), input_shaft_position(0), setpoint(0), output(0), pot_min(pot_min), pot_max(pot_max),
      pid(Kp, Ki, Kd), pulse(pulse), filter(0.215) {}

void Motor::init() {
    pinMode(pwmPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(adcPin, INPUT);
}

void Motor::update() {

    int filtered_adc = static_cast<int>(filter.filter(analogRead(adcPin)) + 0.5f);


    // Read ADC value and map to 1000–2000
    input_shaft_position = map(filtered_adc, pot_min, pot_max, 1000, 2000); // Reading shaft ADC value and mapping it into 1000-2000 ms

    // Get the setpoint from the PulseMeasurement
    if (pulse->isDone()) {
        setpoint = pulse->getPulsePeriod(); // updating width of input pwm signal
    }

    // Set PID parameters
    pid.input = input_shaft_position; // actual shaft position
    pid.setpoint = setpoint;          // desired shaft posiiton

    // Compute PID output
    pid.compute();

    // Apply the PID output to the motor
    output = constrain(pid.output, -255, 255);  //

    // Set motor direction and PWM
    if (output >= 0) {                 // if output "+" rotate in one direction
        digitalWrite(dirPin, HIGH);    // set direction
        analogWrite(pwmPin, output);   // set duty-cycle
    } else {                           // else rotate in the other direction
        digitalWrite(dirPin, LOW);     // set direction
        analogWrite(pwmPin, -output);  // set duty-cycle
    }                                  // if output=0 => error = 0 => do nothing

    Serial.print(filtered_adc);
    Serial.print(" ");
    Serial.println(analogRead(adcPin));

    pulse->resetDoneFlag();
}