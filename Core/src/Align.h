#include "PID.h"

void Align (float dir, float time)
{
	setMotorSync(motorC, motorB, 0, 10*dir);

	while (getColorReflected(S3) < 70 || getColorReflected(S4) < 70);

	while (getColorReflected(S3) > 30 || getColorReflected(S4) > 30);

	setMotorSync(motorC, motorB, 0, 0);

	PID pidL, pidR;
	InitPID (pidL, 0.2, 0, 0, 0.001);
	InitPID (pidR, 0.2, 0, 0, 0.001);

	clearTimer(T1);
	while (time1[T1] < time * 1000)
	{
		// pidL
		float errorL = getColorReflected(S4) - 50;
		float speedL = UpdatePID (pidL, errorL);
		setMotorSpeed(motorC, speedL * dir);

		datalogAddValue(0, (int)(errorL * 10));
    datalogAddValue(1, (int)(speedL * 10));

		// pidR
		float errorR = getColorReflected(S3) - 50;
		float speedR = UpdatePID (pidR, errorR);
		setMotorSpeed(motorB, speedR * dir);
	}
	setMotorSync(motorC, motorB, 0, 0);
}
