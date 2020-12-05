#ifndef _TURN
#define _TURN

#include "Functions.h"


void AdjustWheel(tMotor m, float target)
{
	float error = getMotorEncoder(m) / 360.0 - target;

	if (!InBetween(error, -0.005, 0.005))
	{
		float dir = 0;

		if (error < 0)
			dir = -1;
		else
			dir = 1;

		setMotorSpeed(m, -6 * dir);

		waitUntil((getMotorEncoder(m) / 360.0 - target) * dir <= 0);

		setMotorSpeed(m, 0);

		delay(100);
	}
}

void Turn (float dir, float angle, float speed)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	float target = angle / 179.19;

	Accelerate acc;
	InitAcc (acc, speed, target * 1.1,  30,  30, 7, 7, 0.1);

	while (fabs(getMotorEncoder(motorB)) / 360.0 < target || fabs(getMotorEncoder(motorC)) / 360.0 < target)
	{
		float c_speed = GetSpeed (acc, fabs(getMotorEncoder(motorB)) / 360.0);

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

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
