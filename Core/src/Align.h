#include "PID.h"
#include "Defines.h"

void Align(float dir, float time)
{
	setMotorSync(motorC, motorB, 0, 12 * dir);

	while (getColorReflected(S3) < ALIGN_MIN_WHITE || getColorReflected(S4) < ALIGN_MIN_WHITE) {}

	while (getColorReflected(S3) > ALIGN_MIN_BLACK || getColorReflected(S4) > ALIGN_MIN_BLACK) {}

	setMotorSync(motorC, motorB, 0, 0);

	PID pidL, pidR;
	InitPID (pidL, 0.2, 0, 0, 0.001);
	InitPID (pidR, 0.2, 0, 0, 0.001);

	clearTimer(T1);
	while (time1[T1] < time * 1000)
	{
		// pidL
		float errorL = getColorReflected(S4) - ALIGN_TARGET_LEFT;
		float speedL = UpdatePID (pidL, errorL);
		setMotorSpeed(motorC, speedL * dir);

		datalogAddValue(0, (int)(errorL * 10));
    datalogAddValue(1, (int)(speedL * 10));

		// pidR
		float errorR = getColorReflected(S3) - ALIGN_TARGET_RIGHT;
		float speedR = UpdatePID (pidR, errorR);
		setMotorSpeed(motorB, speedR * dir);
	}
	setMotorSync(motorC, motorB, 0, 0);
}
