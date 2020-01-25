#ifndef _RECTA
#define _RECTA

#include "Functions.h"
#include "PID.h"
#include "Accelerate.h"

float GetCorrection(float err, float turnRate, float threshold)
{
	if (InBetween(err, -threshold, threshold))
		return 0;
	else if (err < 0)
		return -turnRate;
	else
		return turnRate;
}

void Recta(float dir, float distance, float speed)
{
	setMotorSync(motorB, motorC, 0, 0);

	delay(50);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	PID pid;
	InitPID(pid, 0, 0, 0, 0.005);

	Accelerate acc;
	InitAcc(acc, speed, distance, 7, 5, 0.1);

	// Constrain the direction to {-1, 1}
	if (dir < 0)
		dir = -1;
	else
		dir = 1;

	// aqui /////////////////////////////////////////////////////////////////


	setMotorBrakeMode(motorB, motorCoast);
	setMotorBrakeMode(motorC, motorCoast);

	delay(50);

	setMotorSync(motorB, motorC, 0, 0);
	delay(50);

	//setMotorSync(motorB, motorC, 1, 3);
	float c_speed = 5;
	float dt = 0.02;
	while (c_speed < 9)
	{
		float err = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / 360.0;
		float turn = GetCorrection(err * 10000, 15 + 1 * c_speed, 5);

		datalogAddValue(0, (int)(err * 10000));
		datalogAddValue(1, (int)(turn * 10));
		datalogAddValue(2, (int)(c_speed));

		setMotorSync(motorB, motorC, turn, c_speed);

		c_speed += 10 * dt;

		delay(dt * 1000);
	}



	while (fabs(getMotorEncoder(motorC)) / 360.0 <= distance)
	{
		float dist = fabs(getMotorEncoder(motorC) / 360.0);

		float c_speed = UpdateAcc(acc, dist);

		float diff = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / (360.0 * dir);
		float iError = 0 + fabs(getMotorEncoder(motorC) / 360.0) * -0.0045;

		if (dist < acc.iniDist)
		{
			pid.k_p = 1000;
			pid.k_i = 300;
			pid.k_d = 2;
		}
		else if (dist < acc.medDist + acc.iniDist)
		{
			pid.k_p = 500;
			pid.k_i = 100;
			pid.k_d = 5;
		}
		else
		{
			pid.k_p = 500;
			pid.k_i = 100;
			pid.k_d = 0;
		}

		float error = diff - iError;
		float turnRate = UpdatePID(pid, error);

		datalogAddValue(0, (int)(error * 10000));
		datalogAddValue(1, (int)(turnRate * 10));
		datalogAddValue(2, (int)(c_speed));
		datalogAddValue(3, (int)(pid.integ * 1000));
		datalogAddValue(4, (int)(diff * 10000));

		setMotorSpeed(motorB, (c_speed + turnRate) * dir);
		setMotorSpeed(motorC, (c_speed - turnRate) * dir);
	}

	setMotorSync(motorB, motorC, 0, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
}

#endif
