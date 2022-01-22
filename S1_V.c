#pragma config(Sensor, S2,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Motors:
//	Rigth: motorB
//	Left: motorC

// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// From max side to middle: 1.2
// From max up to down: 2.65
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

// ROBOPRO || VEATRIZ
#define VEATRIZ
//#define VEATRIZ

#include "Core/Core.h"

//#include "Sortida_2bR.h"
//#include "Sortida_2bR_Short.h"
//#include "Sortida_3R.h"
//#include "Sortida_4_Robopro.h"

task main()
{
	//Align wall(no acabat)
	MoveMotorTime(motorA, 4, -20);
	MoveMotorTime(motorD, 5, 30);
	MoveMotor(motorD, 1, -50);
	MoveMotor(motorA, 1.1, 50);  //abans 0.8
	////avan�ar fins l�nia(no fet)
	////avan�ar fins prova
	waitForButtonPress();
	//FollowLine(2, 40, Rgt, Lft, true, false, 60, 0.7, 60, 1);  // primer tram
	//FollowLine(0.5, 30, Rgt, Lft, false, false, 50); // corba BDP 20
	//FollowLine(2.2, 40, Rgt, Lft, false, true);  // segon tram
	WaitForLine(Fwd, 10, 20, Lft);   // Detectem banc
	resetGyro(S2);
	Recta(Fwd, 0.6, 10); //???
	MoveMotor(motorD, 1, -60);
	MoveMotor(motorA, 0.6, -50);
	Recta(Fwd, 0.5, 40);  // posiciones cercle empenyent grua
	MoveMotor(motorD, 1.5, -50);
	MoveMotor(motorA, 0.4, -50);  // deixem millora i contenidor
	MoveMotor(motorD, 0.5, 50);
	Recta(Fwd, 0.4, 30);
	MoveMotorTime(motorA, 2, 50);
	Recta(Fwd, 0.7, 30);
	MoveMotor(motorD, 1, 60);
	while(getColorReflected(S4)>=15){
	setMotorSpeed(motorB, -50);
	setMotorSpeed(motorC, -5);

	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);


	FollowLine(0, 20, Lft, Rgt, true, true, 50);
	WaitForBlack(Fwd, 2, 10, Rgt);

	//MoveMotor(motorA, 1, 60);
	MoveMotor(motorD, 1, 60);
	Recta(Bwd, 1, 30);
	Turn(-90, 30, Rgt);
	MoveMotor(motorA, 1.5, -60);
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	setMotorSpeed(motorB, 30);
	setMotorSpeed(motorC, 30);
	float count;
	while (getColorReflected(S3)<= 70){
		count = getMotorEncoder(motorB);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	if (count >= 1.01*360){
		MoveMotor(motorA, 0.5, 60);
		setLEDColor(ledRedFlash);
  }

	else if (count >= 0.76*360 && count <= 1*360){
		MoveMotor(motorA, 0.25, 60);
		setLEDColor(ledRed);
	}

	else if (count >= 0.5*360 && count <= 0.75*360){
		MoveMotor(motorA, 0, 60);
		setLEDColor(ledOrange);
	}

	else if (count >= 0.25*360 && count <= 0.49*360){
		MoveMotor(motorA, 0.25, -60);
		setLEDColor(ledGreen);
	}

	else if (count >= 0 && count <= 0.24*360){
		MoveMotor(motorA, 0.5, -60);
		setLEDColor(ledGreenFlash);
	}
	Recta(Bwd, 3, 70, true, false);
	//MoveMotor(motorA, 0.1, 60);
	//MoveMotor(motorD, 1.5, -60);
	//MoveMotor(motorA, 0.9, -60);
	//MoveMotorAsync(motorD, 1, 60);
	//Recta(Fwd, 1.6, 50);
	//MoveMotor(motorD, 1.8, -60);
	//Recta(Fwd, 1, 50);




}
