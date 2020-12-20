#ifndef _TURN
#define _TURN

#include "Functions.h"
#include "Defines.h"
#include "Accelerate.h"


void Turn (float dir, float angle, float speed)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	loat target = angle / TURN_CONVERSION;

	Accelerate acc;
	InitAcc (acc, speed, target, 2000, 2000, 2, 2, 7, 7, 0.1);

	while (fabs(getMotorEncoder(motorB)) / 360.0 < target || fabs(getMotorEncoder(motorC)) / 360.0 < target)
	{
		float c_speed = GetSpeed(acc, fabs(getMotorEncoder(motorB)) / 360.0);

		setMotorSpeed(motorB, c_speed * dir);
		setMotorSpeed(motorC, -c_speed * dir);

		//datalogAddValue(0, (int)(c_speed));

		delay(10);
	}

	float time = 1;

	clearTimer(T1);
	while (time1[T1] < time * 1000)
	{
		AdjustWheel (motorB, target * dir);
		AdjustWheel (motorC, -target * dir);
	}

	displayCenteredBigTextLine(2, "%.3f - %.3f", getMotorEncoder(motorB), (TURN_CONVERSION * getMotorEncoder(motorB)) / 360.0);
	displayCenteredBigTextLine(5, "%.3f - %.3f", getMotorEncoder(motorC), (TURN_CONVERSION * getMotorEncoder(motorC)) / 360.0);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
