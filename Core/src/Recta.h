#ifndef _RECTA
#define _RECTA

#include "PID.h"
#include "Accelerate.h"
#include "Functions.h"
#include "Defines.h"

void Recta (float dir, float distance, float speed, bool align = false)
{
	setMotorSpeed(motorC, 0);
	setMotorSpeed(motorB, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	PID pid;
	InitPID(pid, 300, 200, 1, 0.005);

	Accelerate acc;
	InitAcc (acc, speed, distance, 150, 125, 2, 2, 7, 5, 0.1);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance)
	{
		float x = fabs(getMotorEncoder(motorC) / 360.0);
		float c_speed = GetSpeed(acc, x);

		float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB) + RECTA_REGRESSION * x) / (360.0 * dir);

	  float turnRate = UpdatePID(pid, error);

		datalogAddValue(0, (int)(error * 1000));
		datalogAddValue(1, (int)(c_speed));

		setMotorSpeed(motorB, (c_speed + turnRate) * dir);
		setMotorSpeed(motorC, (c_speed - turnRate) * dir);
	}

	setMotorSpeed(motorB, 0);
  setMotorSpeed(motorC, 0);

  if (align)
  {
  	AdjustWheel(motorB, distance * dir);
  	AdjustWheel(motorC, distance * dir);
  }

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
