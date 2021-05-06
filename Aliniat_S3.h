// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// PREPAREM WALL SORTIDA 3

#include "Core/Core.h";

void Aliniat_S3(bool align = false)
{
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotorAsync(motorA, 0.8, 70);
	MoveMotor(motorD, 2.5, -70);
}
