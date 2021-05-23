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

#include "Core/Core.h"

void Sortida_4_Robopro(bool align = false)
{
	if (align == true){
	//Aling
	MoveMotorTime(motorA, 2, -70);
	MoveMotorTime(motorD, 3, 70);
	MoveMotor(motorA, 0.95, 70);
	MoveMotor(motorD, 6.15, -70);
	}
	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();

	// Fer comptapassos
	Recta(Fwd, 4.7, 70, true, false);
	Recta(Fwd, 1.2, 50, false, false);
	setMotorSpeed(motorB, -17);
	setMotorSpeed(motorC, -15);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//desenganchem
	MoveMotorAsync(motorB, 0.3, 20);
	MoveMotor(motorC, 0.3, 20);
	MoveMotorAsync(motorA, 0.15, 70);
	MoveMotor(motorD, 0.1, 70);

	//gir

	MoveMotorAsync(motorB, 0.25,-20);
	MoveMotor(motorC, 0.25, -20);

	MoveMotorAsync(motorB, 0.12, 20);
	MoveMotor(motorC, 0.12, 20);

	Turn(Lft, 90, 30);

	//Ens col·loquem a la paret
 	 Recta(Bwd, 0.5, 30, false, false);
	MoveMotorAsync(motorA, 0.6, 70);
 	setMotorSpeed(motorB, 40);
	setMotorSpeed(motorC, 40);
	delay(300);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Avançem fins a la M14

	MoveMotorAsync(motorD, 3.3, 70);
	Recta(Fwd, 1.43, 40); //abans 55

	//Fem la M14
	MoveMotor(motorD, 1.05, -50);
	Recta(Bwd, 0.5, 30);
	MoveMotorAsync(motorA, 1, -70);
	MoveMotor(motorD, 1.95, -70);

	//Avançem fins a M8
	Recta(Fwd, 2.5, 60);
	MoveMotorAsync(motorD, 0.6, 70);
	Recta(Fwd, 0.49, 20, false, true);
	MoveMotor(motorD, 1.2, -70);
	Recta(Fwd, 0.55, 20, false, true);


	////Fem M8

	MoveMotorAsync(motorD, 1.3, 70);
	Recta(Bwd, 0.3, 20, false, false);
	setMotorSpeed (motorB, -50);
	setMotorSpeed (motorC, 50);
	delay(600);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);
	Recta(Fwd, 0.4, 20, false, false);
	while(True){
		setMotorSpeed(motorB, -20);
		setMotorSpeed(motorC, -20);
		delay(1000);
		setMotorSpeed(motorB, 20);
		setMotorSpeed(motorC, 20);
		delay(1000);
	}


}
