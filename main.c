#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	Recta(Fwd, 2, 70, -30, true, false);
	Recta(Fwd, 2, 70, 30, false, false);
	Recta(Fwd, 1, 70, 0, false, true);

	setMotorTarget(motorC, 0, 50);

	waitUntilMotorStop(motorC);
}
