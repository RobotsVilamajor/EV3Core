#ifndef _TURN
#define _TURN


void AdjustWheel (tMotor m, float target)
{
	float error = getMotorEncoder(m) / 360.0 - target;

	if (error != 0)
	{
		float dir = 0;

		if (error < 0)
			float dir = -1;

		else
			float dir = 1;

		setMotorSpeed(m, -6 * dir);

		waitUntil((getMotorEncoder(m) / 360.0 - target) * dir <= 0);

		setMotorSpeed(m, 0);

		delay(10);
	}
}

void Turn (float dir, float angle, float speed)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	float target = angle / 160.0;

	Accelerate acc;
	InitAcc (acc, speed, target * 1.1,  7,  5, 5, 5, 0.1);

	while (fabs(getMotorEncoder(motorB)) / 360.0 < target || fabs(getMotorEncoder(motorB)) / 360.0 < target)
	{
		float c_speed = GetSpeed (acc, fabs(getMotorEncoder(motorB)) / 360.0;

		setMotorSpeed(motorB, c_speed * dir);
		setMotorSpeed(motorB, -c_speed * dir);

		delay(10);
	}


	for (int i = 0; i < 100; i++)
	{
		AdjustWheel (-target * dir, motorB);
		AdjustWheel (target * dir, motorC);
	}

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
