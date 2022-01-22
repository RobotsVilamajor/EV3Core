#include "PID.h"
#include "Defines.h"

bool HasEnded(float errorL, float errorR, float dErrorL, float dErrorR)
{
	return InBetween(errorL, -4, 4) && InBetween(errorR, -4, 4) && InBetween(dErrorL, -1, 1) && InBetween(dErrorR, -1, 1);
}

void Align(float dir1, float time, float colorbalanceright = ALIGN_TARGET_RIGHT, float colorbalanceleft = ALIGN_TARGET_LEFT, float dir2 = dir1)
{
	//setMotorSync(motorC, motorB, 0, 12 * dir);
	setMotorspeed(motorB, dir2);
	setMotorspeed(motorC, dir2);

	while (getColorReflected(S3) < ALIGN_MIN_WHITE || getColorReflected(S4) < ALIGN_MIN_WHITE) {}

	while (getColorReflected(S3) > ALIGN_MIN_BLACK || getColorReflected(S4) > ALIGN_MIN_BLACK) {}

	setMotorSync(motorC, motorB, 0, 0);

	PID pidL, pidR;
	InitPID (pidL, PROPORTIONAL_ALIGN, INTEGRAL_ALIGN, DERIVATE_ALIGN, 0.01);
	InitPID (pidR, PROPORTIONAL_ALIGN, INTEGRAL_ALIGN, DERIVATE_ALIGN, 0.01);

	clearTimer(T1);

	//float iValL = getMotorEncoder(motorC);
	//float iValR = getMotorEncoder(motorB);

	float prev_errL = 0;
	float prev_errR = 0;
	while (time1[T1] < time * 1000)
	{
		// pidL
		float errorL = getColorReflected(S4) - colorbalanceleft;
		float speedL = UpdatePID(pidL, errorL);
		setMotorSpeed(motorC, speedL * dir2);

		// pidR
		float errorR = getColorReflected(S3) - colorbalanceright;
		float speedR = UpdatePID(pidR, errorR);
		setMotorSpeed(motorB, speedR * dir1);

		float dErrorL = errorL - prev_errL;
		float dErrorR = errorR - prev_errR;

		datalogAddValue(0, (int)(errorL));
		//datalogAddValue(0, (int)(dErrorL));
    datalogAddValue(1, (int)(speedL * 10));
    datalogAddValue(2, (int)(dErrorL));
    //datalogAddValue(2, (int)(getMotorEncoder(motorC) - iValL);

    datalogAddValue(3, (int)(errorR));
    datalogAddValue(4, (int)(speedR * 10));
    datalogAddValue(5, (int)(dErrorR));
    //datalogAddValue(5, (int)(getMotorEncoder(motorB) - iValR);

		displayCenteredBigTextLine(4, "%d - %d", getColorReflected(S4), getColorReflected(S3));

		if (HasEnded(errorL, errorR, dErrorL, dErrorR))
		{
			setLEDColor(ledOrange);
			setMotorSync(motorC, motorB, 0, 0);

			delay(50);

			// pidL
			errorL = getColorReflected(S4) - colorbalanceleft;
			dErrorL = errorL - prev_errL;

			// pidR
			errorR = getColorReflected(S3) - colorbalanceright;
			dErrorR = errorR - prev_errR;

			if (HasEnded(errorL, errorR, dErrorL, dErrorR))
			{
				setLEDColor(ledRed);
				break;
			}
		}

		prev_errL = errorL;
		prev_errR = errorR;
	}
	setMotorSync(motorC, motorB, 0, 0);
}
