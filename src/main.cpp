#include "define.h"
int seli;
#include "main.h"
//#include "autoSelect/selection.h"
#include "lemlib/api.hpp" 
#include "pros/apix.h"
//#include "setup.h"
#include "auton.h"

//int seli;
//#include "match.h"
void matchf()
{
    LV_IMG_DECLARE(vexb);
    lv_obj_t * ma = lv_img_create(lv_scr_act());
    lv_img_set_src(ma, &vexb);
	lv_obj_set_pos(ma,95,0);
//	lv_img_set_angle(ma, 900);
   // lv_obj_align(ma, LV_ALIGN_CENTER, 0, 0);
  //  lv_obj_set_size(img1, 200, 200);

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	chassis.calibrate();
	chassis.calibrate(true);
lv_example_get_started_3();
lv_example_img_1();
//auton();


//	pros::lcd::register_btn1_cb(red_right());
//	pros::lcd::register_btn2_cb(blue_right());
//	autonomous();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
/*ASSET (blue_right_txt);
ASSET (blue_left_txt);
ASSET (red_right_txt);
ASSET (red_right_finish_txt);
ASSET (red_left_txt);*/
void autonomous() {
auton();

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
//	autonomous();
//matchf();
while (true){
	if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
      pneumatics_down();
	}
	if (master.get_digital(E_CONTROLLER_DIGITAL_R1)) {
      pneumatics_up();
    }
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      intakeon();
    }
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      intakeoff();
    }
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      off();
    }
	int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    chassis.tank(leftY, rightY);
    pros::delay(25);
}
}