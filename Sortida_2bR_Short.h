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

#include "Core/Core.h"

void Sortida_2bR_Short(bool align = false)
{
	//Align
	if (align == true)
	{
		MoveMotorTime(motorA, 2, -70);
		MoveMotorTime(motorD, 3, 70);
		delay(200);
		MoveMotor(motorD, 1, -70);		// abans 0.6
		MoveMotor(motorA, 1.3, 70);		//1.35 abans ... li he tret
	}
	//Fer ajust inicial
	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();
	delay(250);
	Recta(Bwd, 0.02, 10, false, false);


	// Anem a boccia
	Recta(Fwd, 4.7, 60);
	MoveMotorAsync(motorA, 0.5, 70);
	MoveMotor(motorD, 5, -70); // abans 5.4
	Recta(Fwd, 0.85, 60, true, true);			// Robopro 0.7  (0.6 + 0.27)
	MoveMotorAsync(motorD, 3.8, 70);			//abans 3.3 (+0.7 amunt)
	//Recta(Fwd, 0.27, 50, true, true);		//Robopro 0.27
	MoveMotor(motorA, 0.5, -70);
	Turn(Rgt, 40, 10);		//tota l'estona 41
	Recta(Fwd, 2.35, 30);		//2.25

	// Moure rodes
	MoveMotor(motorA, 0.4, 70);			//0.6 per l'aliniat
	MoveMotorTime(motorA, 0.2, 70);
	MoveMotor(motorD, 3.1, -70);			//2.2
	MoveMotor(motorA, 1.5, -70);
	MoveMotorTime(motorA, 0.3, -70);
	MoveMotorAsync(motorD, 1, 70);

	// Tirem dau
	Recta(Bwd, 0.6, 40);
	MoveMotorAsync(motorA, 0.2, 70);
	MoveMotor(motorD, 0.8, 60);


	////Tornar

	Recta(Fwd, 0.3, 30, false, true);
	MoveMotorAsync(motorD, 3, 60);
	MoveMotor(motorA, 0.7, 60); 	//Pala en posició per S3
	Recta(Bwd, 2.4, 50, false, true);
	setMotorSpeed (motorB, -35);
	setMotorSpeed (motorC, 35);
	delay(425);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);
	Recta(Bwd, 6, 60, false, true);
	MoveMotor(motorD, 1.4, -70);  //Pala en posició per S3		//Preparem alçada S3



}
