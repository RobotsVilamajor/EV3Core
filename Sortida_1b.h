// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#include "Core/Core.h";

void Sortida_1b(bool align = false)
{
	MoveMotorTime(motorA, 3, 70)
	MoveMotorTime(motorD, 4, 70)

	//MoveMotorTime(motorA, 3, 70;
	//MoveMotorTime(motorD, 4, 70);
	//MoveMotor(motorD, -6.2, 50);


	waitForButtonPress();

	//Fer ajust inicial
	delay(250);
	Recta(Bwd, 0.1, 30);

	//Anem fins a la canasta
	//Avancem fins catxarrito
	MoveMotorAsync(motorD, -6.2, 50);
	MoveMotor(motorA, -0.9, 70);
	Recta(Fwd, 1.5, 50);


	//Avancem fins humans
	Turn(Rgt, 40, 20);
	Recta(Fwd, 1.9, 50);

	//Arribem a canasta
	Turn(Lft, 40, 20);
	Recta(Fwd, 1.7, 50);


	//Fem canasta
	//Deixem bloc
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	MoveMotorTime(motorA, 1.5, 75);

	//Pujem primer pis
	MoveMotor(motorD, 3.5, 80);

	//Pujem segon pis
	MoveMotorAsync(motorD, -3.5, 80);
	MoveMotorTime(motorA, 2, -80);
	MoveMotorTime(motorA, 2, 80);
	Turn(Lft, 15, 30);
	MoveMotor(motorD, 5.5, 80);
	MoveMotor(motorA, 0.8, -40);

	//Tornem base
	//Sortim canasta
	MoveMotorAsync(motorD, 5, -80);
	Recta(Bwd, 0.5, 30);

	//Agafem unitat de salut
	Turn(Lft, 55, 30);
	Recta(Fwd, 4.5, 60, false, false);
}
