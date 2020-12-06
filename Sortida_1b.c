#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// F - Forward; B - Backward. Recta direction definitions
// L - Left; R - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)


#include "Core/Core.h";

task main()
{
//Anem fins a la canasta
	//Abancem fins catxarrito
	MoveMotorAsync(motorA, 0.975, 50);
	Recta(Fwd, 0.75, 75);
	delay(10);

	//Abancem fins humans
	Turn(Rgt, 60, 50);
	delay(10);
	Recta(Fwd, 2.3, 75);
	delay(10);

	//Arribem a canasta
	Turn(Lft, 60, 50);
	delay(10);
	Recta(Fwd, 1.75, 75);
	delay(10);


//Fem canasta
	//Deixem bloc
	MoveMotor(motorA, 0.975, 100);
	Recta(Fwd, 01, 10);

	//Pujem primer pis
	MoveMotor(motorD, ?, 100);

	//Pujem segon pis
	MoveMotor(motorD, ?, 100);
	MoveMotor(motorA, ?, 100);
	MoveMotor(motorD, ?, 100);
	MoveMotor(motorA, ?, 100);

//Tornem base
	//Sortim canasta
	Recta(Bwd, ?, 75);

	//Agafem unitat de salut
	Turn(Lft, ?, 50);
	Recta(Fwd, ?, 75);
}
