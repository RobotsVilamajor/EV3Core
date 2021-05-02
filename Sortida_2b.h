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

void Sortida_2b(bool align = false)
{
	//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotor(motorD, 0.6, -50);
	MoveMotorAsync(motorA, 1.3, 20);

	//Fer ajust inicial

	waitForButtonPress();
	flushButtonMessages();
	delay(250);
	Recta(Bwd, 0.08, 20);




	//// Avançar i girar cap a M08, després girar l'estructura
					/////MoveMotor(motorD, 5.2, 70);
					/////MoveMotorAsync(motorA, 1.3, 20);  //1.3 abans
					////Recta(Fwd, 3.8, 60);

	Recta(Fwd, 5.69, 60);
	Turn(Rgt, 42, 20);
	MoveMotorAsync(motorD, 2.2, -70);
	Recta(Fwd, 2.2, 50);

	// Moure rodes
			//MoveMotor(motorA, 0.9, -70);
			//MoveMotorTime(motorA, 0.2, -70);
		//Recta(Fwd, 0.95, 50);
	MoveMotor(motorA, 0.6, 70);
	MoveMotorTime(motorA, 0.3, 70);
	MoveMotor(motorD, 2.5, -70);
	MoveMotor(motorA, 1.5, -70);
	MoveMotorTime(motorA, 0.3, -70);
	MoveMotor(motorD, 1, 70);


	// Tirem dau
	Recta(Bwd, 0.6, 40);
	MoveMotorAsync(motorA, 0.3, 70);
	MoveMotor(motorD, 1, 60);


	//Avançar cap palanca i agafar porció
	MoveMotorAsync(motorD, 2.6, -20);
	Recta(Fwd, 3.4, 60, true, false);
	MoveMotorAsync(motorB, 0.3, -40);
	MoveMotor(motorC, 0.3, -40);
	Recta(Bwd, 0.1, 10);

	//Situar l'extremitat sota la M13
	MoveMotor(motorA, 0.6, 70);
	Recta(Bwd, 0.1, 30);
	MoveMotor(motorA, 0.7, 70);
	MoveMotorTime(motorA, 0.3, 70);

	//Aixecar M13 i col·locar-se de nou
	MoveMotor(motorD, 5.4, 70);
	MoveMotorAsync(motorA, 1.2, -70);
	MoveMotor(motorD, 1.9, -70);
	MoveMotorTime(motorA, 0.2, -70);


	 //Tornar

	MoveMotorAsync(motorA, 0.3, 70);

	Recta(Bwd, 5.05, 60);
		//setMotorSpeed	(motorB, 20);
		//setMotorSpeed	(motorC, 20);
		//delay(200);

		//MoveMotorAsync(motorB, 5.1, 51);
		//MoveMotor	(motorC, 5.1, 50);
	Turn(Lft, 32, 20);
	MoveMotorAsync(motorD, 2.4, -70);
	MoveMotor(motorA, 0.8, 70);
	MoveMotorTime(motorA, 0.3, 70);

	Recta(Bwd, 0.6, 40);

	MoveMotorAsync(motorD, 4, 70);
	MoveMotor(motorA, 1.5, -70);

	Recta(Bwd, 5.5, 60);

}
