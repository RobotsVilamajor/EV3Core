#pragma config(Sensor, S2,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)

// ROBOPRO || VEATRIZ
#define VEATRIZ

#include "Sortida_1V.h"
#include "Sortida_2a.h"
#include "Sortida_2bV.h"
#include "Sortida_3V.h"
#include "Sortida_4_Robopro.h"


task main()
{
	waitForButtonPress();

	if (getButtonPress(buttonEnter))
	{
		// Tot sense alinear
		flushButtonMessages();
		Sortida_1V();
		Sortida_2a();
		Sortida_2bV();
		Sortida_3V();
		Sortida_4_Robopro();
	}
	if (getButtonPress(buttonLeft))
	{
		// Començar en la 2 aliniant-se
		flushButtonMessages();
		Sortida_2a(true);
		Sortida_2bV();
		Sortida_3V();
		Sortida_4_Robopro();

	}
	if (getButtonPress(buttonUp))
	{
		// Començar en la 3 aliniant-se
		flushButtonMessages();
		Sortida_3V(true);
		Sortida_4_Robopro();
	}
	if (getButtonPress(buttonRight))
	{
		// des de la sortida 4 alineant-se
		flushButtonMessages();
		Sortida_4_Robopro(true);
	}
	if (getButtonPress(buttonDown))
	{
		flushButtonMessages();
		StartCheck();
	}
}
