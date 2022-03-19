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
void Align_S4()
{
	flushButtonMessages();
	MoveMotorTime(motorD, 2, 70);
	MoveMotorTime(motorA, 4, -30);
	MoveMotor(motorD, 2.5, -50);
	//MoveMotor(motorA, 1.7, 30);
}
void Sortida_4()
{
	flushButtonMessages();
	waitForButtonPress();
	resetGyro(S2);
	delay(100);

	//sortida
	MoveMotorAsync(motorD, 0.7, 50);
	MoveMotorAsync(motorA, 1.7, 50);
	Recta(Fwd, 1.5, 40, false, false, 1, 0.9);
	WaitForBlack(Fwd, 10, 30, Rgt, false);
	delay(100);
	WaitForLine(Fwd, 10, 30, Rgt, false);

	//Tram 1: Gir
	FollowLine(2.5, 40, Rgt, Lft, false, false, 45,  0.7, 50, 0.2);  // primer tram //1

	//Tram 2:
	FollowLine(0.8, 50, Rgt, Lft, false, false, 45, 0.3, 45, 0.1); //0.5

	//Tram 3: Arribem pon
	FollowLine(0, 50, Rgt, Lft, false, false, 45, 0.3, 45, 0.1);
	MoveMotorAsync(motorD, 0.45, -80);//0.7
	MoveMotorAsync(motorA, 0.5, -80); //0.8
	FollowLine(0.8, 50, Rgt, Lft, false, false, 45, 0.3, 45, 0.1);
	FollowLine(0, 50, Rgt, Lft, false, false, 45, 0.3, 45, 0.1);
	Recta(Fwd, 0.5, 30, false, true);

	//Deixar millora
	MoveMotor(motorA, 0.8, 70);
	MoveMotorTime(motorA, 0.4, 70);
	MoveMotor(motorD, 1, 70);
	MoveMotor(motorA, 1.1, -70);

	//Anem bloc blau
	MoveMotorAsync(motorA, 0.9, 50); //0.9
	FollowLine(0.5, 40, Rgt, Lft, false, false, 65,  0.7, 50, 0.2); //0.5, 50 //0.7, 50, 0.12
	FollowLine(0.8, 40, Rgt, Lft, false, false, 65,  0.5, 40, 0.1); //0.5, 50 //0.4, 40
	FollowLine(0.9, 40, Rgt, Lft, false, false, 65,  0.3, 40, 0.1); //0.5, 50 //1.1 //0.4, 40
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Deixem bloc balu
	//MoveMotorTime(motorA, 0.3, -70);
	MoveMotor(motorA, 1.7, -80); //1.2
	MoveMotor(motorD, 1, 70);
	delay(10);
	//MoveMotorAsync(motorD, 1.2, 70);//2.6

	//Tornem per anar a l'�tlima zona
	//MoveMotorAsync(motorA, 1.6, 70); //1.6
	Recta(Bwd, 1, 50,false, false);
	Turn(-47, 20, Rgt); //32 //-50
	setmotorspeed(motorA, 60);
	Recta(Bwd, 2.25, 70, false, false); //2.3
	setmotorspeed(motorA, 0);
	WaitForLine(Bwd, 10, 30, Lft);
	Recta(Fwd, 0.1, 50, false, false);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Ens encarem
	Turn(43, 20, Lft); //43

	Align(Fwd, 2);
	Recta(Fwd, 0.6, 50); //0.6
	MoveMotor(motorD, 2.3, -80);
	MoveMotor(motorA, 2, -60);
	MoveMotorTime(motorA, 0.3, -80);

	MoveMotor(motorD, 2.3, 80);
	Recta(Fwd, 0.8, 50, false, false);
	Recta(Fwd, 0.3, 20, false, false);
	resetGyro(S2);
	delay(100);
	Recta(Bwd, 0.15, 50, false, false);
	MoveMotorAsync(motorA, 1.7, 70); //1.2
	Turn(90, 20, Lft);
	Recta(Bwd, 0.45, 20, false, false);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	//Fem la part final
	MoveMotor(motorD, 3, -80);
	Recta(Fwd, 0.45, 30, true, false);
	WaitForBlack(Fwd, 10, 20, Rgt);
	delay(150);
	flushButtonMessages();
	waitForButtonPress();
}