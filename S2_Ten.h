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
//#define ROBOPRO


#include "Core/Core.h"

//#include "Sortida_2bR.h"
//#include "Sortida_2bR_Short.h"
//#include "Sortida_3R.h"
//#include "Sortida_4_Robopro.h"
void Align_S2()
{
	flushButtonMessages();
	MoveMotorTime(motorD, 2, 70);
	MoveMotorTime(motorA, 4, -30);
	MoveMotor(motorD, 3, -50);
	MoveMotor(motorA, 1.6, 30);
}

void Sortida_2()
{
	////Align wall(no acabat)

	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();

	//Fer tractors
	MoveMotorTime(motorA, 1, -70);
	Recta(Fwd, 2.9, 50, false, false); //3.3
	Recta(Fwd, 0.5, 30, false, false);
	Recta(Fwd, 0.5, 20, false, true);

	//Agafem Gall i abancem fins deixar ala
	MoveMotor(motorD, 1, 50);
	Recta(Fwd, 0.4, 30, true, false); //0.4
	Recta(Fwd, 0.4, 30, false, false); //0.35
	Recta(Fwd, 0.2, 50, false, false);
	MoveMotorAsync(motorD, -1, 50); //-0.9
	Recta(Fwd, 1.45, 50, false, false);	//1.5
	//Assegurem
	setMotorSpeed(motorB, 30);
	setMotorSpeed(motorC, 30);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Tornem. Deixem ala. Tirem dron
	Recta(Bwd, 0.2, 50, false, false, 1, 0.985); //0.3

	//Deixem gall i bloc
	MoveMotorAsync(motorA, 1.4, 30); //1.6
	Recta(Bwd, 1.9, 50, false, true);//2.2
	delay(100);
	MoveMotor(motorD, 2.2, 50);

	//Tornem i aliniem
	Recta(Bwd, 2, 70, false, false);
	MoveMotorAsync(motorD, 1.85, -50); // 1.7
	MoveMotorAsync(motorA, 0.4, -50); //0.4
	Recta(Bwd, 2.8, 70, false, false);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}
