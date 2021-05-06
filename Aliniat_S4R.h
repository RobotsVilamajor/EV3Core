// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// PREPAREM WALL SORTIDA 4 ROBOPRO

#include "Core/Core.h"

void Aliniat_S4R(bool align = false)
{
	//Aling
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 5, 70);
	delay(200);
	MoveMotorAsync(motorA, 0.95, 70);
	MoveMotor(motorD, 6.15, -70);
}
