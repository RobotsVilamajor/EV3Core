#include "PID.h"
#include "Defines.h"

void FollowLine(int dir, float distance, float speed, bool bAcc = true, bool bDec = true)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	if (bAcc)
	{
		setMotorSpeed(motorC, 0);
		setMotorSpeed(motorB, 0);
	}

	PID pid;
	InitPID(pid, 300, 200, 1, 0.005);

	Accelerate acc;
	InitAcc(acc, speed, distance, 1000, 800, 2, 2, 7, 7, 0.1, bAcc, bDec);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance || fabs(getMotorEncoder(motorB) / 360.0) <= distance)
	{
		float error = getColorReflected(S1) - 50;

		float turnRate = UpdatePID(pid, error);

		float x = fabs(getMotorEncoder(motorC) / 360.0);
		float c_speed = GetAcc(acc, x);

		setMotorSync(motorB, motorC, turnRate, c_speed);
	}

	if (bDec)
	{
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
	}

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}
