#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortida Arbre; Missions: , ; Gadget 1
// MotorA = Vertical. MotorD = Horitzontal.

#include "Core/Core.h"

task main()
{
	//Avancem fins l'arbre
	Recta(1, 7, 50);
	delay(500);

	//Deixem els blocs en l'arbre(M5)
	MoveMotor(motorA, -3, 20);
	MoveMotor(motorA, 3, 20);

	//Retrosedim, girem a la dreta i avancem
	Recta(-1, 2, 70);
	Turn(1, 20, 70);
	Recta(1, 2, 70);
	Turn(-1, 20, 70);

	//Deixar ratpanat
	MoveMotor(motorD, -1, 20);
	MoveMotor(motorA, -0.5, 20);

	//Treure pinxo ratpanat
	MoveMotor(motorA, 0.75, 20);
	MoveMotor(motorD, 1, 20);

	//Agafem dron
	MoveMotor(motorD, -3, 20);
	Recta(1, 0.5, 50);
	MoveMotor(motorD, 2.75, 20);

	//Avancem i deixem dron
	Recta(1, 0.5, 50);
	MoveMotor(motorD, -0.75, 20);


	//Baixem pala i ens movem fins la grua
	MoveMotor(motorD, -2, 20);
	Turn(1, 60, 70);
	Recta(-1, 3, 50);

	//Movem la grua
	MoveMotor(motorD, 1, 20);

	//Tornem a casa
	Recta(1, 1, 70);
	Turn(-1, 90, 70);
	Recta(-1, 7, 70);
	Turn(-1, 90, 70);
	Recta(-1, 4, 70);
}
