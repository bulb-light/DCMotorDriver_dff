// SPDX-FileCopyrightText: 2025 David Chirme Sisa ([dff-laoise](https://github.com/bulb-light)) 
// SPDX-License-Identifier: MIT
// For full license text, see the LICENSE file in the repository root or https://opensource.org/licenses/MIT

/**
 * @file DCMotorDriver.h
 * @brief Header file for the DCMotorDriver class.
 * 
 * This file contains the declaration of the DCMotorDriver class, which provides methods
 * to control a DC motor with an armature circuit using an Arduino or ESP32. The class
 * allows for motor initialization, direction control, speed control, and stopping the motor.
 * 
 * @note This library is specifically designed to work with three-pin motor drivers
 *  such as the L298N, but can be extended to other drivers.
 */

#ifndef __DCMOTORDRIVER_H__
#define __DCMOTORDRIVER_H__

#include <Arduino.h>

/**
 * @class DCMotorDriver
 * @brief A class to control a DC motor with an armature circuit using an Arduino or ESP32.
 * 
 * This class provides methods to initialize the motor, control its direction and speed,
 * and stop it. It uses two control pins and one PWM pin to operate the motor.
 * 
 * Example usage:
 * @code
 * DCMotorDriver myMotor(IN1, IN2, ENA); // IN1, IN2, ENA driver control pins
 * myMotor.motorInit(); // Initialize motor pins
 * myMotor.moveMotor(HIGH, LOW, 200); // Move forward with PWM 200
 * @endcode
 * 
 * @note This library is specifically designed to work with motor drivers such as the L298N.
 */
class DCMotorDriver {
    private:
        uint8_t mPin1;   ///< The first control pin for the motor.
        uint8_t mPin2;   ///< The second control pin for the motor.
        uint8_t mPwmPin; ///< The PWM pin for controlling motor speed.

    public:
        /**
         * @brief Construct a new DCMotor object.
         * 
         * @param pin1 The first control pin for the motor.
         * @param pin2 The second control pin for the motor.
         * @param pwmPin The PWM pin for controlling motor speed.
         */
        DCMotorDriver(uint8_t pin1, uint8_t pin2, uint8_t pwmPin);

        /**
         * @brief Destroy the DCMotor object.
         */
        ~DCMotorDriver();

        /**
         * @brief Initialize the motor pins as output.
         * 
         * This method configures the control pins and the PWM pin as output pins.
         */
        void motorInit();

        /**
         * @brief Move the motor by setting the control pins and PWM value.
         * 
         * @param pin1State The state of the first control pin (HIGH or LOW).
         * @param pin2State The state of the second control pin (HIGH or LOW).
         * @param pwm The PWM value (0-255) to control motor speed.
         */
        void moveMotor(bool pin1State, bool pin2State, uint8_t pwm);

        /**
         * @brief Stop the motor by setting both control pins to LOW and PWM to 0.
         */
        void stop();
};

#endif