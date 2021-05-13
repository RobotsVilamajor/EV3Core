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

void Sortida_2bV(bool align = false)
{
	//Align
	if (align == true)
	{
		MoveMotorTime(motorA, 2, -70);
		MoveMotorTime(motorD, 3, 70);
		delay(200);
		MoveMotor(motorD, 1, -50);		// abans 0.6
		MoveMotor(motorA, 1.3, 70);		//1.35 abans ... li he tret
	}
	//Fer ajust inicial
	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();
	delay(250);
	Recta(Bwd, 0.02, 10, false, false);


	// Anem a boccia
	Recta(Fwd, 4.7, 60);		//4.7 robopro
	MoveMotorAsync(motorA, 0.5, 70);
	MoveMotor(motorD, 5.2, -70); // abans 5
	Recta(Fwd, 0.65, 60, true, true);			// Robopro 0.7
	MoveMotorAsync(motorD, 3.4, 70);			//abans 3
	Recta(Fwd, 0.25, 50, true, true);		//Robopro 0.27
	MoveMotor(motorA, 0.5, -70);
	Turn(Rgt, 41, 10);
	Recta(Fwd, 2.3, 30);

	// Moure rodes
	MoveMotor(motorA, 0.4, 70);			//0.6 per l'aliniat
	MoveMotorTime(motorA, 0.2, 70);
	MoveMotor(motorD, 2.7, -70);			//2.2
	MoveMotor(motorA, 1.5, -70);
	MoveMotorTime(motorA, 0.3, -70);
	MoveMotorAsync(motorD, 1, 70);

	// Tirem dau
	Recta(Bwd, 0.6, 40);
	MoveMotorAsync(motorA, 0.2, 70);
	MoveMotor(motorD, 0.8, 60);


	//Avançar cap palanca i agafar porció
	MoveMotorAsync(motorD, 2.5, -30);
	Recta(Fwd, 3.5, 60, true, false);
	MoveMotorAsync(motorB, 0.3, -40);
	MoveMotor(motorC, 0.3, -40);
	MoveMotorAsync(motorD, 0.3, 70);
	Recta(Bwd, 0.25, 20);

	//Situar l'extremitat sota la M13
	MoveMotor(motorA, 1.4, 70);
	MoveMotorTime(motorA, 0.3, 70);

	//Aixecar M13 i col·locar-se de nou
	MoveMotor(motorD, 5.3, 70);
	MoveMotorAsync(motorA, 1.7, -70);	//1.7 abans al recollir
	MoveMotor(motorD, 2.9, -70);			//2.1 +1.5 avall per evitar enganxarm-e ... 3.6

	//Tornar

	MoveMotorAsync(motorD, 0.9, 70);
	Recta(Bwd, 2.5, 60, true, false);
	MoveMotorAsync(motorA, 0.4, 20); 	//Pala en posició per S3
	Recta(Bwd, 3, 60, false, true);
	setMotorSpeed (motorB, -35);
	setMotorSpeed (motorC, 35);
	delay(420);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);			//Turn(Lft, 35, 20);
	MoveMotorAsync(motorD, 1.9, 70);
	Recta(Bwd, 6, 60);
	MoveMotor(motorD, 2, -70);		//Preparem alçada S3

}
