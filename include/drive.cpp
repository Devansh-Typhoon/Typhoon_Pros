#include "pros/imu.hpp"
#include "main.h"
#include <cmath>
// Math related comments
// why are you reading this
// what is the need for you to read this
// if you are still reading this, then you probs need to be reading this
// in which case
// you need 18 pi inches of driving to make a full rotation
// 56.5486677646 inches therefore for a full 360 turn
// 14.1371669412 for 90 degrees
// and therefore twice that for 180, but icba to calculate that, so why dont u, u lazy child
// fun fact: you need 14.1371669412 many full rotations to get 360 degrees of rotation
// you therefore need 14.1371669412/4 rotations of driving to get 90 degrees
// you have a phone dont you?
// search it up with your calculator


// Variables
float degFL;
float degFR;
float degBL;
float degBR;
float inch;
float target_deg;
float error_drive;
float Dp = 0.1;
float Dd = 0.1;
float driveProp;
float driveDeriv;
float LastDError;
float drive_outFL, drive_outBL, drive_outFR, drive_outBR;
float heading;

//Helper Functions
void resetMotorEncoders() {
    driveFL.tare_position();
    driveFR.tare_position();
    driveBL.tare_position();
    driveBR.tare_position();
}

void setDrive(float FL, float FR,float BL, float BR) {
    driveFL.move_voltage(FL);
    driveFR.move_voltage(FR);
    driveBL.move_voltage(BL);
    driveBR.move_voltage(BR);

}
//Autonomous Functions
float pidFL(double inch) {

 degFL = driveFL.get_position();
 target_deg = inch * 127.279220613;
 error_drive = target_deg - degFL;
 driveProp = Dp * error_drive;
 driveDeriv = Dd * (LastDError - error_drive);
 
 
drive_outFL = degFL + driveDeriv + driveProp; 
 
 LastDError = error_drive;
return (drive_outFL);

}
float pidFR(double inch) {

 degFR = driveFR.get_position();
 target_deg = inch * 127.279220613;
 error_drive = target_deg - degFR;
 driveProp = Dp * error_drive;
 driveDeriv = Dd *  (LastDError - error_drive) ;

 
drive_outFR = degFR + driveDeriv + driveProp; 
LastDError = error_drive;
return (drive_outFR);

}
float pidBL(double inch) { 

 degBL = driveBL.get_position();
 target_deg = inch * 127.279220613;
 error_drive = target_deg - degBL;
 driveProp = Dp * error_drive;
 driveDeriv = Dd * (LastDError - error_drive);
drive_outBL = degBL + driveDeriv + driveProp; 
LastDError = error_drive;
return (drive_outBL);

}
float pidBR(double inch) {

 degBR = driveBR.get_position();
 target_deg = inch * 127.279220613;
 error_drive = target_deg - degBR;
 driveProp = Dp * error_drive;
 driveDeriv =Dd*  (LastDError - error_drive);
 

drive_outBR = degBR + driveDeriv + driveProp; 

 LastDError = error_drive; 
 return (drive_outBR);


 



}
void translate(int inch) {
   while (true) {
  
    drive_outFL= pidFL(inch);
    drive_outFR= pidFR(inch);
    drive_outBL= pidBL(inch);
    drive_outBR= pidBR(inch);
   
   setDrive(drive_outFL,-drive_outFR,-drive_outBL,drive_outBR);


   }
}
void rotate(double inch) {
while (true) {
heading = imu.get_heading();
while ((target_deg/19.75) > heading > (target_deg/20.15)) {
   if (heading < (target_deg/20.15)) {
   // 20 is the number of degrees a wheel has to turn in order to get 1 degree of real life movement
   // it is also pretty much half of the meaning of life 
   // therefore 2 degrees of x drive rotation is the meaning of life
   // what a sad life
    drive_outFL= pidFL(inch);
    drive_outFR= pidFR(inch);
    drive_outBL= pidBL(inch);
    drive_outBR= pidBR(inch);

    setDrive(drive_outFL,drive_outFR,-drive_outBL,-drive_outBR);
   }
   else if (heading > (target_deg/19.75)) {
    drive_outFL= pidFL(inch);
    drive_outFR= pidFR(inch);
    drive_outBL= pidBL(inch);
    drive_outBR= pidBR(inch);

    setDrive(-drive_outFL,-drive_outFR,drive_outBL,drive_outBR);
   } 
   else {
    setDrive(0,0,0,0);
   }
 
}
}
imu.reset();
}
   

// void fwd(int units, int voltage) {
// //reset motor encoders
// resetMotorEncoders();
// //drive fwd until units reached
// while (driveFL.get_position() < units) {
//     setDrive(voltage,-voltage,-voltage,voltage);
// }
// //set drive back to neutral
//     setDrive(0,0,0,0);
// }

// void back(int units, int voltage) {
// //reset motor encoders
// resetMotorEncoders();
// //drive fwd until units reached
// while (driveBL.get_position() < units) {
//     setDrive(-voltage,voltage,voltage,-voltage);
// }
// //set drive back to neutral
//     setDrive(0,0,0,0);
// }


// void strafe(int units, int voltage) {
//     resetMotorEncoders();
//     //drive left/right until units are reached
//     while (driveFL.get_position() < units) {
//         setDrive(voltage,voltage,voltage,voltage);


//     }
//  //set drive back to neutral
//     setDrive(0,0,0,0);
// }

// void rotateleft(int units, int voltage) {
//     resetMotorEncoders();
//     // rotate until units are reached
//     while (driveFL.get_position() < units) {
//         setDrive(voltage,voltage,-voltage,-voltage);
//     }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }
// void rotateright(int units, int voltage) {
//     resetMotorEncoders();
//     // rotate until units are reached
//     while (driveBL.get_position() < units) {
//         setDrive(-voltage,-voltage,voltage,voltage);
//     }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }
