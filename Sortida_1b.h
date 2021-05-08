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
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 3, 70);
		MoveMotorTime(motorD, 4, 70);
		delay(250);
	}

	waitForButtonPress();
	flushButtonMessages();
	//Fer ajust inicial
	Recta(Bwd, 0.05, 30);

	//Anem fins a la canasta
	//Avancem fins catxarrito
	MoveMotorAsync(motorD, -6.2, 50);
	MoveMotor(motorA, -0.9, 70);
	Recta(Fwd, 1.5, 60);


	//Avancem fins humans
	Turn(Rgt, 40, 15);
	Recta(Fwd, 1.85, 60);	//1.9

	//Arribem a canasta
	Turn(Lft, 39, 15);
	Recta(Fwd, 1.69, 60); // Abans 1.7


	//Fem canasta
	//Deixem bloc
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	MoveMotorTime(motorA, 1.5, 70);

	//Pujem primer pis
	MoveMotor(motorD, 3.7, 70);

	////Pujem segon pis
	MoveMotorAsync(motorD, -3.7, 50);
	MoveMotorTime(motorA, 1.8, -70); 	//1.8?
	MoveMotorTime(motorA, 1.8, 70);
	setMotorSpeed (motorB, -15);
	setMotorSpeed (motorC, 15);
	delay(400);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	Recta(Fwd, 0.02, 30);
	MoveMotor(motorD, 5.5, 70);
	MoveMotorAsync(motorD, 3.5, -70);

	//Tornem base
	//Sortim canasta
	Recta(Bwd, 0.5, 30);

	//Agafem unitat de salut
	Turn(Lft, 60, 30);
	MoveMotorAsync(motorA, 0.8, -40);
	Recta(Fwd, 4.5, 60, false, true);
	MoveMotor(motorD, 1.6, -70);
	MoveMotorTime(motorA, 1.5, -70);
}
