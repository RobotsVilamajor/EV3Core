#include "PID.h"
#include "Defines.h"

void FollowLine(float distance, float speed, float sensor, float side, bool bAcc = true, bool bDec = true)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	if (bAcc)
	{
		setMotorSpeed(motorC, 0);
		setMotorSpeed(motorB, 0);
	}

	PID pid;
	//InitPID(pid, 0.5, 0.0, 0.02, 0.005);
	//InitPID(pid, 1, 0.0, 0.1, 0.005);
	InitPID(pid, 1, 50, 0.15, 0.005);

	Accelerate acc;
	InitAcc(acc, speed, distance, 1000, 800, 2, 2, 7, 7, 0.1, bAcc, bDec);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance || fabs(getMotorEncoder(motorB) / 360.0) <= distance)
	{
		float error = 50 - getColorReflected(sensor == Lft ? S4 : S3);

		float turnRate = UpdatePID(pid, error) * side;

		float x = fabs(getMotorEncoder(motorC) / 360.0);
		float c_speed = -GetAcc(acc, x);

		datalogAddValue(0, error);
		datalogAddValue(1, turnRate);
		datalogAddValue(2, pid.ki * pid.integ * pid.dt);

		setMotorSync(motorB, motorC, turnRate, c_speed);
	}

	if (bDec)
	{
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
	}
}
