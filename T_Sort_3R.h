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
	FollowLine(3.5, 50, Rgt, Lft, true, true);
}
