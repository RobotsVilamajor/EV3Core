#ifndef _TURN
#define _TURN

#include "Accelerate.h"

void AdjustWheel(float target, tMotor m)
{
	float error = getMotorEncoder(m) - target;
	if (error != 0)
	{
		float dir = 0;
		if (error < 0)
			dir = -1;
		else
			dir = 1;

		setMotorSpeed(m, -6 * dir);
		waitUntil((getMotorEncoder(m) / 360.0 - target) * dir < 0);
		setMotorSpeed(m, 0);
		delay(10);
	}
}

void Turn(float dir, float angle, float speed)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	angle /= 160.0;

	if (dir < 0)
		dir = -1;
	else
		dir = 1;

	Accelerate acc;
	InitAcc(acc, speed, angle * 1.1, 10, 10, 0);

	while (fabs(getMotorEncoder(motorB) / 360.0) < angle || fabs(getMotorEncoder(motorC) / 360.0) < angle)
	{
		float c_speed = UpdateAcc(acc, fabs(getMotorEncoder(motorC)) / 360.0);

		datalogAddValue(0, (int)(c_speed * 100.0));

		setMotorSpeed(motorB, -c_speed * dir);
		setMotorSpeed(motorC, c_speed * dir);

		delay(10);
	}

	for (int i = 0; i < 100; i++)
	{
		//displayCenteredBigTextLine(4, "%.4f", getMotorEncoder(motorB) / 360.0);
		//displayCenteredBigTextLine(6, "%.4f", getMotorEncoder(motorC) / 360.0);
		//displayCenteredBigTextLine(8, "%.4f", (fabs(getMotorEncoder(motorB)) - fabs(getMotorEncoder(motorC))) / 360.0);

		AdjustWheel(-angle * dir, motorB);
		AdjustWheel(angle * dir, motorC);
	}

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
