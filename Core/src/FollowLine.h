#include "PID.h"
#include "Defines.h"

void FollowLine(float distance, float speed, float sensor, float side, bool bAcc = true, bool bDec = true, float Colorbalance = 0)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	float ColorBalance = 0;

	if(sensor == Lft)
	{
		if (side = Lft)
			ColorBalance = COLOR_BALANCE_LEFT_LEFT;
		else if (side = Rgt)
			ColorBalance = COLOR_BALANCE_LEFT_RIGHT;
	}
	else
	{
		if (side = Rgt)
			ColorBalance = COLOR_BALANCE_RIGHT_RIGHT;
		else if (side = Lft)
			ColorBalance = COLOR_BALANCE_RIGHT_LEFT;
	}

	if (Colorbalance != 0)
		ColorBalance = Colorbalance;

	if (bAcc)
	{
		setMotorSpeed(motorC, 0);
		setMotorSpeed(motorB, 0);
	}
	int position;
	if ((InBetween(speed, 0, 35))
		position = 0;
	else if (InBetween(speed, 36, 45))
		position = 1;
	else if (InBetween(speed, 46, 55))
		position = 2;
	else if (InBetween(speed, 56, 65))
		position = 3;
	else
		position = 4;

	//Proportional
	float prop_array[] = PROPORTIONAL_ARRAY;
	float prop_value;
	prop_value = prop_array[position];
//Integral
	float int_array[] = INTEGRAL;
	float int_value;
	int_value = int_array[position];
//Derivate
	float dev_array[] = DERIVATE;
	float dev_value;
	dev_value = dev_array[position];

	PID pid;
	//InitPID(pid, 0.5, 0.0, 0.02, 0.005);
	//InitPID(pid, 1, 0.0, 0.1, 0.005);
	//InitPID(pid, 1, 50, 0.15, 0.005);
	//InitPID(pid, 0.5, 40, 0.35, 0.005);
	//InitPID(pid, 0.35, 15, 0.035, 0.005);
		//InitPID(pid, 0.35, 6, 0, 0.005);
	InitPID(pid, prop_value, int_value, dev_value, 0.005);

	Accelerate acc;
	InitAcc(acc, speed, distance, 1000, 800, 2, 2, 7, 7, 0.1, bAcc, bDec);

	while (fabs(getMotorEncoder(motorC) / 360.0) <= distance || fabs(getMotorEncoder(motorB) / 360.0) <= distance)
	{
	float error = ColorBalance - getColorReflected(sensor == Lft ? S4 : S3);

		float turnRate = UpdatePID(pid, error) * -side;

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
