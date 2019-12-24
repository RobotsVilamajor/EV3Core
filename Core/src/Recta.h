#ifndef _RECTA
#define _RECTA

#include "PID.h"
#include "Accelerate.h"

void RectaStep(PID& pid, float speed, float dir)
{
	float error = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / -360.0;
	float turnRate = UpdatePID(pid, error);

	//datalogAddValue(0, (int)(error * 360.0));
	//datalogAddValue(1, turnRate);

	setMotorSync(motorB, motorC, turnRate, speed * dir);
}

void Recta(float dir, float distance, float speed)
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	PID pid;
	InitPID(pid, 500, 25, 0);

	Accelerate acc;
	InitAcc(acc, speed, distance, 15, 5, 0.15);

	// Constrain the direction to {-1, 1}
	if (dir < 0)
		dir = -1;
	else
		dir = 1;


	while (fabs(getMotorEncoder(motorC)) / 360.0 <= distance)
	{
		float c_speed = UpdateAcc(acc, fabs(getMotorEncoder(motorC)) / 360.0);

		float dist = fabs(getMotorEncoder(motorC) / 360.0);

		datalogAddValue(1, (int)dist * 100);
		displayCenteredBigTextLine(4, "%f", dist);

		RectaStep(pid, c_speed, dir);
	}

	setMotorSync(motorB, motorC, 0, 0);

	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);

	//float accMult = 10;
	//float decMult = 5;


	//// Add a safe dist to nail the distance
	//float safeDist = 0.15;
	//distance -= safeDist;


	//// Reduce if necessary the speed
	//float iniDist, endDist, medDist;

	//do
	//{
	//	iniDist = log(speed / 5.0) / (log(2) * accMult);
	//	endDist = log((speed - 5) / 5.0) / (log(2) * decMult);
	//	medDist = distance - iniDist - endDist;

	//	speed -= 1;
	//}
	//while (medDist < 0.2);

	//speed += 1;


	//// Acceleration
	//while (fabs(getMotorEncoder(motorC) / 360.0) <= iniDist)
	//{
	//	// 5*2^x*a
	//	float c_speed = pow(2, fabs(getMotorEncoder(motorC)	* accMult) / 360.0) * 5;

	//	RectaStep(pid, c_speed, dir);
	//}

	//// Constant speed
	//while (fabs(getMotorEncoder(motorC) / 360.0) <= medDist + iniDist)
	//{
	//	RectaStep(pid, speed, dir);
	//}

	//// Deceleration
	//float startDist = getMotorEncoder(motorC);

	//while(fabs(getMotorEncoder(motorC) / 360.0) <= distance)
	//{
	//	float c_speed = speed - pow(2, fabs((getMotorEncoder(motorC) - startDist)	* decMult) / 360.0) * 5;

	//	RectaStep(pid, c_speed, dir);
	//}

	//// Nail the distance
	//while (fabs(getMotorEncoder(motorC) / 360.0) <= distance + safeDist)
	//{
	//	RectaStep(pid, 7, dir);
	//}
}

#endif
