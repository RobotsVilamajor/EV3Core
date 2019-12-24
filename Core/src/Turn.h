#ifndef _TURN
#define _TURN

#include "Accelerate.h"

void AdjustWheel(float target, tMotor m)
{
	float lError = getMotorEncoder(m) - target;
	if (lError != 0)
	{
		float dir = 0;
		if (lError < 0)
			dir = -1;
		else
			dir = 1;

		setMotorSpeed(m, -6 * dir);
		waitUntil((getMotorEncoder(m) / 360.0 - target) * dir < 0);
		setMotorSpeed(m, 0);
		delay(10);
	}
}

void Turn(float dir, float angle, float speed)
{
	if (dir < 0)
		dir = -1;
	else
		dir = 1;

	Accelerate acc;
	InitAcc(acc, speed, angle, 10, 10, 0);

	while (fabs(getMotorEncoder(motorB) / 360.0) < angle || fabs(getMotorEncoder(motorC) / 360.0) < angle)
	{
		float c_speed = UpdateAcc(acc, fabs(getMotorEncoder(motorC)) / 360.0);

		setMotorSpeed(motorB, -c_speed * dir);
		setMotorSpeed(motorC, c_speed * dir);
	}

	for (int i = 0; i < 100; i++)
	{
		displayCenteredBigTextLine(4, "%.4f", getMotorEncoder(motorB) / 360.0);
		displayCenteredBigTextLine(6, "%.4f", getMotorEncoder(motorC) / 360.0);
		displayCenteredBigTextLine(8, "%.4f", (fabs(getMotorEncoder(motorB)) - fabs(getMotorEncoder(motorC))) / 360.0);

		AdjustWheel(angle, motorB);
		AdjustWheel(-angle, motorC);
	}

	setMotorSync(motorB, motorC, 0, 0);

}

//void Turn(float dir, float angle, float speed)
//{
//	// Constrain the direction to {-1, 1}
//	if (dir < 0)
//		dir = -1;
//	else
//		dir = 1;

//	PID lPID;
//	PID rPID;
//	InitPID(lPID, 200, 50, 10);
//	InitPID(rPID, 200, 50, 10);

//	bool finished = false;

//	while (!finished)
//	{
//		float lError = -(getMotorEncoder(motorB) / 360.0 - angle);
//		float c_lSpeed = UpdatePID(lPID, lError);


//		if (c_lSpeed > speed)
//			c_lSpeed = speed;
//		else if (c_lSpeed < -speed)
//			c_lSpeed = -speed;

//		setMotorSpeed(motorB, c_lSpeed * dir);


//		float rError = -(getMotorEncoder(motorC) / 360.0 + angle);
//		float c_rSpeed = UpdatePID(rPID, rError);

//		if (c_lSpeed > speed)
//			c_lSpeed = speed;
//		else if (c_lSpeed < -speed)
//			c_lSpeed = -speed;

//		setMotorSpeed(motorC, c_rSpeed * dir);

//		if (fabs(c_lSpeed) < 5 && fabs(c_rSpeed) < 5)
//			finished = true;

//		//displayCenteredBigTextLine(2, "%.3f - %.3f", lError, rError);
//		//displayCenteredBigTextLine(4, "%.3f - %.3f", c_lSpeed, c_rSpeed);
//		datalogAddValue(0, (int)(lError * 1000));
//		datalogAddValue(1, (int)(c_lSpeed * 100));
//	}

//	for (int i = 0; i < 100; i++)
//	{
//		AdjustWheel(angle, motorB);
//		AdjustWheel(-angle, motorC);
//	}

//	setMotorSync(motorB, motorC, 0, 0);
//}

#endif
