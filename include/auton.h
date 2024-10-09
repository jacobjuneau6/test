ASSET (blue_right_txt);
ASSET (blue_left_txt);
ASSET (red_right_txt);
ASSET (red_left_txt);
void auton(){
int auton = 1;
pneumatics_up();
if (auton == 1) {
	chassis.setPose(-58, -47,90);
	chassis.follow(red_right_txt,38,1000,false,false);
} else if (auton == 2)
{
	chassis.setPose(58,47,0);
	chassis.follow(blue_right_txt,38,1000,false,false);
} else if (auton == 3) {
	chassis.setPose(58,-46,0);
	chassis.follow(blue_left_txt,38,1000,false,false);
} else if (auton == 4) {
	chassis.setPose(-58,46,0);
	chassis.follow(red_left_txt,38,1000,false,false);
}
pros::delay(1000);
pneumatics_down();
intakeon();
}