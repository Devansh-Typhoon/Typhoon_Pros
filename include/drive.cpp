#include "main.h"

//Helper Functions
void resetMotorEncoders() {
    driveFL.tare_position();
    driveFR.tare_position();
    driveBL.tare_position();
    driveBR.tare_position();
}

void setDrive(float FL, float FR,float BL, float BR) {
    driveFL.move(FL);
    driveFR.move(FR);
    driveBL.move(BL);
    driveBR.move(BR);

}
//Flywheel Function


void shoot(int discs) {
    cam.move_relative(360 * discs, 127);
}
//Autonomous Functions

void fwd(int units, int voltage) {
//reset motor encoders
resetMotorEncoders();
//drive fwd until units reached
while (driveFL.get_position() < units) {
    setDrive(voltage,-voltage,-voltage,voltage);
}
//set drive back to neutral
    setDrive(0,0,0,0);
}

void back(int units, int voltage) {
//reset motor encoders
resetMotorEncoders();
//drive fwd until units reached
while (driveBL.get_position() < units) {
    setDrive(-voltage,voltage,voltage,-voltage);
}
//set drive back to neutral
    setDrive(0,0,0,0);
}


void strafe(int units, int voltage) {
    resetMotorEncoders();
    //drive left/right until units are reached
    while (driveFL.get_position() < units) {
        setDrive(voltage,voltage,voltage,voltage);


    }
 //set drive back to neutral
    setDrive(0,0,0,0);
}

void rotateleft(int units, int voltage) {
    resetMotorEncoders();
    // rotate until units are reached
    while (driveFL.get_position() < units) {
        setDrive(voltage,voltage,-voltage,-voltage);
    }
    //set drive back to neutral
    setDrive(0,0,0,0);
}
void rotateright(int units, int voltage) {
    resetMotorEncoders();
    // rotate until units are reached
    while (driveBL.get_position() < units) {
        setDrive(-voltage,-voltage,voltage,voltage);
    }
    //set drive back to neutral
    setDrive(0,0,0,0);
}

