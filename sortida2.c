#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortida Grua; Missions: M2, M12; Gadget 2
// MotorA = Vertical. MotorD = Horitzontal.

#include "Core/Core.h"

task main()
{
	//resetMotorEncoder(motorD) = motorD;
	//resetMotorEncoder(motorA) = motorA;

	//Avancem i deixem pessa blanca (M12)
	Recta(1, 4, 70);

	//Tirem enrrere i apartem pala
	Recta(-1, 2, 70);
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, 1*360, 40);

	//Avancem i movem el cub petit fins el cercle blau (M2: Part 1)
	Recta(1, 3, 70);

	//Tirem enrrere i baixem grua (M2: Part 2)
	Recta(-1, 2, 70);
	resetMotorEncoder(motorD);
	setMotorTarget(motorD, 0.2*360, 20);
	resetMotorEncoder(motorA);
	setMotorTarget(motorA, 1*360, 20);

	//Tornem a casa
	Recta(-1, 4, 70);
	Turn (1, 90, 70);
	Recta(-1, 2, 70);
}
