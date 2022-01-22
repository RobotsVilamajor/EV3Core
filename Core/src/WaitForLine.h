#include "Defines.h"

void WaitForLine(float dir, float distance, float speed, float side)
{
	setMotorSync(motorB, motorC, 0, speed * dir);

	waitUntil(getColorReflected(side == Lft ? S4 : S3) > LINE_WHITE_MIN || fabs(getMotorEncoder(motorB) / 360.0) >= distance);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}

void WaitForBlack(float dir, float distance, float speed, float side)
{
	setMotorSync(motorB, motorC, 0, speed * dir);

	waitUntil(getColorReflected(side == Lft ? S4 : S3) < LINE_BLACK_MIN || fabs(getMotorEncoder(motorB) / 360.0) >= distance);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}

void WaitForLine2(float dir, float distance, float speed, float side, float lfturn = 1, float rgturn = 1)
{
		setMotorSpeed(motorC, speed * dir * lfturn);
		setMotorSpeed(motorB, speed * dir * rgturn);

	waitUntil(getColorReflected(side == Lft ? S4 : S3) > LINE_WHITE_MIN || fabs(getMotorEncoder(motorB) / 360.0) >= distance);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}

void WaitForBlack2(float dir, float distance, float speed, float side, float lfturn = 1, float rgturn = 1)
{
	setMotorSync(motorB, motorC, 0, speed * dir);

	waitUntil(getColorReflected(side == Lft ? S4 : S3) < LINE_BLACK_MIN || fabs(getMotorEncoder(motorB) / 360.0) >= distance);

	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}
