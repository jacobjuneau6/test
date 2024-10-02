#include "main.h"
#include "lemlib/api.hpp" 
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	autonomous();
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
ASSET (path2_txt);
void autonomous() {
chassis.setPose(-160, 160,0);
//chassis.follow(path2_txt); //This tells the robot to folow the imported path from Jerryio.com
//chassis.moveToPose(-63.08, -11.987, 0, 4);
//chassis.moveTo(-23.456, -23.536, 5000);
//chassis.moveTo(-47.151, -47.43, 5000);

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
while (true){
	//	left_motors.move(master.get_analog(ANALOG_LEFT_Y));
//		right_motors.move(master.get_analog(ANALOG_RIGHT_Y));
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

        // move the robot
        chassis.tank(leftY, rightY);

        // delay to save resources
        pros::delay(25);


}
}