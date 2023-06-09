// Leaphymurphy.h
// suitable for Fundumoto Shield
// Copyright Stichting Leaphy 2023
// version 1.0.0    17 April 2023
#ifndef LEAPHYORIGINAL1_H_
#define LEAPHYORIGINAL1_H_

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "wiring_private.h"
#ifndef F_CPU
#define  F_CPU 16000000UL
#endif
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>

#define MOTOR_LEFT      (3)     // M1
#define MOTOR_RIGHT     (11)    // M2
#define TRUE            (1)
#define FALSE           (0)
#define FORWARD         (1)
#define BACKWARD        (2)
#define LEFT            (3)
#define RIGHT           (4)

// PIN definitions for Fundumoto L298P motor shield with built in buzzer
#define M1_PWM          (3)    // Motor A PWM
#define M1_DIR          (2)  // Motor A direction
#define M2_PWM          (11)    // Motor B PWM
#define M2_DIR          (4)    // Motor B direction
#define TONE_PIN        (4)     // DIG-OUT
#define LED1_RED        (6)     // PWM-OUT
#define LED1_GREEN      (5)     // PWM-OUT
#define LED1_BLUE       (3)     // PWM-OUT
#define LINE_LEFT       (16)    // DIG-IN       A2 tinkerkit In2
#define LINE_RIGHT      (17)    // DIG-IN       A3 tinkerkit In3
#define US_ECHO         (8)     // DIG-IN/OUT
#define US_TRIG         (7)     // DIG-OUT

float getDistance(void);
int getLineFollower(int fpSide);
void setTone( int fpTone, int fpBeat);
void setMotor(int fpMotor, int fpSpeed);
void moveMotors(int fpDirection, int fpSpeed);
void setLed(int fpRed, int fpGreen, int fpBlue);

#endif
