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

void Sortida_2(bool align = false)
{
	//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotor(motorD, 5.8, -50); //6.2 abans


	//Fer ajust inicial
	waitForButtonPress();
	delay(250);
	Recta(Bwd, 0.08, 20);


	// Sortir de base direcció a M03 i recollir homenets
	Recta(Fwd, 3.1, 50, true, false);
	MoveMotorAsync(motorB, 0.2, -40);
	MoveMotor(motorC, 0.2, -40);
	Recta(Bwd, 1.5, 30, true, false);

	setMotorSpeed	(motorB, 50);
	setMotorSpeed	(motorC, 20);
	delay(1200);

	setMotorSpeed	(motorB, 60);
	setMotorSpeed	(motorC, 60);
	delay(1000);

	setMotorSpeed	(motorB, 0);
	setMotorSpeed	(motorC, 0);

	MoveMotor(motorD, 5.2, 70);
	MoveMotorAsync(motorA, 1.3, 20);

	//// Avançar i girar cap a M08, després girar l'estructura
					/////MoveMotor(motorD, 5.2, 70);
					/////MoveMotorAsync(motorA, 1.3, 20);  //1.3 abans
					////Recta(Fwd, 3.8, 60);
	delay(2000);
	waitForButtonPress();

	Recta(Bwd, 0.08, 20);
	Recta(Fwd, 5.7, 60);
	Turn(Rgt, 40, 20);
	MoveMotorAsync(motorD, 2.2, -70);
	Recta(Fwd, 1.2, 40);

	//// Moure rodes
	//MoveMotor(motorA, 0.9, -70);
	//MoveMotorTime(motorA, 0.2, -70);
	//Recta(Fwd, 1.2, 50);
	//MoveMotor(motorA, 1.7, 70);
	//MoveMotor(motorD, 2.5, -70);
	//MoveMotor(motorA, 1.7, -70);
	//MoveMotorTime(motorA, 0.2, -70);
	//MoveMotor(motorD, 1, 70);
	//Recta(Bwd, 0.6, 40);

	//// Tirem dau
	//MoveMotorAsync(motorA, 0.3, 70);
	//MoveMotor(motorD, 1, 70);


	////Avançar cap palanca i agafar porció
	//MoveMotorAsync(motorD, 2.6, -20);
	//Recta(Fwd, 3.4, 60, true, false);
	//MoveMotorAsync(motorB, 0.2, -40);
	//MoveMotor(motorC, 0.2, -40);
	//Recta(Bwd, 0.1, 10);

	////Situar l'extremitat sota la M13
	//MoveMotor(motorA, 0.4, 70);
	//Recta(Bwd, 0.18, 30);
	//MoveMotor(motorA, 0.7, 70);
	//MoveMotorTime(motorA, 0.3, 70);

	////Aixecar M13 i col·locar-se de nou
	//MoveMotor(motorD, 5.1, 70);
	//MoveMotor(motorA, 1.2, -70);
	//MoveMotorAsync(motorA, 0.5, -70);
	//MoveMotor(motorD, 1.6, -70);
	//MoveMotorTime(motorA, 0.2, -70);


	// //Tornar

	//MoveMotor(motorA, 1.5, 70);
	//setMotorSpeed	(motorB, 20);
	//setMotorSpeed	(motorC, 20);
	//delay(200);

	//setMotorSpeed	(motorB, 50);
	//setMotorSpeed	(motorC, 20);
	//delay(1000);

	//setMotorSpeed	(motorB, 60);
	//setMotorSpeed	(motorC, 60);
	//delay(1000);

	//setMotorSpeed	(motorB, 0);
	//setMotorSpeed	(motorC, 0);

	//MoveMotor(motorC, 5, 50);
	//MoveMotorAsync(motorB, 5, 50);
	//MoveMotor(motorC, 5, 40);
	////Recta(Bwd, 5.5, 60);
	//Turn(Lft, 35, 20);






		////Col·locar-se cap a M08
	//Recta(Bwd, 1.6, 40);
	//Turn(Lft, 90, 20);
	//MoveMotor(motorA, 0.6, 70);
	//MoveMotorAsync(motorD, 0.5, -70);
	//Recta(Fwd, 0.3, 40, false, false);
	//MoveMotorAsync(motorB, 0.3, -30);
	//MoveMotor(motorC, 0.3, -30);
	//resetGyro(S2);
	//delay(250);
	//Recta(Bwd, 0.1, 40);

	////Aixecar M08
	//MoveMotor(motorD, 0.55, 70);
	//Recta(Bwd, 0.55, 40);
	//MoveMotor(motorA, 0.9, 70);
	//MoveMotor(motorD, 0.7, 70);

	////Moure les rodes enrere
	//MoveMotorAsync(motorD, 0.2, -70);
	//Recta(Bwd, 1.05, 60);
	//Recta(Fwd, 0.15, 40);

	////Avançar fins M03
	//MoveMotor(motorD, 1.9, -70);
	//Turn(Lft, 55, 20);
	//MoveMotor(motorA, 0.4, 70);
	//Recta(Fwd, 2.3, 60);
	//Turn(Lft, 35, 20);
	//MoveMotorAsync(motorA, 0.4, -70);
	//Recta(Fwd, 0.7, 40);
	//Turn(Lft, 38, 20);
	//Recta(Fwd, 0.2, 40);



	////Avançar fins M03
	//MoveMotorAsync(motorA, 1.1, 70);
	//MoveMotor(motorD, 2, -70);
	//Turn(Lft, 55, 20);
	//Recta(Fwd, 2.3, 40);
	//Turn(Lft, 35, 20);
	//Recta(Fwd, 1, 40);
	//Turn(Lft, 38, 20);

	////Aixecar les figures
	//MoveMotor(motorA, 1.2, 70);
	//MoveMotorAsync(motorD, 3.5, 40);
	//Recta(Fwd, 0.8, 40);




}
