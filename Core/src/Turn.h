#ifndef _TURN
#define _TURN

#include "Functions.h"
#include "Defines.h"
#include "Accelerate.h"
void AdjustAngle(float angle)
{
	float error = getGyroDegrees(S2) - angle;

		writeDebugStreamLine("error: %f", error);

		//if (!InBetween(error, -0.005, 0.005))
		if (error != 0)
		{
			float dir = 0;

			if (error < 0)
				dir = -1;
			else
				dir = 1;

			setMotorSync(motorB, motorC, 100 * dir, 7);

			waitUntil((getGyroDegrees(S2) - angle) * dir <= 0);

			setMotorSpeed(motorB, 0);
  		setMotorSpeed(motorC, 0);

			//delay(100);
		}
}

void Turn(float dir, float angle, float speed)
{
	Accelerate acc;
	InitAcc(acc, speed, target, 1000, 2000, 2, 2, 7, 7, 0.1);

	setMotorSync(motorB, motorC, 100 * dir, 30);
	waitUntil(getGyroDegrees(S2) >= angle);


	//delay(1000);

	for (int i = 0; i < 100; i++)
	{
		AdjustAngle(angle * dir);
	}
}

#endif
