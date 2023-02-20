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
// float degFL;
// float degFR;
// float degBL;
// float degBR;
// float inch;
float target_deg;
float error_drive;
float Dp = 0.7;
float Dd = 0.8;
float Rp = 2;
float Rd = 1;
float driveProp;
float driveDeriv;
float LastDError;
float actual_volt;
// float drive_outFL, drive_outBL, drive_outFR, drive_outBR;
float heading;

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
// //Autonomous Functions
void flywheel(void * ignore, int time, int speed) {
    fw1.move_relative(time*50,speed);
    fw2.move_relative(time*50,speed);
}
// float pidFL(double inch,float LastDError) {

//  degFL = driveFL.get_position();
//  target_deg = inch * 127.279220613;
//  error_drive = target_deg - degFL;
//  driveProp = Dp * error_drive;
//  driveDeriv = Dd * (LastDError - error_drive);
//  drive_outFL = degFL + driveDeriv + driveProp; 
 
// //  LastDError = error_drive;
//  return (drive_outFL);

// }
// float pidFR(double inch, float LastDError) {

//  degFR = driveFR.get_position();
//  target_deg = inch * 127.279220613;
//  error_drive = target_deg - degFR;
//  driveProp = Dp * error_drive;
//  driveDeriv = Dd *  (LastDError - error_drive) ;

// drive_outFR = degFR + driveDeriv + driveProp; 
// // LastDError = error_drive;
// return (drive_outFR);

// }
// float pidBL(double inch,float LastDError) { 

//  degBL = driveBL.get_position();
//  target_deg = inch * 127.279220613;
//  error_drive = target_deg - degBL;
//  driveProp = Dp * error_drive;
//  driveDeriv = Dd * (LastDError - error_drive);
// drive_outBL = degBL + driveDeriv + driveProp; 
// // LastDError = error_drive;
// return (drive_outBL);

// }
// float pidBR(double inch,float LastDError) {

//  degBR = driveBR.get_position();
//  target_deg = inch * 127.279220613;
//  error_drive = target_deg - degBR;
//  driveProp = Dp * error_drive;
//  driveDeriv = Dd*  (LastDError - error_drive);
 

// drive_outBR = degBR + driveDeriv + driveProp; 

// //  LastDError = error_drive; 
//  return (drive_outBR);
// }
// void translate(int inch) {
//     float LastDError =  inch * 127.279220613;
//     float LastEError =  inch * 127.279220613;
//     float LastFError =  inch * 127.279220613;
//     float LastGError =  inch * 127.279220613;
//     resetMotorEncoders();
//    while (true) {
//     if ( -5 <LastDError<5)
//     {
//         degFL = driveFL.get_position();
//         target_deg = inch * 127.279220613;
//         drive_outFL= pidFL(inch,LastDError);
//             printf("I Am FrontLeft");
//     printf("%f", LastDError);
//       printf("\n");
//         LastDError = target_deg-degFL;
//     }
//     if ( -5 <LastEError<5)
//     {
//     target_deg = inch * 127.279220613;
//     degFR = driveFR.get_position();
//     printf("I Am Front Right");
//     printf("%f", LastEError);
//       printf("\n");
//     drive_outFR= pidFR(inch,LastEError);
//     LastEError = target_deg-degFL;
//     }
//        if ( -5 <LastFError<5)
//     { 
//     degBL = driveBL.get_position();
//     target_deg = inch * 127.279220613;
//     drive_outBL= pidBL(inch,LastFError);
//     LastFError= target_deg - degBL;
//     }
//     if ( -5 <LastGError<5) {
//     degBR = driveBR.get_position();
//     target_deg = inch * 127.279220613;
//     drive_outBR= pidBR(inch,target_deg - degBR);
//     LastGError= target_deg - degBR;
//     }
//    setDrive(drive_outFL,-drive_outFR,-drive_outBL,drive_outBR);


//    }
// }
// void rotate(double inch) {
// while (true) {
// heading = imu.get_heading();
// while ((target_deg/19.75) > heading > (target_deg/20.15)) {
//    if (heading < (target_deg/20.15)) {
//    // 20 is the number of degrees a wheel has to turn in order to get 1 degree of real life movement
//    // it is also pretty much half of the meaning of life 
//    // therefore 2 degrees of x drive rotation is the meaning of life
//    // what a sad life
//     drive_outFL= pidFL(inch);
//     drive_outFR= pidFR(inch);
//     drive_outBL= pidBL(inch);
//     drive_outBR= pidBR(inch);

//     setDrive(drive_outFL,drive_outFR,-drive_outBL,-drive_outBR);
//    }
//    else if (heading > (target_deg/19.75)) {
//     drive_outFL= pidFL(inch);
//     drive_outFR= pidFR(inch);
//     drive_outBL= pidBL(inch);
//     drive_outBR= pidBR(inch);

//     setDrive(-drive_outFL,-drive_outFR,drive_outBL,drive_outBR);
//    } 
//    else {
//     setDrive(0,0,0,0);
//    }
 
// }
// }
// imu.reset();
// }
   

