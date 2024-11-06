/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
//#include "auton.h"
/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS
#include "pros/apix.h"
#include "api.h"
#include "lemlib/api.hpp" 
/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
 using namespace pros;
 using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
//config
//pros::Gps gps(13);
pros::Controller master (E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({LEFT1, LEFT2, LEFT3}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({RIGHT1, RIGHT2, RIGHT3}, pros::MotorGearset::blue);
lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                            &right_motors, // right motor group
                            12.84 , // 10 inch track width
                            lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                            601.25,
                            2
);
pros::Imu imu(IMUPORT);
pros::adi::Encoder vertical_encoder(CONNECT1, CONNECT2);
lemlib::TrackingWheel horizontal_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, 1);
pros::Rotation rotation_sensor(VERTICLE);
lemlib::TrackingWheel vertical_tracking_wheel(&rotation_sensor, lemlib::Omniwheel::NEW_275, 1);
lemlib::OdomSensors sensors(
                            &vertical_tracking_wheel,
                            nullptr,
                            &horizontal_tracking_wheel,
                            nullptr,
                            &imu
);
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              0.5, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              0.5, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);
//other devs
pros::adi::DigitalOut sensor (CLAMP, true);
void pneumatics_down(){
  sensor.set_value(false);
}
void pneumatics_up(){
  sensor.set_value(true);
}
pros::Motor intake (INTAKE, pros::v5::MotorGears::blue);
pros::Motor pull (CONVEYOR, pros::v5::MotorGears::green);
void off(){
  pull.brake();
    intake.brake();
}
 void intakeon(){
  intake.move_velocity(200);
  intake.move(127);
  pull.move_velocity(900);
  pull.move(127);
 } 
 void intakeoff(){
  intake.move_velocity(0);
  pull.move(-127);
}
Distance clamp(DISTANCE);
