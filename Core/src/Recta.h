#ifndef _RECTA
#define _RECTA

#include "PID.h"
#include "Accelerate.h"
#include "Functions.h"
#include "Defines.h"

// Geogebra link: geogebra.org/graphing/rjzhaafu
/*float GetCorrection(float x)
{
	float min = 0.85;	// Minimum RECTA_REGRESSION value (percent)
	float b = 1.5;		// Geogebra
	float a = 2.5;		// Geogebra
	return RECTA_REGRESSION * (min - ((1.0 - min) / 2.0) * (tanh((x-a)/b) - 1));
}*/

void Recta(float dir, float distance, float speed, bool bAcc = true, bool bDec = true)
{
	float reg_array[] = REGRESSION_ARRAY;
	float reg_value;
	if (distance > 9)
		reg_value = reg_array[9];
	else
		reg_value = reg_array[(int)distance];

	if (bAcc)
	{
		setMotorSpeed(motorC, 0);
		setMotorSpeed(motorB, 0);
	}

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	delay(100);

	PID pid;
	InitPID(pid, 300, 200, 1, 0.005);

	Accelerate acc;
	InitAcc(acc, speed, distance, 1000, 800, 2, 2, 7, 7, 0.1, bAcc, bDec);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance || fabs(getMotorEncoder(motorB) / 360.0) <= distance)
	{
		float x = fabs(getMotorEncoder(motorC) / 360.0);
		float c_speed = GetAcc(acc, x);

		//float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB) + GetCorrection(x) * x) / (360.0 * dir);
		float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB) - dir * reg_value * x) / (360.0 * dir);

	  float turnRate = UpdatePID(pid, error);

		//datalogAddValue(0, (int)(error * 1000));
		//datalogAddValue(1, (int)(c_speed));

		setMotorSpeed(motorB, (c_speed + turnRate) * dir);
		setMotorSpeed(motorC, (c_speed - turnRate) * dir);
	}

	if (bDec)
	{
		setMotorSpeed(motorB, 0);
		setMotorSpeed(motorC, 0);
	}

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
