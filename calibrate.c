#include "Core/Core.h"

task main()
{
	//float side = L;

	//float target = getColorReflected(S3);

	//FollowLine(R, 2, 10, target);

	//delay(3000);

	setMotorBrakeMode(motorB, motorCoast);
	setMotorBrakeMode(motorC, motorCoast);

	while (true)
	{
		float diff = (getMotorEncoder(motorC) - getMotorEncoder(motorB)) / 360.0;
		diff += fabs(getMotorEncoder(motorC) / 360.0) * 0.0002;
		datalogAddValue(4, (int)(diff * 10000))
	}
}
