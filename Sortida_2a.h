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

void Sortida_2a(bool align = false)
{

	if (align = true){
		//Align
		MoveMotorTime(motorA, 3, -70);
		MoveMotorTime(motorD, 4, 70);
		delay(200);
		MoveMotor(motorD, 5.8, -50);
	}

	//Fer ajust inicial

	waitForButtonPress();
	flushButtonMessages();
	delay(250);
	Recta(Bwd, 0.08, 20);


	// Sortir de base direcció a M03 i recollir homenets
	Recta(Fwd, 3.1, 50, true, false);
	MoveMotorAsync(motorB, 0.2, -40);
	MoveMotor(motorC, 0.2, -40);
	Recta(Bwd, 1.5, 30, true, false);

	setMotorSpeed	(motorB, 70);
	setMotorSpeed	(motorC, 5);
	delay(1200);

	setMotorSpeed	(motorB, 60);
	setMotorSpeed	(motorC, 60);
	delay(1200);

	setMotorSpeed	(motorB, 0);
	setMotorSpeed	(motorC, 0);

	MoveMotor(motorD, 5.2, 70);
	MoveMotorAsync(motorA, 1.3, 20);


}
