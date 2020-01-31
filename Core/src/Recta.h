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

enum RectaState
{
	Default,
	Over,
	End
};

void Recta(float dir, float distance, float speed)
{
	//setMotorSync(motorB, motorC, 0, 0);

	//delay(50);

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

	setMotorSync(motorB, motorC, 0, 0);
	delay(50);

	setMotorBrakeMode(motorB, motorBrake);
	setMotorBrakeMode(motorC, motorBrake);

	setMotorSync(motorB, motorC, 0, 0);
	delay(50);

	//setMotorSync(motorB, motorC, 1, 3);
	//bool didTurn = false;
	RectaState state = Default;
	float c_speed = 5;
	float dt = 0.01;
	float sign = 0;
	//InitPID(pid, 1000, 500, 0, dt);
	while (c_speed < 8)
	{
		float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / 360.0;
		//float turn = GetCorrection(err * 10000, 50, 55);

		float turnRate = 0;//UpdatePID(pid, error);

		if (state == Over)
		{
			//UpdatePID(pid, error);

			//if (error * 10000 * sign > 60)
			//	turnRate = (55 + (c_speed - 5) * 2.5) * sign;
			//else
			//	turnRate = (50 + (c_speed - 5) * 2.5) * sign;
			turnRate = 50 * sign;

			//setMotorSync(motorB, motorC, turnRate, c_speed);
			//delay(dt * 1000);

			if (error * 10000 * sign <= 30)
			{
				state = Default;
				//pid.k_p = 1000;
				//pid.k_i = 1000;
				//pid.k_d = 0;
			}
		}
		else if (state == Default || state == End)
		{
			//turnRate = UpdatePID(pid, error);
			turnRate = GetCorrection(error * 10000, 5, 20);

			//setMotorSpeed(motorB, (c_speed + turnRate) * dir);
			//setMotorSpeed(motorC, (c_speed - turnRate) * dir);

			if (fabs(error) * 10000 > 50 && state != End)
			{
				setLEDColor(ledRed);
				state = Over;
				sign = error > 0 ? 1 : -1;
			}
		}

		datalogAddValue(0, (int)(error * 10000));
		datalogAddValue(1, (int)(turnRate * 1));
		datalogAddValue(2, (int)(c_speed));
		datalogAddValue(3, (int)(pid.integ * 1000));
		datalogAddValue(5, (int)(sign * 10));

		setMotorSync(motorB, motorC, turnRate, c_speed);
		//20 + 4 * c_speed
		//setMotorSpeed(motorC, (c_speed - turnRate) * dir);

		c_speed += 5 * dt;

		delay(dt * 1000.0);
	}

	pid.integ = 0;
	pid.prevError = 0;
	while (fabs(getMotorEncoder(motorC)) / 360.0 <= distance)
	{
		float dist = fabs(getMotorEncoder(motorC) / 360.0);

		float c_speed = UpdateAcc(acc, dist);

		float diff = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / (360.0 * dir);
		float iError = 0 + fabs(getMotorEncoder(motorC) / 360.0) * 0.0025;//-0.0045;

		if (dist < acc.iniDist)
		{
			pid.k_p = 900;
			pid.k_i = 300;
			pid.k_d = 1;
		}
		else if (dist < acc.medDist + acc.iniDist)
		{
			pid.k_p = 600;
			pid.k_i = 300;
			pid.k_d = 5;
		}
		else
		{
			pid.k_p = 300;
			pid.k_i = 150;
			pid.k_d = 2;
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