void fwd(int units, int voltage) {
//reset motor encoders
float scale_factor = 1;
resetMotorEncoders();
if (units==0) {
scale_factor = 1;
}
else {
scale_factor = 90/units*23;
}
//drive fwd until units reached
while (driveFL.get_position() < units*23) {
    error_drive = (units * 23) - driveFL.get_position();   
    driveProp = error_drive * Dp;
    driveDeriv = (LastDError - error_drive) * Dd;
    actual_volt = (driveProp + driveDeriv)*scale_factor;
    // if (-5 < error_drive or error_drive > 5) {
    setDrive(actual_volt,-actual_volt,-actual_volt,actual_volt);
    LastDError = error_drive;
// }
}
//set drive back to neutral
    setDrive(0,0,0,0);
}

void back(int units, int voltage) {
//reset motor encoders
resetMotorEncoders();
//drive fwd until units reached
while (driveBL.get_position() < units*23) {
    error_drive = (units * 23) - driveBL.get_position();
    driveProp = error_drive * Dp;
    driveDeriv = (LastDError - error_drive) * Dd;
    actual_volt = voltage + driveProp + driveDeriv;
    
    setDrive(-actual_volt,actual_volt,actual_volt,-actual_volt);
    LastDError = error_drive;
}
//set drive back to neutral
    setDrive(0,0,0,0);
}


// void strafe(int units, int voltage) {
//     resetMotorEncoders();
//     //drive left/right until units are reached
//     while (imu.get_heading() < units) {
//         setDrive(voltage,voltage,voltage,voltage);


//     }
//  //set drive back to neutral
//     setDrive(0,0,0,0);
// }

// void rotateright(int units) {
//     resetMotorEncoders();
//     imu.reset();
//     LastDError = 0;
//     // float scale_factor = 127/units;
//     // rotate until units are reached
//    while (imu.get_heading()+15 > units+15 or imu.get_heading()+15 < units-15) {
//     error_drive = units - (imu.get_heading()+15);
//     driveProp = error_drive * Rp;
//     driveDeriv = (LastDError - error_drive) * Dd;
//     actual_volt = (driveProp + driveDeriv);
//     setDrive(actual_volt,actual_volt,-actual_volt,-actual_volt);
//     printf("%f",imu.get_heading());
//     printf("\n");
//     LastDError = error_drive;
//    }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }
// void rotateleft(int units) {
//     resetMotorEncoders();
//     imu.set_heading(0);
//     error_drive = units;
//     LastDError = 0;
//     // float scale_factor = 127/units;
//     // rotate until units are reached
//    while (imu.get_heading()-20 < (360-units)) {
//     error_drive =  (imu.get_heading())-(360-units);
//     driveProp = (error_drive * Rp);
//     driveDeriv = ((LastDError - error_drive) * Rd);
//     actual_volt = (driveProp + driveDeriv);
//     setDrive(-actual_volt,-actual_volt,actual_volt,actual_volt);
//     printf("%f",imu.get_heading());
//     printf("\n");
//     LastDError = error_drive;
//    }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }

void rotateRight(int units) {
    resetMotorEncoders();
    imu.set_heading(5);
    LastDError = 0;
    error_drive = units;
    // float scale_factor = 127/units;
    // rotate until units are reached
   while (imu.get_heading()+5 <= units ) {
    error_drive = units - (imu.get_heading());
    driveProp = error_drive * Rp;
    driveDeriv = (LastDError - error_drive) * Rd;
    actual_volt = (driveProp + driveDeriv);
    setDrive(actual_volt,actual_volt,-actual_volt,-actual_volt);
    printf("%f",imu.get_heading());
    printf("\n");
    LastDError = error_drive;
   }
    //set drive back to neutral
    setDrive(0,0,0,0);
}

// void rotate(int units) {
//     resetMotorEncoders();
//     imu.set_heading(0);
//     LastDError = 0;
//     error_drive = units;
//     // float scale_factor = 127/units;
//     // rotate until units are reached
//    while (imu.get_heading()+20 >= units ) {
//     error_drive = units - (imu.get_heading());
//     driveProp = error_drive * Rp;
//     driveDeriv = (LastDError - error_drive) * Rd;
//     actual_volt = (driveProp + driveDeriv)*(127/units);
//     setDrive(-actual_volt,-actual_volt,actual_volt,actual_volt);
//     printf("%f",imu.get_heading());
//     printf("\n");
//     LastDError = error_drive;
//    }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }
// void rotateright(int units, int voltage) {
//     resetMotorEncoders();
//     imu.reset();
//     // rotate until units are reached
//   while ((imu.get_heading() + 15) <  (units + 2) or (imu.get_heading() + 15) > (units - 2)) {
//     error_drive = units - (imu.get_heading() + 15);
//     driveProp = error_drive * Dp;
//     driveDeriv = (LastDError - error_drive) * Dd;
//     actual_volt = driveProp + driveDeriv;
//     setDrive(-actual_volt,-actual_volt,actual_volt,actual_volt);
//     printf("%f",imu.get_heading());
//     printf("\n");
//     LastDError = error_drive;
//    }
//     //set drive back to neutral
//     setDrive(0,0,0,0);
// }
