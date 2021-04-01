#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

#define ROBOPRO

#include "Core/Core.h";

task main()
{
	//Align
	MoveMotorTime(motorA, 3, -70)
	MoveMotorTime(motorD, 4, 70)
	MoveMotorAsync(motorA, 1.15, 50);
	MoveMotor(motorD, -6.2, 50);
	resetGyro(S2);
	waitForButtonPress();

	//Fer ajust inicial
	delay(250);
	Recta(Bwd, 0.08, 20);
	delay(250);

	//Sortir de base direcci� a M03 i deixar estructura
	Recta(Fwd, 3.2, 50);
	MoveMotorTime(motorA, 1, -30);
	MoveMotorAsync(motorA, 1.35, 50);
	MoveMotor(motorD, 2.9, 50);

	//Avan�ar i girar cap a M08, despr�s girar l'estructura
	Recta(Fwd, 2.6, 50);
	Turn(Rgt, 34, 20);
	Recta(Fwd, 3.5, 40);

	//Moure estructura i agafar porci�
	MoveMotorAsync(motorD, 2.65, -70);
	MoveMotor(motorA, 1.3, -70);
	Recta(Fwd, 1.5, 30);

	MoveMotorAsync(motorB, 0.2, -40);
	MoveMotor(motorC, 0.2, -40);

	//Situar l'extremitat sota la M13
	MoveMotorAsync(motorD, 0.4, 70);
	MoveMotor(motorA, 1, 70);
	Recta(Bwd, 0.3, 30);
	MoveMotorAsync(motorD, 0.2, -70);
	MoveMotor(motorA, 0.8, 50);

	//Aixecar M13 i col�locar-se de nou
	MoveMotor(motorD, 4.4, 70);
	MoveMotor(motorA, 1, -70);
	MoveMotorAsync(motorA, 0.7, -70);
	MoveMotor(motorD, 3.5, -70);

	//Col�locar-se cap a M08
	Recta(Bwd, 1.5, 40);
	Turn(Lft, 90, 30);

	//Aixecar M08
	MoveMotor(motorA, 0.4, 70);
	Recta(Bwd, 0.2, 40);
	MoveMotorTime(motorA, 1, 70);
	MoveMotor(motorD, 0.5, 70);

	//Moure les rodes enrere
	Recta(Bwd, 1, 40);

	//Col�Locar-se contra paret i agafar porcions de salut



	////Avan�ar fins a M13, aixecar Wall per agafar porcions de salut i aixecar M13
	//MoveMotorAsync(motorD, -1.9, 25);
	//Recta(Fwd, 2.5, 50);

	////Fins aqu� fet. Cal definir angle de gir

	//MoveMotor(motorD, -0.4, 50);
	//MoveMotorAsync(motorA, 1, 50);
	//MoveMotor(motorD, 2.5, 50);

	////Col�locar-nos de nou, anar enrere fins a M10 i orientar-nos cap a M10
	//MoveMotor(motorD, -2.5, 50);
	//MoveMotorAsync(motorA, -1, 50);
	//Recta(Bwd, 3.5, 70);
	//Turn(Lft, 90, 50);

	////Avan�ar, aixecar Wall per agafar tel�fon, acabar d'avan�ar i baixar Wall per agafar tel�fon
	//Recta(Fwd, 0.5, 40);
	//MoveMotor(motorD, 2.5, 50);
	//Recta(Fwd, 0.2, 30);
	//MoveMotor(motorD, -2, 50);

	////Aixecar Wall per moure estructura M08
	//Recta(Fwd, 0.2, 30);
	//MoveMotor(motorD, 1, 50);

	////Anar enrere per moure rodes
	//MoveMotor(motorD, -1.5, 50);
	//Recta(Bwd, 2.5, 70);

	////Avan�ar i girar per tornar
	//Recta(Fwd, 0.5, 50);
	//Turn(Rgt, 90, 50);
	//Recta(Bwd, 3, 70);
	//Turn(Lft, 40, 70);

	////Part Final

}
