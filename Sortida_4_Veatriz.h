// F - Forward; B - Backward. Recta direction definitions
// L - Left; R - Right. Turns direction definitions

// From max side to middle: 1.1
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#include "Core/Core.h";

void Sortida_4_Veatriz(bool align = false)
{

	//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 5, 70);
	MoveMotor(motorA, 0.95, 70);
	MoveMotor(motorD, 6.25, -70);
	waitForButtonPress();


	//Fem M2
	Recta(Fwd, 4.7, 70, true, false);
	Recta(Fwd, 1.2, 50, false, false);

	setMotorSpeed(motorB, -17);
	setMotorSpeed(motorC, -15);
	delay(500);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);


		//desenganchem
	MoveMotorAsync(motorB, 0.4, 20);
	MoveMotor(motorC, 0.4, 20);
	MoveMotorAsync(motorA, 0.15, 70);
	MoveMotor(motorD, 0.1, 70);

	//gir

	MoveMotorAsync(motorB, 0.35,-20);
	MoveMotor(motorC, 0.35, -20);

	MoveMotorAsync(motorB, 0.1, 20);
	MoveMotor(motorC, 0.1, 20);

	Turn(Lft, 90, 30);

	//Ens col·loquem a la paret
  Recta(Bwd, 0.5, 30, false, false);
	setMotorSpeed(motorB, 40);
	setMotorSpeed(motorC, 40);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);



	//Avançem fins a la M14
	MoveMotor(motorA, 0.6, 70);
	MoveMotorAsync(motorD, 3, 70);
	Recta(Fwd, 1.45, 50);



	//Fem la M14
	MoveMotor(motorD, 0.95, -30);
	Recta(Bwd, 0.4, 40);
	MoveMotor(motorA, 0.9, -50);
	MoveMotor(motorD, 2, -70);

	//Avançem fins a M8
	Recta(Fwd, 2.5, 50);
	MoveMotor(motorD, 1, 70);
	Recta(Fwd, 0.5, 30);
	MoveMotor(motorD, 1.1, -70);
	Recta(Fwd, 0.55, 30);

	//Fem M8

	MoveMotorAsync(motorD, 1.5, 70);
	Recta(Bwd, 0.3, 40);
	Turn(Lft, 60, 40);
	Recta(Fwd, 0.4, 30);
	while(True){
		setMotorSpeed(motorB, -20);
		setMotorSpeed(motorC, -20);
		delay(1000);
		setMotorSpeed(motorB, 20);
		setMotorSpeed(motorC, 20);
		delay(1000);
	}
}
