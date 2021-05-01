// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#include "Core/Core.h";

void Sortida_3(bool align = false)
{
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	MoveMotor(motorA, 1.1, 70);
	MoveMotor(motorD, 3, -70);


	resetGyro(S2);
	delay(300);
	waitForButtonPress();

		// corregir rodes
	delay(250);
	Recta(Bwd, 0.08, 8);

	//anar a M11

	Recta(Fwd, 8.3, 70);

	// encaixar gadget a M11
	Recta(Fwd, 0.5, 40);

	//anem a M12

	Recta(Bwd, 0.5, 50);
	MoveMotorAsync(motorA, 0.1, 70);

	Turn(Lft, 45, 20);
	MoveMotorAsync(motorD, 2.1, -70);
	Recta(Fwd, 1.3, 70);


	// Fem Rem
	MoveMotor(motorD, 0.8, -70);
	Recta(Bwd, 0.25, 70);
	Turn(Lft, 30, 30);

	//Anem cap a M9


	MoveMotor(motorD, 3, 70);
	Turn(Rgt, 65, 30);
	Recta(Bwd, 2, 50);
	Turn(Rgt, 15, 30);
	Recta(Bwd, 1.1, 50);

	// Fem M9

	MoveMotorTime(motorA, 0.7, 70);
	MoveMotor(motorD, 3, -70); // agafar la vida
	Recta(Fwd, 0.5, 70); //comprovar que no falla 0.7
	MoveMotorAsync(motorD, 4, 50);
	Recta(Fwd, 1, 70);






	//Coloquem
	MoveMotorAsync(motorD, -0.25, 30);
	Recta(Fwd, 0.20, 50);
	Recta(Bwd, 0.40, 80);	// aqui ja hem girat i collcat les rodes

	//Anem a fer la M(12)(posar la roda rara en el cercle)
	Recta(Fwd, 0.40, 50);
	Turn(Lft, 45, 50);
	MoveMotorAsync(motorD, 0.25, 50);
	Recta(Fwd, 0.10, 50);

	//Fem M12
	MoveMotorAsync(motorD, -0.25, 50);// aqui ja ens hem colocat i agafem la roda
	Turn(Lft, 45, 50); // la posem en el cercle
	MoveMotorAsync(motorD, 0.25, 50);
	Recta(Fwd, 0.10, 50);

	//Ens recoloquem
	Recta(Bwd, 0.60, 80); // aqui toca a la paret

	//Fem M14
	Recta(Fwd, 0.10, 50);
	Turn(Lft, 90, 50);	// va a agafar la M14 (porcions de salut)
	MoveMotorAsync(motorA, 0.25, 50);
	Recta (Fwd, 1.2, 50);

	//Tornem a la base
	MoveMotorAsync(motorD, 0.5, 50);
	MoveMotor(motorA, 0.5, 50);
	Recta (Fwd, 5.8, 50);
}
