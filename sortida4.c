#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortia rampa; Missi� a fer: M1, M11 i M13.
//MotorA = Vertical. MotorD = Horitzontal.

#include "Core/Core.h"

task main()
{
//Primera accelerada fins al cercle Vermell: +__ Punts
	Recta (1, -, 40)
	Recta (-1, -, 10)
	Gir ()

//Avan�ar fins al cercle marr� per deixar bloc marr� i estructura innovadora: +__ Punts
	Recta (1, -, 40)



}
