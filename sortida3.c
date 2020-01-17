#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
// Sortida 3; Missió a fer: M6, M7 + possar una peça, M8, M12, M9, M10; Comentari: possiblement no es podran fer totes
// MotorA = Vertical, MotorD = Horitzontal.
//Negatiu= Pujar/ Positiu= Baixar
//F - Forward(endevant); B - Backward(enrere). Recta
//L - Left(esquerra); R - Right(dreta)
#include "Core/Core.h"

task main(){

//!!!!falta cambiar-ho tot a les indicacions de dalt!!!!. ex: -1=x   f= si
	Recta(1, 2, 20); // vaig cap a M6
	MoveMotor (motorA, -1, 50);//Pujar la pala
	MoveMotorAsync (motorA, -0.5, 30);
	MoveMotorAsync(motorD, 0.5, 30);
	WaitForMotors();
	// Això si no poden pujar a la vegada: MoveMotor (motorD //que tiri cap a la dreta (o mens al mateix temps que puja)
	Recta(-1, 0.2, 10);	// tiro enrere per sortir i anar diractament a M7
	MoveMotor (motorD, 0.5, 30);
	MoveMotorAsync (motorD, 0.5, 30);
	MoveMotorAsync(motorA, 0.8, 30);
	WaitForMotors();
	Recta (-1, 0.2, 20);//tirar enrere per podercolocar-se per sortir cap a M7
	MoveMotorAsync (motorD, 0.3, 30);
	MoveMotorAsync(motorA, 1, 30);
	WaitForMotors();  // els motors es mouen cap a l'altre costat
	Recta (1, 1.5, 20); //vaig cap a M7

	MoveMotor (motorD, -0.5, 30);
	MoveMotorAsync (motorD, -0.5, 30);
	MoveMotorAsync(motorA, 0.7, 30); //que baixi (per baixar la barra de M7)i que tiri cap a la dreta per tenir més seguratat de tocar-la
	WaitForMotors();
	Recta (1, 0.3, 30);//endevant
	MoveMotor (motorA, 0.5, 30); //que baixi, perque la construcció es quedi dins del cercle
	Recta (-1, 0.1, 10); //mateixa raó d'abans,preparar-se per sortir d'aquella zona per anar a una altra prova
	//posar el motor just al centre de la pala
	Turn(1, 90, 30); //vull girar a la dreta(no acabada la direcció)




}
