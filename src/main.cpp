#include "main.h"
#include "drive.cpp"
#include "drive.hpp"




//cricket

//Controller
pros:: Controller master(pros::E_CONTROLLER_MASTER);
// Drive Motors
pros::Motor driveFL(1,pros::E_MOTOR_GEAR_GREEN,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor driveFR(2,pros::E_MOTOR_GEAR_GREEN,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor driveBL(3,pros::E_MOTOR_GEAR_GREEN,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor driveBR(4,pros::E_MOTOR_GEAR_GREEN,true,pros::E_MOTOR_ENCODER_DEGREES);
//Intake
 pros::Motor intake(9,pros::E_MOTOR_GEAR_GREEN,false,pros::E_MOTOR_ENCODER_DEGREES);
// Flywheel related Motors
pros::Motor fw1(5,pros::E_MOTOR_GEAR_BLUE,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor fw2(6,pros::E_MOTOR_GEAR_BLUE,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor cam(7,pros::E_MOTOR_GEAR_GREEN,false,pros::E_MOTOR_ENCODER_DEGREES);
//Expansion
pros::ADIDigitalOut expansionR ('A', LOW);
pros::ADIDigitalOut expansionL ('B', LOW);
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	driveFL.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveFR.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveBL.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	driveBR.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	fw1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	fw2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}



/**
 * Runs aaaa after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

/* changes in the code*/



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
void auton_win () {
	fw1.move(125); 
fw2.move(125);
	fwd(120,127);
	intake.move_relative(-90,127);
	pros::delay(500);
	back(100, 127);
	pros::delay( 200);
	rotateright(50,127);
	pros::delay(500);
	cam.move_relative(360 , 127);
	pros::delay(1000);
	cam.move_relative(360 , 127);
	pros::delay(1000);
	rotateright(270,127);
	pros::delay(500);
	fwd(900,127);
	pros::delay(500);
	rotateright(150,127);
	intake.move(127);
	fwd(550,127);
	rotateleft(130,127);
	pros::delay(200);
	rotateleft(75,127);
	fwd(1500,127);
	rotateleft(180,127);
	fwd(300,127);
	pros::delay(300);
	back(200,127);
	cam.move_relative(360,127);
	pros::delay(1000);
	cam.move_relative(360,127);
	pros::delay(1000);
	cam.move_relative(360,127);
	// rotateleft(160,127);
	// pros::delay(500);
	// fwd(150,127);
	// pros::delay(200);
	// intake.move_relative(-90,127)
	


}

void mainauton () {
	fw1.move(122); 
    fw2.move(122);
	fwd(200,127);
	intake.move_relative(-90,127);
	pros::delay(1000);
	back(100, 127);
	pros::delay(200);
	rotateright(45,127);
	pros::delay(1000);
	cam.move_relative(360 , 200);
	pros::delay(1200);
	cam.move_relative(360 , 200);
	pros::delay(3000);
}
void consistentautonskills () {
	fw1.move(122); 
	fw2.move(122);
	fwd(120,127);
	intake.move_relative(-90,127);
	pros::delay(500);
	back(100, 127);
	pros::delay(200);
	rotateright(50,127);
	pros::delay(1000);
	cam.move_relative(360,200);
	pros::delay(1500);
	cam.move_relative(360,200);
	pros::delay(1000);
	rotateright(270,127);
	pros::delay(500);
	fwd(900,127);
	pros::delay(500);
	rotateright(150,127);
	intake.move(127);
	fwd(550,127);
	rotateleft(120,127);
	pros::delay(200);
	rotateleft(60,127);
	fwd(1600,110);
	rotateleft(180,127);
	fwd(300,127);
	pros::delay(200);
	back(550,127);
	rotateright(300,127);
	fwd(600,127);
	pros::delay(200);
	back(100,127);
	rotateleft(150,127);
	back(800,127);
	rotateright(30,127);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(2000);
	fwd(1500,127); 
	rotateleft(240,120);
	expansionR.set_value(false);
	expansionR.set_value(true);
	rotateleft(90,120);
	expansionL.set_value(false);
	expansionL.set_value(true);
}
void autonskills () {
	fw1.move(122); 
	fw2.move(122);
	fwd(120,127);
	intake.move_relative(-90,127);
	pros::delay(500);
	back(100, 127);
	pros::delay(200);
	rotateright(50,127);
	pros::delay(1000);
	cam.move_relative(360 , 200);
	pros::delay(1500);
	cam.move_relative(360 , 200);
	pros::delay(1000);
	rotateright(270,127);
	pros::delay(500);
	fwd(900,127);
	pros::delay(500);
	rotateright(150,127);
	intake.move(127);
	fwd(550,127);
	rotateleft(120,127);
	pros::delay(200);
	rotateleft(60,127);
	fwd(1600,110);
	rotateleft(180,127);
	fwd(300,127);
	pros::delay(200);
	back(550,127);
	rotateright(300,127);
	fwd(600,127);
	pros::delay(200);
	back(100,127);
	rotateleft(150,127);
	back(800,127);
	rotateright(30,127);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(2000);
	rotateleft(450,127);
	pros::delay(300);
	fwd(550,127);
	rotateleft(120,127);
	pros::delay(200);
	rotateleft(60,127);
	fwd(1500,110);
	rotateleft(180,127);
	fwd(300,127);
	pros::delay(100);
	back(1000,127);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(750);
	cam.move_relative(360,127);
	pros::delay(2000);
	fwd(1000,127);
	expansionL.set_value(false);
	expansionR.set_value(false);
	expansionL.set_value(true);
	rotateright(120,127);
	expansionR.set_value(true);
	// pros::delay(500);
	// fwd(150,127);
	// pros::delay(200);
	// intake.move_relative(-90,127)



}

void autonomous() {
// auton_win(); 
//mainauton();
// secondaryauton();
// autonskills();
consistentautonskills();

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
	// Variable Storage
	int expcount1 = 0;
	int expcount2 = 0;

	float proportional1;
 	float proportional2;

 	int target_rpm = 0;

 	float TotalError1;
 	float TotalError2;

 	float integral1;
 	float integral2;

 	float LastError1;
 	float LastError2;

 	float derivative1;
 	float derivative2;

 	float rpm1;
	float rpm2;

 	int is_flywheel_running = 0;

	float error1 = 0;
  	float error2 = 0;
 	
// Input Constants here

  // Kp is for proportional gain
  float Kp = 0.5;
  // Ki is integral gain
  float Ki = 0;
  // Kd is derivative gain
  float Kd = 0.5;


	while (true) {
	// Printing Flywheel Values to terminal
	printf("%f", fw1.get_actual_velocity());
	printf(";");
	printf("\n");

	
	//Drivebase
	int leftx = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	int lefty = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightx = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	driveFL.move(leftx + lefty + rightx);
	driveFR.move(leftx - lefty + rightx);
	driveBR.move(leftx + lefty - rightx);
	driveBL.move(leftx - lefty - rightx);
	

	//Intake
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
	intake.move(127);
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
	intake.move(-127);	
	}

	else { 
		intake.move(0);
	}


	
	


	//Flywheel
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
		if (is_flywheel_running == 0) {
			is_flywheel_running = 1;
			target_rpm = 450;
		}
		else if (is_flywheel_running ==1) {
			is_flywheel_running = 0;
			target_rpm = 0;
		}
	}

	error1 = (target_rpm - rpm1);
  	error2 = (target_rpm - rpm2);
	rpm1 = fw1.get_actual_velocity();
	rpm2 = fw2.get_actual_velocity();

  if (error1 and error2 != 0) {


  // Proportional
  proportional1 = Kp*error1;
  proportional2 = Kp*error2;

  // Integral
  // Be very careful with this, because if you set this too high, we will kill the motors VERY fast
  TotalError1 = TotalError1 + error1;
  TotalError2 = TotalError2 + error2;
  integral1 = TotalError1 * Ki;
  integral2 = TotalError2 * Ki;

  if (TotalError1 > 50/Ki) {
  integral1 = 50/Ki;
  integral2 = 50/Ki;

  }


 // Derivative 

  derivative1 = (error1 - LastError1) * Kd;
  derivative2 = (error2 - LastError2) * Kd;
  LastError1 = error1;
  LastError2 = error2;
}
// If the RPM is already perfect, then to just stay in the same place
else if (error1 and error2 == 0) {
  proportional1 = 0;
  proportional2 = 0;
  integral1 = 0;
  integral2 = 0;
  derivative1 = 0;
  derivative2 = 0;
}
// Slowing the flywheel down
	if (is_flywheel_running ==0  and (rpm1+proportional1 + integral1 + derivative1 <=25 or rpm2+proportional2 + integral2 + derivative2<=25)) {
      fw1.move_velocity(0);
      fw2.move_velocity(0);
  }
// Setting the velocities using PID
	else if (is_flywheel_running == 1)
  {
  fw1.move_velocity(rpm1+proportional1 + integral1 + derivative1);
  fw2.move_velocity(rpm2+proportional2 + integral2 + derivative2);
  }

// Cam prog

	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) && fw1.get_actual_velocity() > 300) {
	cam.move_relative(1080, 200);
	
	}

	//Expansion

	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
	expansionL.set_value(true);
	
	}
	
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
	expansionR.set_value(true);
	}
}
pros::delay(20);
}