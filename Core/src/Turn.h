#ifndef _TURN
#define _TURN

#include "Functions.h"
#include "Defines.h"
#include "Accelerate.h"


void AdjustAngle(float angle)
{
	float error = angle - getGyroDegrees(S2);

	//writeDebugStreamLine("error: %f", error);

	//if (!InBetween(error, -0.005, 0.005))
	if (error != 0)
	{
		float dir = error < 0 ? 1 : -1;

		setMotorSync(motorB, motorC, 100 * dir, 7);

		waitUntil((getGyroDegrees(S2) - angle) * dir <= 0);

		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);

		delay(90);
	}
	delay(3);
}

void Turn(float angle, float speed)
{
	//resetGyro(S2);
	//delay(300);

	float iniVal = getGyroDegrees(S2);
	float delta = angle - iniVal;

	float dir = delta < 0 ? 1 : -1;

	Accelerate acc;
	InitAcc(acc, speed, fabs(delta), 0.5, 0.02, 2, 2, 7, 7, 5, true, true);
	//InitAcc(acc, speed, angle, 0.5, 0.02, 2, 2, 7, 7, 5, true, true);

	while ((getGyroDegrees(S2) - iniVal) * -dir < fabs(delta))
	{
		float c_speed = GetAcc(acc, fabs(getGyroDegrees(S2) - iniVal));

		writeDebugStreamLine("x = %.1f, x - i = %.1f, delta = %.1f", getGyroDegrees(S2), (getGyroDegrees(S2) - iniVal) * -dir, delta);

		setMotorSync(motorB, motorC, 100 * dir, c_speed);
	}

	for (int i = 0; i < 100; i++)
	{
		AdjustAngle(angle);
	}

	setMotorSpeed(motorB, 0);
  setMotorSpeed(motorC, 0);
}

#endif
