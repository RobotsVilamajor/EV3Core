#include "PID.h"
#include "Defines.h"

void Align(float dir, float time)
{
	setMotorSync(motorC, motorB, 0, 12 * dir);

	while (getColorReflected(S3) < ALIGN_MIN_WHITE || getColorReflected(S4) < ALIGN_MIN_WHITE) {}

	while (getColorReflected(S3) > ALIGN_MIN_BLACK || getColorReflected(S4) > ALIGN_MIN_BLACK) {}

	setMotorSync(motorC, motorB, 0, 0);

	PID pidL, pidR;
	InitPID (pidL, 0.2, 10, 0, 0.01);
	InitPID (pidR, 0.2, 10, 0, 0.01);

	clearTimer(T1);

	float prev_errL = 0;
	float prev_errR = 0;
	while (time1[T1] < time * 1000)
	{
		// pidL
		float errorL = getColorReflected(S4) - ALIGN_TARGET_LEFT;
		float speedL = UpdatePID(pidL, errorL);
		setMotorSpeed(motorC, speedL * dir);

		// pidR
		float errorR = getColorReflected(S3) - ALIGN_TARGET_RIGHT;
		float speedR = UpdatePID(pidR, errorR);
		setMotorSpeed(motorB, speedR * dir);

		float dErrorL = errorL - prev_errL;
		float dErrorR = errorR - prev_errR;

		datalogAddValue(0, (int)(errorL));
		//datalogAddValue(0, (int)(dErrorL));
    datalogAddValue(1, (int)(speedL * 10));

    datalogAddValue(2, (int)(errorR));
    datalogAddValue(3, (int)(speedR * 10));

		displayCenteredBigTextLine(4, "%d - %d", getColorReflected(S4), getColorReflected(S3));

		if (InBetween(errorL, -1, 1) && InBetween(errorR, -1, 1) && InBetween(dErrorL, -1, 1) && InBetween(dErrorR, -1, 1))
		{
			setLEDColor(ledRed);
			break;
		}

		prev_errL = errorL;
		prev_errR = errorR;
	}
	setMotorSync(motorC, motorB, 0, 0);
}
