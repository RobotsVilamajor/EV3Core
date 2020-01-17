#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortia rampa; Missió a fer: M1, M11 i M13.
//MotorA = Vertical. MotorD = Horitzontal.
//Gir (Direcció (+__, -__), Angle, Velocitat)
//Horitzontal: Des de 0 --> 0,68
//Vertical: Des de 0 -->

#include "Core/Core.h"

task main()

{

	//MoveMotor (motorD, 0.68, 40);
	MoveMotor (motorA, 3.72, 40);

}
