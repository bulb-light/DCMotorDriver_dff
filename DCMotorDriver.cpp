// SPDX-FileCopyrightText: 2025 David Chirme Sisa ([dff-laoise](https://github.com/bulb-light)) 
// SPDX-License-Identifier: MIT
// For full license text, see the LICENSE file in the repository root or https://opensource.org/licenses/MIT

/**
 * @file DCMotorDriver.cpp
 * @brief Implementation of the DCMotorDriver class.
 * 
 * This file contains the implementation of the DCMotorDriver class, which provides methods
 * to control a DC motor using motor drivers such as the L298N. The class supports motor
 * initialization, direction control, speed control, and stopping the motor.
 */

#include "DCMotorDriver.h"

DCMotorDriver::DCMotorDriver(uint8_t pin1, uint8_t pin2, uint8_t pwmPin)
{
    this->mPin1 = pin1;
    this->mPin2 = pin2;
    this->mPwmPin = pwmPin;
}

DCMotorDriver::~DCMotorDriver()
{
}

void DCMotorDriver::motorInit()
{
    pinMode(this->mPin1, OUTPUT);
    pinMode(this->mPin2, OUTPUT);
    pinMode(this->mPwmPin, OUTPUT);
}

void DCMotorDriver::moveMotor(bool pin1State, bool pin2State, uint8_t pwm)
{
    analogWrite(this->mPwmPin, pwm);
    digitalWrite(this->mPin1, pin1State);
    digitalWrite(this->mPin2, pin2State);
}

void DCMotorDriver::stop()
{
    // stop motor
    moveMotor(LOW, LOW, 0);
}
