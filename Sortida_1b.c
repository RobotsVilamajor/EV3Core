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
#define ROBOPRO

#include "Core/Core.h";

task main()
{
	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	waitForButtonPress();

//Anem fins a la canasta
	//Abancem fins catxarrito
	MoveMotorAsync(motorA, -0.9, 50);
	Recta(Fwd, 0.75, 75);
	delay(10);

	//Abancem fins humans
	Turn(Rgt, 60, 50);
	delay(10);
	Recta(Fwd, 2.1, 75);
	delay(10);

	//Arribem a canasta
	Turn(Lft, 60, 50);
	delay(10);
	Recta(Fwd, 1.95, 75);
	delay(10);


//Fem canasta
	//Deixem bloc
	MoveMotor(motorA, 0.9, 100);

	//Pujem primer pis
	MoveMotor(motorD, 3, 70);

	//Pujem segon pis
	MoveMotor(motorA, -1, 100);
	MoveMotor(motorD, -3, 100);
	MoveMotor(motorA, 1, 100);
	MoveMotor(motorD, 7, 100);

////Tornem base
//	//Sortim canasta
//	Recta(Bwd, ?, 75);

//	//Agafem unitat de salut
//	Turn(Lft, ?, 50);
//	Recta(Fwd, ?, 75);
}
