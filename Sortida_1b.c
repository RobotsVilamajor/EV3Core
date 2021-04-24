#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

// ROBOPRO || VEATRIZ
#define VEATRIZ

#include "Core/Core.h";

task main()
{
	MoveMotorTime(motorA, 3, 70)
	MoveMotorTime(motorD, 4, 70)
	MoveMotor(motorD, -6.2, 50);AlignWall();

	//MoveMotorTime(motorA, 3, 70;
	//MoveMotorTime(motorD, 4, 70);
	//MoveMotor(motorD, -6.2, 50);


	waitForButtonPress();

	//Fer ajust inicial
	delay(250);
	Recta(Bwd, 0.1, 30);

	//Anem fins a la canasta
	//Avancem fins catxarrito
	MoveMotor(motorA, -0.9, 70);
	Recta(Fwd, 1.5, 50);


	//Avancem fins humans
	Turn(Rgt, 40, 20);
	Recta(Fwd, 1.7, 50);

	//Arribem a canasta
	Turn(Lft, 39, 20);
	Recta(Fwd, 1.9, 50);


	//Fem canasta
	//Deixem bloc
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);
	MoveMotorTime(motorA, 1.5, 75);

	//Pujem primer pis
	MoveMotor(motorD, 3.5, 75);

	//Pujem segon pis
	MoveMotorTime(motorA, 2, -80);
	MoveMotor(motorD, -3.5, 75);
	MoveMotorTime(motorA, 2, 80);
	Turn(Lft, 10, 30);
	MoveMotor(motorD, 5.5, 80);
	MoveMotor(motorA, 0.8, -40);

	//Tornem base
	//Sortim canasta
	MoveMotorAsync(motorD, 5, -80);
	Recta(Bwd, 0.5, 30);

	//Agafem unitat de salut
	Turn(Lft, 57, 30);
	Recta(Fwd, 4.5, 60, false, false);
}
