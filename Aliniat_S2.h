// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// PREPAREM WALL SORTIDA 2

#include "Core/Core.h";

void Aliniat_S2(bool align = false)
{
	//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotor(motorD, 5.8, -50);
}
