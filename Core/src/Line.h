#ifndef _LINE
#define _LINE

#include "PID.h"

typedef enum
{
	None = 0,
	Left,
	Right,
} Side;

void Line(float time, float dir)
{
	const int wThreshold = 50;	// White threshold
	const int bThreshold = 15;	// Black threshold

	if (dir < 0)
		dir = -1;
	else
		dir = 1;

	Side side = None;

	// Move until touching the white of the line,
	// then move the other motor until it touches it too
	setMotorSync(motorB, motorC, 0, 10 * dir);
	while (side == None)
	{
		//datalogAddValue(0, getColorReflected(S3));
		//datalogAddValue(1, getColorReflected(S4));

		if (getColorReflected(S4) > wThreshold)
		{
			setMotorSync(motorB, motorC, 0, 0);
			//stopAllMotors();

			side = Left;

			setLEDColor(ledOrangePulse);

			delay(1000);

			setMotorSpeed(motorB, 10 * dir);
			while (getColorReflected(S3) < wThreshold) {}
		}
		else if (getColorReflected(S3) > wThreshold)
		{
			setMotorSync(motorB, motorC, 0, 0);
			//stopAllMotors();

			side = Right;

			setLEDColor(ledRedPulse);

			delay(1000);

			setMotorSpeed(motorC, 10 * dir);
			while (getColorReflected(S4) < wThreshold) {}
		}
	}
	setMotorSync(motorB, motorC, 0, 0);
	delay(100);

	// Move until touching the black line
	side = None;
	setMotorSync(motorB, motorC, 0, 10 * dir);
	while (side == None)
	{
		if (getColorReflected(S4) < bThreshold)
			side = Left;
		else if (getColorReflected(S3) < bThreshold)
			side = Right;
	}
	setMotorSync(motorB, motorC, 0, 0);
	delay(100);

	// Adjust using PID
	PID lPID;
	PID rPID;
	InitPID(lPID, 0.15, 0.001, 0);
	InitPID(rPID, 0.15, 0.001, 0);

	float lTarget = 28;
	float rTarget = 40;

	clearTimer(T1);
	while (time1[T1] < time * 1000.0)
	{
		float lError = getColorReflected(S3) - lTarget;
		setMotorSpeed(motorB, -UpdatePID(lPID, lError));

		float rError = getColorReflected(S4) - rTarget;
		setMotorSpeed(motorC, -UpdatePID(rPID, rError));

		//displayCenteredBigTextLine(2, "%d - %d", lError, rError);
	}

	setMotorSync(motorB, motorC, 0, 0);
}

#endif
