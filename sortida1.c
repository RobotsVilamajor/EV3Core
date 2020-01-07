#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortida Arbre; Missions: , ; Gadget 1
// MotorA = . MotorD =

#include "Core/Core.h"

task main()
{
	//Avancem fins l'arbre
	Recta(1, 7, 50);

	//Deixem els blocs en l'arbre(M5)
	setMotorTarget(motorD, 2, 20);
	setMotorTarget(motorD, -2, 20);

	//Retrosedim, girem a la dreta i avancem
	Recta(-1, 2, 70);
	Turn(1, 20, 70)
	Recta(1, 2, 70);
	Turn(-1, 20, 70)

	//Deixar ratpanat
	setMotorTarget(motorA, -1, 20);
	setMotorTarget(motorD, -0.5, 20);

	//Treure pinxo ratpanat
	setMotorTarget(motorD, 0.75, 20);
	setMotorTarget(motorA, 1, 20);

	//Agafem dron
	setMotorTarget(motorA, -3, 20);
	Recta(1, 0.5, 50);
	setMotorTarget(motorA, 2.75, 20);

	//Avancem i deixem dron
	Recta(1, 0.5, 50);
	setMotorTarget(motorA, -0.75, 20);


	//Baixem pala i ens movem fins la grua
	setMotorTarget(motorA, -2, 20);
	Turn(1, 60, 70)
	Recta(-1, 3, 50);

	//Movem la grua
	setMotorTarget(motorA, 1, 20);

	//Tornem a casa
	Recta(1, 1, 70);
	Turn(-1, 90, 70);
	Recta(-1, 7, 70);
	Turn(-1, 90, 70);
	Recta(-1, 4, 70);
}
