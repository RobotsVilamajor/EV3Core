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

// Sortida 1 retallada Robopro

#include "Core/Core.h";

void TNF_SORT_1R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 2, 70);
		MoveMotorTime(motorD, 4, 70);
	}

	waitForButtonPress();
	flushButtonMessages();
	//Fer ajust inicial
	Recta(Bwd, 0.02, 10, false, false);

	//Anem fins a la canasta
	//Avancem fins humans
	MoveMotorAsync(motorD, -6.2, 60);
	MoveMotor(motorA, 0.9, -70);
	Recta(Fwd, 2.5, 60);
	Turn(Rgt, 40, 15);

	//Arribem a canasta
	//Turn(Lft, 40, 15);
	//Turn(Lft, 40, 15);
	//MoveMotorAsync(motorA, 0.2, 20);
	////if (getColorReflected(S3)> 40)	{

	////	Turn(Lft, 2, 10);
	////}
	//Recta(Fwd, 1.7, 60); // Abans 1.69


	////Fem canasta
	////Deixem bloc
	//setMotorBrakeMode(motorB, motorBrake);
	//setMotorBrakeMode(motorC, motorBrake);
	//MoveMotorTime(motorA, 0.5, 70);

	////Pujem primer pis
	//MoveMotor(motorD, 3.7, 70);

	////Pujem segon pis
	//MoveMotorAsync(motorD, -3.7, 45);
	//MoveMotorTime(motorA, 1.7, -70); 	//1.8?
	//MoveMotorTime(motorA, 1.7, 70);
	//Recta(Bwd, 0.04, 10, false, false);
	//setMotorSpeed (motorB, -20);
	//setMotorSpeed (motorC, 20);
	//delay(300);
	//setMotorSpeed (motorB, 0);
	//setMotorSpeed (motorC, 0);
	//Recta(Fwd, 0.04, 20, false, false);
	//setMotorSpeed (motorB, 0);
	//setMotorSpeed (motorC, 0);
	//setMotorBrakeMode(motorB, motorBrake);
	//setMotorBrakeMode(motorC, motorBrake);
	//MoveMotor(motorD, 5.5, 70);
	//MoveMotorAsync(motorD, 3.5, -70);

	////Tornem base
	////Sortim canasta
	//Recta(Bwd, 0.5, 30, false, true);

	////Agafem unitat de salut
	////Turn(Lft, 55, 30);

	//setMotorSpeed (motorB, -40);
	//setMotorSpeed (motorC, 40);
	//delay(500);	//620, 600			595 (550)
	//setMotorSpeed (motorB, 0);
	//setMotorSpeed (motorC, 0);
	//MoveMotorAsync(motorA, 0.8, -20);
	//Recta(Fwd, 4.5, 60, false, true);
	//MoveMotor(motorD, 1.7, -70);			//1.6
	//MoveMotorTime(motorA, 1.2, -70);
}
