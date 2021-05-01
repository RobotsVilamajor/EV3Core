// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)
// Motor A --> horitzontal
// Motor D --> vertical
//Moviment Wall --> -: avall & dreta / +: amunt & esquerra

// Sortida amb retorn a la base

#include "Core/Core.h";

void Sortida_2(bool align = false)
{
	//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	MoveMotor(motorD, -6, 50); //6.2 abans


	//Fer ajust inicial
	waitForButtonPress();
	delay(250);
	Recta(Bwd, 0.08, 20);


	//Sortir de base direcció a M03 i recollir homenets
	Recta(Fwd, 3.1, 70, true, false);
	MoveMotorAsync(motorB, 0.2, -40);
	MoveMotor(motorC, 0.2, -40);
	delay (500);
	setMotorSpeed(motorB, 20);
	setMotorSpeed(motorC, 20);
	delay(1300);
	MoveMotorAsync(motorA, 1.1, 20);
	setMotorSpeed(motorB, 65);
	setMotorSpeed(motorC, 50);
	delay(2500);


	// Tornar a sortir.

	//Fer ajust inicial
	waitForButtonPress();
	delay(250);
	Recta(Bwd, 0.08, 20);

	//Avançar i girar cap a M08, després girar l'estructura
	MoveMotorAsync(motorD, 3.7, 70);
	Recta(Fwd, 6, 65);
	Turn(Rgt, 36, 20);
	Recta(Fwd, 3.7, 40);

	////Moure estructura i agafar porció
	//MoveMotorAsync(motorD, 3.55, -70);
	//MoveMotor(motorA, 0.4, -70);
	//MoveMotorTime(motorA, 0.3, -70);
	//Recta(Fwd, 1.5, 30, true, false);
	//MoveMotorAsync(motorB, 0.2, -40);
	//MoveMotor(motorC, 0.2, -40);
	//resetGyro(S2);
	//delay(250);
	//Recta(Bwd, 0.1, 10, false, true);


	//////Situar l'extremitat sota la M13
	//MoveMotorAsync(motorD, 0.5, 70);
	//MoveMotor(motorA, 0.6, 70);
	//Recta(Bwd, 0.18, 30);
	//MoveMotorAsync(motorD, 0.2, -70);
	//MoveMotor(motorA, 0.8, 70);
	//MoveMotorTime(motorA, 0.2, 70);

	////Aixecar M13 i col·locar-se de nou
	//MoveMotor(motorD, 4.9, 70);
	//MoveMotor(motorA, 1.2, -70);
	//MoveMotorAsync(motorA, 0.5, -70);
	//MoveMotor(motorD, 3.6, -70);
	//MoveMotorTime(motorA, 0.2, -70);

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
