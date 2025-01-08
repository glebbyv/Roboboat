#include <Arduino.h>
#include "init.h"
#include "motor.h"
#include "pulsemeasurement.h"

PulseMeasurement pulseMeasure(PWM_INPUT_PIN);

Motor motor_left(ADC_LEFT, MOTOR_LEFT_PWM, MOTOR_LEFT_DIR,POT_MIN_LEFT,POT_MAX_LEFT, 5.0, 2.49, 0.15,&pulseMeasure);
Motor motor_right(ADC_RIGHT, MOTOR_RIGHT_PWM, MOTOR_RIGHT_DIR,POT_MIN_RIGHT,POT_MAX_RIGHT, 5.0, 2.49, 0.15,&pulseMeasure);


void setup() {
    initial();
    pulseMeasure.init();
    motor_left.init();
    motor_right.init();
    attachInterrupt(digitalPinToInterrupt(PWM_INPUT_PIN), []() { pulseMeasure.measure(); }, CHANGE);
}

void loop() {
    motor_left.update();
    motor_right.update();

    delay(100);
}