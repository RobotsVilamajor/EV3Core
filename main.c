#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Core/Core.h"

task main()
{
	Turn(-1, 0.54, 30);

	//while (true)
	//{
	//	displayCenteredBigTextLine(4, "%.4f", getMotorEncoder(motorB) / 360.0);
	//	displayCenteredBigTextLine(6, "%.4f", getMotorEncoder(motorC) / 360.0);
	//	displayCenteredBigTextLine(8, "%.4f", (fabs(getMotorEncoder(motorB)) - fabs(getMotorEncoder(motorC))) / 360.0);
	//}
	//Recta(-1, 2, 70);

	//delay(5000);

	//float dist = 2;

	//Accelerate acc;
	//InitAcc(acc, 70, dist, 10, 5, 0.15);

	//setMotorSyncEncoder(motorB, motorC, 0, dist * 360, 5);
	//while (getMotorEncoder(motorB) / 360.0 <= dist + 0.5)
	//	datalogAddValue(0, (int)(UpdateAcc(acc, getMotorEncoder(motorB) / 360.0) * 10));
}
