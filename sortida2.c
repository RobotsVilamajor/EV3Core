#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)

#include "Core/Core.h"

task main()
{
	Recta(1, 4, 70);

	Recta(-1, 4, 70);
	setMotorTarget(motorA, 1, 20);
	Recta(1, 1, 70);
	setMotorTarget(motorA,-0.2, 20);
	Recta(1, 2, 70);

	Recta(-1, 4, 70);
	setMotorTarget(motorA,0.2, 20);

	Recta(1, 7, 70);
}
