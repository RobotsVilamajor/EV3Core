#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//Sortida Grua; Missions: M2, M12; Gadget 2
// MotorA = Vertical. MotorD = Horitzontal.

#include "Core/Core.h"

task main()
{
	//Avancem i deixem pessa blanca (M12)
	Recta(1, 4, 70);

	//Tirem enrrere i apartem pala
	Recta(-1, 2, 70);
	MoveMotor(motorD, 1, 20);;

	//Avancem i movem el cub petit fins el cercle blau (M2: Part 1)
	Recta(1, 3, 70);

	//Tirem enrrere i baixem grua (M2: Part 2)
	Recta(-1, 2, 70);
	MoveMotor(motorD, 0.2, 20);
	MoveMotor(motorA, 1, 20);

	//Tornem a casa
	Recta(-1, 4, 70);
	Turn (1, 90, 70);
	Recta(-1, 2, 70);
}
