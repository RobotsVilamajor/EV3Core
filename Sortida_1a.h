// F - Forward; B - Backward. Recta direction definitions
// L - Left; R - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

//Colocaci�: Pala m�xim dreta i la part dreta del robot a la segona linea fosca comen�ant des de la esquerra

#include "Core/Core.h";

void Sortida_1a(bool align = false)
{
	resetGyro(S2);
	waitForButtonPress();

	//Fer ajust inicial
	delay(250);
	Recta(Bwd, 0.08, 20);
	delay(250);

	//Avan�em fins a la petanca
	Recta(Fwd, 1.7, 50);

	//Ens coloquem per deixar els blocs
	Turn(Rgt, 20, 75);
	Recta(Fwd, 0.5, 75);
	MoveMotor(motorA, 1.2, 100);

	//Coloquem els cubs
	Recta(Fwd, 0.25, 50);

	//Tornem a base i coloquem pala
	Recta(Bwd, 2.4, 100);
	delay(500);
	MoveMotorAsync(motorA, -1.2, 100);

}
