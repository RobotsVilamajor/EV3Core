#ifndef _LINE
#define _LINE

#include "PID.h"

typedef enum
{
	None = 0,
	Left,
	Right,
} Side;

void FollowLine(float time, float dir)
{
	if (dir < 0)
		dir = -1;
	else
		dir = 1;

	Side side = None;

	// Move until touching the line,
	// then move the other motor until it touches the line too
	setMotorSync(motorB, motorC, 0, 10 * dir);
	while (side == None)
	{
		if (getColorReflected(S4) > 80)
		{
			setMotorSync(motorB, motorC, 0, 0);
			delay(1000);
			side = Left;

			setMotorSpeed(motorB, 10 * dir);
			while (getColorReflected(S3) > 80) {}
		}
		else if (getColorReflected(S3) > 80)
		{
			setMotorSync(motorB, motorC, 0, 0);
			delay(1000);
			side = Right;

			setMotorSpeed(motorC, 10 * dir);
			while (getColorReflected(S4) > 80) {}
		}
	}
	setMotorSync(motorB, motorC, 0, 0);
	delay(100);

	// Move until leaving the line
	side = None;
	setMotorSync(motorB, motorC, 0, 10 * dir);
	while (side == None)
	{
		if (getColorReflected(S4) < 15)
			side = Left;
		else if (getColorReflected(S3) < 15)
			side = Right;
	}
	setMotorSync(motorB, motorC, 0, 0);
	delay(100);

	// Adjust using PID
	PID lPID;
	PID rPID;
	InitPID(lPID, 0.15, 0.05, 0);
	InitPID(rPID, 0.15, 0.05, 0);

	float lTarget = 28;
	float rTarget = 40;

	clearTimer(T1);
	while (time1[T1] < time * 1000.0)
	{
		float lError = getColorReflected(S3) - lTarget;
		setMotorSpeed(motorB, -UpdatePID(lPID, lError));

		float rError = getColorReflected(S4) - rTarget;
		setMotorSpeed(motorC, -UpdatePID(rPID, rError));
	}

	setMotorSync(motorB, motorC, 0, 0);
}

#endif
