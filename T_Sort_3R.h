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

#include "Core/Core.h"

void T_Sort_3R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 4, -40);
		MoveMotorTime(motorD, 4, 40);
		MoveMotorAsync(motorA, 1.2, 60);
		MoveMotor(motorD, -0.5, 40);
		MoveMotor(motorD, -2.6, 40);
	}
  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	//Començem sortida
	Recta(Fwd, 1, 50, true, true);
	FollowLine(4, 30, Rgt, Rgt, true, true);
	setMotorSync(motorB, motorC, 0, -30);
	waitUntil(getColorReflected(S4) > LINE_WHITE_MIN);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	Recta(Fwd, 0.2, 30, true, true);
	Turn(65, 50);
	Recta(Bwd, 0.5, 50, false, false);
	Recta(Bwd, 0.5, 30, true, true);
	MoveMotor(motorD, 1.5, 40);
	MoveMotor(motorA, 1.2, -40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	delay(300);
	Recta(Fwd, 0.7, 40, true, true);
	MoveMotor(motorD, -0.3, 40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	delay(300);
	Recta(Bwd, 0.3, 15, true, true);
	MoveMotor(motorA, 0.8, 40);
	MoveMotor(motorD, -1.2, 40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	delay(300);
	FollowLine(1.8, 30, Rgt, Rgt, true, true);
	MoveMotor(motorA, 1.6, 40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	delay(300);
	Recta(Fwd, 1, 30, true, true);
	MoveMotor(motorA, -1.7, 40);
	MoveMotor(motorD, -0.1, 40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	delay(300);
	Recta(Fwd, 0.5, 30, true, true);
	MoveMotor(motorD, 1, 40);
	setMotorBrakeMode(motorA, motorBrake);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.5, 30, true, true);
	Turn(40, 30);
	Recta(Fwd, 1.5, 50, false, true);
	delay(300);
}
