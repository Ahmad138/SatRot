/*****************************************************************************
**  File name: a4988Driver.h
**  Description: a4988 driver Class to control stepper motor
**  Notes:
**  Author(s): Ahmad, Muhammad
**  Created: 12-02-2020
**  Last Modified: 19-02-2020
**  Changes:
******************************************************************************/

#ifndef A4988DRIVER_H
#define A4988DRIVER_H

#include <iostream>
#include <stdint.h> //to use uint8_t
#include <wiringPi.h> //to control the GPIO of raspberry pi 3
#include <math.h>
#include "helper.h" //Some helper functions and variables

//Defining some constants for the controller

//define output digital levels
#define HIGH 1 //corresponds to ON
#define LOW 0 //corresponds to OFF

//Define the different stepping modes of the drivers
#define FULL_STEP 0 // 1.8 degrees per step
#define HALF_STEP 1 // 0.9 degrees per step
#define QUARTER_STEP 2 // 0.45 degrees per step
#define EIGHTH_STEP 3 // 0.225 degres per step
#define SIXTEENTH_STEP 5 // 0.1125 degrees per step

//Define constants for the directions
#define CW 1
#define CCW 0


class a4988Driver
{
   public:
    /** Constructor initialisation when creating a a4988Driver instance
     *
     *  @param enablePin -> The pin which is connected to the enable input on the stepper driver
     *  @param dirPin -> The pin connected to the dir input on the stepper driver
     *  @param stepPin -> The pin connected to the step input on the stepper driver
     *  @param ms1Pin -> The pin connected to the ms1 input on the stepper driver
     *  @param ms2Pin -> The pin connected to the ms2 input on the stepper driver
     *  @param ms3Pin -> The pin connected to the ms3 input on the stepper driver
     *
     * @note
     * 1 - All specified pins are set as OUTPUT.
     * 2 - Default settings are set to enabled -> true, mode -> FULL_STEP, direction -> clockwise, and the speed -> 50%.
     */
    a4988Driver(uint8_t enablePin, uint8_t dirPin, uint8_t stepPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin);
    virtual ~a4988Driver();
    /** Set the step mode
     *
     *  @param mode -> The mode you wish to put the stepper motor into
     *
     *  @note This mode must be a valid mode which are specified in the defines
     *  above. (0, 1, 2, 3, 5)
     */
    void setMode(uint8_t mode);

    /** Set the direction
     *
     *  @param direction -> A valid direction to set (clockwise CW or counter clockwise CCW)
     */
    void setDirection(uint8_t direction);

    /** Set the speed
     *
     *  @param speed -> The perecent speed to set. Must be between 0 and 100 inclusive
     */
    void setSpeed(uint8_t speed);

    /** Step the motor in the set direction the set amount of degrees
     *
     *  @param degrees -> A float representing how many degrees to step the motor.
     *
     *  @note The degrees to step must be a multiple of the current mode. ie. if The
     *  current mode is HALF_STEP, degrees must be a multiple of 0.9. If not, then
     *  the amount of steps will be rounded to the nearest integer. ie. If you
     *  want to step 2.0 degrees with HALF_STEP, it will only step 2 times for a total
     *  of 1.8 degrees.
     */
    void stepDegrees(float degrees);

    /** Enables the motor for use
     *
     *  @note Only necessary to call if the motor was previously disabled as the motor
     *  is enabled by default.
     */
    void enable();

    /** Disables the motor
     *
     *  @note This diables all outputs such that the motor cannot be controlled.
     *  However in this disabled state it is still possible to change things around
     *  As all the inputs and internal transalator logic remain active
     */
    void disable();

  private:
    bool _enabled;
    bool _autodisable;
    uint8_t _direction;
    uint8_t _enable;
    uint8_t _dir;
    uint8_t _step;
    uint8_t _ms1;
    uint8_t _ms2;
    uint8_t _ms3;
    uint8_t _mode;
    uint8_t _speed;

    float stepAngles[5] = { 1.8, 0.9, 0.45, 0.225, 0.1125 };

    helper h;

    void _updateDriver();
};

#endif // A4988DRIVER_H
