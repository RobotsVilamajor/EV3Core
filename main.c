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
#define VEATRIZ

#include "Core/Core.h"

//#include "Sortida_2bR.h"
//#include "Sortida_2bR_Short.h"
//#include "Sortida_3R.h"
//#include "Sortida_4_Robopro.h"
//
task main()
{
	flushButtonMessages();
	//Recta(Bwd, 0.2, 60, true, true);
	MoveMotorAsync(motorA, 1, 80);
	MoveMotor(motorD, 1.7, 80);


	WaitForBlack(Fwd, 10, 30, Lft, false);
	delay(100);
	WaitForLine(Fwd, 10, 30, Lft);

}
