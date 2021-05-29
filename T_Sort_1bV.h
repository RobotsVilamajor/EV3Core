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

#include "Core/Core.h";

void T_Sort_1bV(bool align = false)
{

flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 4, -30);
		MoveMotorTime(motorD, 4, -40);
		delay(100);
		MoveMotorAsync(motorA, 1.2, 40);
		MoveMotor(motorD, 2.65, 40);
	}
  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	// Sortir de base direcció a M03 i recollir homenets
	Recta(Fwd, 3.5, 60, true, false);
	setMotorSpeed	(motorB, -40);
	setMotorSpeed	(motorC, -40);
	delay(800);
	setMotorSpeed	(motorB, 0);
	setMotorSpeed	(motorC, 0);

	Recta(Bwd, 1, 40, false, false);
	Recta(Bwd, 1, 60, false, false);

	setMotorSpeed	(motorB, 70);
	setMotorSpeed	(motorC, 5);
	delay(450);
	//MoveMotorAsync(motorA, 1.3, 70);
	setMotorSpeed	(motorB, 60);
	setMotorSpeed	(motorC, 60);
	delay(1200);

	setMotorSpeed	(motorB, 0);
	setMotorSpeed	(motorC, 0);

	//MoveMotor(motorD, 5.2, 70);



}
