#ifndef _RECTA
#define _RECTA

#include "PID.h"
#include "Accelerate.h"
#include "Functions.h"
#include "Defines.h"

void Recta(float dir, float distance, float speed, float stear, bool bAcc = true, bool bDec = true)
{
	if (dir > 0)
		dir = 1;
	else
		dir = -1;

	if (bAcc)
		setMotorSpeed(motorB, 0);

	resetMotorEncoder(motorB);

	Accelerate acc;
	InitAcc(acc, speed, distance, 150, 125, 2, 2, 7, 5, 0.1, bAcc, bDec);

	setMotorTarget(motorC, stear, 50);

	while (fabs(getMotorEncoder(motorB) / 360.0) <= distance)
	{
		float x = fabs(getMotorEncoder(motorB) / 360.0);
		float c_speed = GetSpeed(acc, x);

		datalogAddValue(1, (int)(c_speed));

		setMotorSpeed(motorB, (c_speed) * dir);
	}

	if (bDec)
		setMotorSpeed(motorB, 0);

	resetMotorEncoder(motorB);
}

#endif
