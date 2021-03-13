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

#include "Core/Core.h"

task main()
{
	resetGyro(S2);

	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Fer ajust inicial
	delay(250);

	Recta(Bwd, 0.08, 70);

	waitForButtonPress();

	float target = 90;



	//Turn(Lft, 50, 20);

	/*
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	waitForButtonPress();

	delay(1000);
	//Recta(Fwd, 4, 70, true);

	Turn(Rgt, 360, 7);

	delay(10000);
	*/
}
