  
#ifndef INIT_H
#define INIT_H
#include <Arduino.h>

// MotorDriver pins
#define PWM_INPUT_PIN 3 // PWM input pin

//left motor
#define MOTOR_LEFT_PWM 5 // PWM output  pin
#define MOTOR_LEFT_DIR 4 // Mototr direction
#define ADC_LEFT A0
#define POT_MIN_LEFT 800
#define POT_MAX_LEFT 2200

//right motor
#define MOTOR_RIGHT_PWM 6 // PWM output  pin
#define MOTOR_RIGHT_DIR 7 // Mototr direction
#define ADC_RIGHT A1
#define POT_MIN_RIGHT 800
#define POT_MAX_RIGHT 2200



#endif