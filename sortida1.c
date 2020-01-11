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
	resetMotorEncoder(motorA);
	setMotorTarget(motorA, -3*360, 50);
	delay (500);
	resetMotorEncoder(motorA);
	setMotorTarget(motorA, 3*360, 50);
	delay (2000);

	//Retrosedim, girem a la dreta i avancem
	Recta(-1, 2, 70);
	Turn(1, 20, 70);
	Recta(1, 2, 70);
	Turn(-1, 20, 70);

	//Deixar ratpanat
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, -1*360, 20);
	resetMotorEncoder(motorA);
	setMotorTarget(motorA, -0.5*360, 20);

	//Treure pinxo ratpanat
	resetMotorEncoder(motorA);
	setMotorTarget(motorA, 0.75*360, 20);
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, 1*360, 20);

	//Agafem dron
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, -3*360, 20);
	Recta(1, 0.5, 50);
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, 2.75*360, 20);

	//Avancem i deixem dron
	Recta(1, 0.5, 50);
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, -0.75*360, 20);


	//Baixem pala i ens movem fins la grua
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, -2*360, 20);
	Turn(1, 60, 70);
	Recta(-1, 3, 50);

	//Movem la grua
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, 1*360, 20);

	//Tornem a casa
	Recta(1, 1, 70);
	Turn(-1, 90, 70);
	Recta(-1, 7, 70);
	Turn(-1, 90, 70);
	Recta(-1, 4, 70);
}
