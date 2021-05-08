#pragma config(Sensor, S2,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Motors:
//	Rigth: motorB
//	Left: motorC

// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// From max side to middle: 1.1
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

// ROBOPRO || VEATRIZ
#define ROBOPRO
#include "Aliniat_S1.h"
#include "Sortida_1b.h"
#include "Sortida_2a.h"
#include "Sortida_2b.h"
#include "Sortida_3.h"
#include "Sortida_4_Robopro.h"



task main()
{
	//delay(250);
	//Recta(Bwd, 0.1, 30);
	//Recta(Fwd, 5, 60);
	//Aliniat_S1();
	//Sortida_1b();
	//Sortida_2a(true);
	//Sortida_2b();


	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	//MoveMotorTime(motorA, 1.5, 70);

	//Pujem primer pis
	MoveMotor(motorD, 3.7, 70);

	////Pujem segon pis
	//MoveMotorAsync(motorD, -3.7, 50);
	//MoveMotorTime(motorA, 1.8, -70); 	//1.8?
	//MoveMotorTime(motorA, 1.8, 70);
	//setMotorSpeed (motorB, -15);
	//setMotorSpeed (motorC, 15);
	//delay(500);
	//setMotorSpeed (motorB, 0);
	//setMotorSpeed (motorC, 0);
	//setMotorBrakeMode(motorB, motorBrake);
	//setMotorBrakeMode(motorC, motorBrake);
	//MoveMotor(motorD, 5.5, 70);
	//MoveMotor(motorD, 3.5, -70);
}
