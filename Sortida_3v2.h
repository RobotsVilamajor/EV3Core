//  Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#include "Core/Core.h";

void Sortida_3v2(bool align = false)
{
	MoveMotorTime(motorA, 1.5, -70);
	MoveMotorTime(motorD, 2.5, 70);
	MoveMotor(motorA, 1.1, 70);
	MoveMotor(motorD, 2.5, -70);
	resetGyro(S2);
	delay(300);
	waitForButtonPress();

		// corregir rodes
	delay(250);
	Recta(Bwd, 0.08, 8);

	//anar a M11

	Recta(Fwd, 8.3, 70);

	// encaixar gadget a M11
	Recta(Fwd, 0.5, 40);

	//anem a M9

	Recta(Bwd, 0.5, 50);
	Turn(Rgt, 16, 8);
	MoveMotorAsync(motorA, 0.3, -70);
	MoveMotor(motorD, 1.3, -70);
	Recta(Bwd, 1.6, 50);
	Turn(Lft, 14, 8);
	MoveMotorAsync(motorD, 1.3, 70);
	Recta(Bwd, 0.6, 50);

	MoveMotor(motorA, 1, 70);
	MoveMotor(motorD, 3.3, -70);

	// Girem rodes

	Recta(Fwd, 0.6, 70);
	MoveMotorAsync(motorD, 3.8, 50);
	Recta(Fwd, 1, 70);


	Recta(Fwd, 1.1, 70);
	MoveMotor(motorD, 3, -70);
	//MoveMotor(motorD, 2.7, -70);
}
