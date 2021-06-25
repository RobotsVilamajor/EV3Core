#pragma config(Sensor, S2,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)

// ROBOPRO || VEATRIZ
#define ROBOPRO


#include "T_Sort_1R.h"
#include "T_Sort_1bV.h"
#include "T_Sort_2R.h"
#include "T_Sort_3R.h"

task main()
{
	waitForButtonPress();

	if (getButtonPress(buttonEnter))
	{
		// Tot sense alinear
		flushButtonMessages();
		T_Sort_1R(true);
		T_Sort_1bV();
		T_Sort_2R();
		T_Sort_3R();
	}
	if (getButtonPress(buttonLeft))
	{
		// Començar en la 2 aliniant-se
		flushButtonMessages();
		T_Sort_1bV(true);
		T_Sort_2R();
		T_Sort_3R();
	}
	if (getButtonPress(buttonUp))
	{
		// Començar en la 3 aliniant-se
		flushButtonMessages();
		T_Sort_2R(true);
		T_Sort_3R();
	}
	if (getButtonPress(buttonRight))
	{
		// des de la sortida 4 alineant-se
		flushButtonMessages();
			T_Sort_3R(true);
	}
	if (getButtonPress(buttonDown))
	{
		flushButtonMessages();
		StartCheck();
	}
}
