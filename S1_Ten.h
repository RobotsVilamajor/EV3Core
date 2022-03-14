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
void Align_S1()
{
	flushButtonMessages();
	MoveMotorTime(motorA, 4, -20);
	MoveMotorTime(motorD, 5, 30);
	MoveMotor(motorA, 1.5, 50);
	MoveMotor(motorD, 0.7, -50); //0.8


}
void Sortida_1()
{
	//fase 1: anada
	waitForButtonPress();
	flushButtonMessages();
	resetGyro(S2);

	//sortida
	Recta(Fwd, 1.5, 40, false, false, 1, 0.85);
	WaitForBlack(Fwd, 10, 30, Rgt, false);
	delay(100);
	WaitForLine(Fwd, 10, 30, Rgt, false);
	MoveMotorAsync(motorD, 0.7, -50);
	FollowLine(1.5, 40, Rgt, Lft, false, false, 45, 0.9, 60, 0.1);  // primer tram //1
	FollowLine(2.5, 50, Rgt, Lft, false, false, 60, 0.4, 40, 0.09);  // segon tram//2.5 //3 //0.5

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Ens recoloquem
	if (getGyroDegrees(S2) > -47)
	Turn(-50, 60, Rgt);
	else if (getGyroDegrees(S2) < -53)
	Turn(-50, 60, Lft);

	//Coloquem wall
	MoveMotor(motorA, 0.2, -50);
	MoveMotorAsync(motorD, 0.3, 70); //0.4

	// baixem pon i movem grua
	WaitForLine(Fwd, 10, 20, Lft);  // Detectem banc
	Recta(Fwd, 0.2, 30, false, false); //Avan�ar per tirar pont //0.5
	MoveMotorAsync(motorD, 2.7, -70);//1
	Recta(Fwd, 1, 40, false, false);//0.7
	Recta(Bwd, 0.2, 70, false, false);

	//Ens recoloquem
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	delay(100);
	if (getGyroDegrees(S2) > -46)
		Turn(-50, 60, Rgt);
	else if (getGyroDegrees(S2) < -54)
		Turn(-50, 60, Lft);

	//Movem Wall per sortir
	MoveMotor(motorA, 0.9, -50);
	MoveMotor(motorD, 0.6, 70); //2.8
	MoveMotorAsync(motorD, 2.2, 70);//1
	MoveMotor(motorA, 1.3, 70);//1.4

	//Sortim i arrivem a tren
	Recta(Fwd, 0.45, 30);
	while(getColorReflected(S4)>=30){
	setMotorSpeed(motorB, -15);
	setMotorSpeed(motorC, 10);
	}
	FollowLine(1.7, 40, Lft, Rgt, false, false, 35, 0.9, 60, 0.1);
	WaitForLine(Fwd, 10, 20, Rgt);

	//Anem a paret
	Turn(-140, 30, Rgt);
	MoveMotorAsync(motorD, 1.3, -70);
	Recta(Bwd, 2.3, 70, false, false);//1 //2.5
	resetGyro(S2);

	//Tirem paquet helicopter
	MoveMotorTime(motorA, 1.5, -60);

	//Fem tren
	//Avancem fins balnca
	MoveMotor(motorA, 1.7, 70); //1.1
	MoveMotorAsync(motorD, 1.3, -40);//0.8
	resetMotorEncoder(motorC);
	resetMotorEncoder(motorB);
	WaitForLine(Fwd, 10, 30, Rgt, false);
	setMotorSpeed(motorA, 20);
	//Fem tren
	Recta(Fwd, 0.3, 30, false, false, 0.98, 1);
	setMotorSpeed(motorA, 0);
	Recta(Fwd, 0.8, 10, false, true);
	MoveMotor(motorA, 0.2, -70);//0.8
	Recta(Fwd, 0.75, 40, false, false);
	MoveMotor(motorD, 0.2, -70);
	//Agafem blocs
	Recta(Fwd, 0.75, 40, false, false);//0.8

	//Assegurem
	setMotorSpeed(motorB, -40);
	setMotorSpeed(motorC, -40);
	delay(300);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	setMotorSpeed(motorB, -40);
	setMotorSpeed(motorC, -40);
	delay(300);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	MoveMotor(motorD, 0.9, 50);
	setMotorSpeed(motorB, -20);
	setMotorSpeed(motorC, -20);
	delay(300);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Tornem
	setMotorSpeed(motorD, 50);
	delay(300);
	setMotorSpeed(motorA, -35);
	//Anem fins blanca
	Recta(Bwd, 1.95, 50, false);//1.5 //2
	setMotorSpeed(motorD, 0);
	setMotorSpeed(motorA, 0);
	//Agafem linea negre
	Turn(-90,40,Rgt);
	WaitForBlack(Fwd, 10, 40, Lft, false);   // Detectem negre
	Recta(Fwd, 0.3, 20, false, false);
		while(getColorReflected(S4)<=75){//85
		setMotorSpeed(motorC, 30);
		setMotorSpeed(motorB, -30);
		}
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
		delay(10);

		while(getColorReflected(S4)>=45){
		setMotorSpeed(motorC, 30);
		setMotorSpeed(motorB, -40);
		}
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
		delay(10);

		while(getColorReflected(S4)<=20){
		setMotorSpeed(motorC, -20);
		setMotorSpeed(motorB, 20);
		}
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
		delay(10);

	FollowLine(0.4, 45, Lft, Rgt, false, false, 0, 0.9, 60, 0.1);  // primer tram

		while(getColorReflected(S4)>=55){
		setMotorSpeed(motorC, 20);
		setMotorSpeed(motorB, -20);
		}

	FollowLine(0.5, 60, Lft, Rgt, false, false, 50, 0.9, 60, 0.1);  // primer tram

	WaitForBlack2(Fwd, 10, 30, Rgt, 1, 0.6, false);//0.7   // Detectem negre
	WaitForLine2(Fwd, 10, 20, Lft, 1, 0.6, false);   // Detectem blanc
	Recta(Fwd, 0.1, 20, false, false, 0.75);

		while(getColorReflected(S4)>=20){
		setMotorSpeed(motorC, -30);
		setMotorSpeed(motorB, 30);
		}
		delay(40);
		setMotorSpeed(motorC, 0);
		setMotorSpeed(motorB, 0);

	//Acavem de tornar
	MoveMotorAsync(motorA, 1.7, 40);
	FollowLine(1.8, 60, Lft, Rgt, false, false, 35, 0.9, 60, 0.1);
	MoveMotorAsync(motorD, 0.3, -50);
	Recta(Fwd, 1.5, 75, false, false, 1, 0.9);
	Recta(Fwd, 4.5, 75, false, false);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	delay(4000);
	MoveMotor(motorD, 0.7, 50);
	MoveMotor(motorD, 3, -50);
}
