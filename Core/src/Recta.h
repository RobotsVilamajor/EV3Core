#ifndef _RECTA
#define _RECTA

#include "PID.h"
#include "Accelerate.h"

void Recta (float dir, float distance, float speed)
{
	setMotorSpeed(motorC, 0);
	setMotorSpeed(motorB, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	PID pid;
	InitPID(pid, 300, 200, 1, 0.005);

	Accelerate acc;
	InitAcc (acc, speed, distance, 10, 10, 7, 5, 0.1);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance)
	{
		float x = fabs(getMotorEncoder(motorC) / 360.0);
		float c_speed = GetSpeed(acc, x);

		float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / (360.0 * dir);

		float turnRate = UpdatePID(pid, error);

		//datalogAddValue(0, (int)(c_speed));

		setMotorSpeed(motorB, (c_speed + turnRate) * dir);
		setMotorSpeed(motorC, (c_speed - turnRate) * dir);
	}

	setMotorSpeed(motorB, 0);
  setMotorSpeed(motorC, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
