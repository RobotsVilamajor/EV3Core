// Wall:
// 	Vertical: motorD
//	Horizontal: motorA


// PREPAREM WALL SORTIDA 1

#include "Core/Core.h";

void Aliniat_S1(bool align = false)
{
	MoveMotorTime(motorA, 3, 70);
	MoveMotorTime(motorD, 4, 70);
}
