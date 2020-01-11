#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
// Sortida 3; Missió a fer: M6, M7 + possar una peça, M8, M12, M9, M10; Comentari: possiblement no es podran fer totes
// MotorA = Vertical, MotorD = Horitzontal.

#include "Core/Core.h"

task main(){
	Recta(1, 2, 20); // vaig cap a M6
	setMotorTarget (motorA, //que puji)
	setMotorTarget (motorD //que tiri cap a la dreta (o mens al mateix temps que puja)
	resetMotorEncoder (motorA, motorD)
	Recta(-1, 0.2, 10);	// tiro enrere per sortir i anar diractament a M7
	//moure els motors cap a l'altre costat
	Recta (1, 1.5, 20);
	setMotorTarget (motorA, //que baixi (per baixar la barra de M7)
	resetMotorEncoder (motorA)

	// Baixar la pala perque la construcció es quedi dins del cercle
	Recta (-1, 0.1, 10); //mateixa raó d'abans
	//Pujar la pala
	Turn(1, 90, 30); //vull girar a la dreta(no acaada la direcció)
}
