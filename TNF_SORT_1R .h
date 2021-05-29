// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

// Sortida 1 retallada Robopro

#include "Core/Core.h";

void T_1R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 2, 70);
		MoveMotorTime(motorD, 4, 70);
	}

	waitForButtonPress();
	flushButtonMessages();
	//Fer ajust inicial
	Recta(Bwd, 0.02, 10, false, false);


}
