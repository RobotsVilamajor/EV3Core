#include "Defines.h"

void FollowLine(float side, float distance, float speed, float target = 50)
{
	PID pid;
	InitPID(pid, 0.3, 0, 0.03);

	while (fabs(getMotorEncoder(motorB) / 360.0) < distance)
	{
		float error = getColorReflected(side == R ? S3 : S4) - target;
		float turnRate = UpdatePID(pid, error);

		float diff = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / (360.0);
		//datalogAddValue(4, (int)(diff * 10000));
		//datalogAddValue(0, (int)(error));
		//datalogAddValue(1, (int)(turnRate));
		//datalogAddValue(2, (int)(pid.integ * pid.k_i));

		setMotorSpeed(motorB, -(speed + turnRate * side));
		setMotorSpeed(motorC, -(speed - turnRate * side));

		//setMotorSync(motorB, motorC, turnRate, speed * dir);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
}
