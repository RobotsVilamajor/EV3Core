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

// Ajustada per Veatriz

#include "Core/Core.h";

void Sortida_3V(bool align = false)
{
	if (align == true){
		//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotor(motorA, 0.8, 70); //1.1
	MoveMotor(motorD, 2.5, -70);
	}
	flushButtonMessages();
	waitForButtonPress();
	flushButtonMessages();

		// corregir rodes
	delay(250);
	Recta(Bwd, 0.02, 10, false, false);

	//agafem vida
	MoveMotorAsync(motorA, 0.3, 20);  	//abans 0.6
	Recta(Fwd, 6.5, 60, true, false);
	MoveMotorAsync(motorD, 1.6, -70);
	Recta(Fwd, 1.5, 20, false, true);
	MoveMotorAsync(motorD, 1.5, 70);

	//// anem rodes
	Turn(Rgt, 17, 10);
	Recta(Bwd, 1.6, 60);
	MoveMotorAsync(motorA, 0.6, 70);
	Turn(Lft, 16, 10);
	MoveMotorTime(motorA, 0.2, 70);
	Recta(Bwd, 0.5, 30);

	//// Preparem rodes
	//MoveMotorTime(motorA, 0.3, 70);
	MoveMotor(motorD, 3.5, -70);
	Recta(Fwd, 0.5, 50, true, false);
	setMotorSpeed (motorB, 10);
	setMotorSpeed (motorC, -10);
	delay(450);
	setMotorSpeed (motorB, 10);
	setMotorSpeed (motorC, 10);
	delay(200);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);

	// Girem rodes
	MoveMotorAsync(motorD, 3.4, 70);
	Recta(Fwd, 1.8, 20);			//abans 2

	// Tornem
	// arrosseguem rodes

	setMotorSpeed (motorB, -20);
	setMotorSpeed (motorC, 20);
	delay(300);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);
	MoveMotorAsync(motorD, 3, -70);
	Recta(Bwd, 1, 40);
	MoveMotorAsync(motorD, 3.5, 70);
	MoveMotor(motorA, 1.6, -70);
	MoveMotorTime(motorA, 0.2, -70);
	Recta(Bwd, 8, 70);

	// posicionem pala. Preparar pala sortida 4
	MoveMotorAsync(motorA, 0.85, 70);
	MoveMotor(motorD, 4, -70);			//3.95




	//MoveMotorAsync(motorD, 5.5, -70);
	//Recta(Fwd, 0.7, 70);
	//Recta(Bwd, 0.3, 70);
	//Turn(Lft, 13, 20);


	////////// tornem

	//////Rodes a dins
	//MoveMotor(motorD, 2, 70);
	//MoveMotorAsync(motorD, 2, -20);
	//Turn(Rgt, 15, 10);
	//Recta(Bwd, 0.5, 20);
	//MoveMotorAsync(motorD, 0.5, -30);
	//Recta(Bwd, 1.5, 50);

	//MoveMotorAsync(motorD, 4, 70);
	//MoveMotor(motorA, 1.6, -70);
	//MoveMotorTime(motorA, 0.2, -70);
	//Recta(Bwd, 7.5, 70);

	// posicionem pala. Preparar pala sortida 4
	//MoveMotorAsync(motorA, 0.9, 70);
	//MoveMotor(motorD, 5.8, -70);


	// agafem endevant

	//MoveMotorAsync(motorA, 0.6, 70);  	//abans 0.3
	//Recta(Fwd, 7.3, 70);
	//MoveMotorAsync(motorA, 0.3, -70); //Reposicionem pala
	//MoveMotor(motorD, 1.65, -70);
	//Recta(Fwd, 1, 60);


	// Sortida com abans

	//Recta(Fwd, 8.3, 70);  //8.3

	////anem a M12

	//MoveMotorAsync(motorA, 0.7, -70);
	//Turn(Rgt, 17, 10);
	//MoveMotor(motorD, 1.5, -70);		//1.35 abans
	//Recta(Bwd, 1.6, 50);
	//MoveMotorAsync(motorD, 0.7, 70);
	//MoveMotor(motorA, 0.8, 70);
	//Turn(Lft, 16, 8);
	//Recta(Bwd, 0.8, 30);

	//Preparem rodes
	//MoveMotor(motorA, 0.3, 70);
	//MoveMotorTime(motorA, 0.2, 70);
	//MoveMotor(motorD, 2.5, -70);			//vaig 0.2 amunt
	//Recta(Fwd, 0.6, 70);
	//setMotorSpeed (motorB, 9);
	//setMotorSpeed (motorC, -9);
	//delay(500);
	//setMotorSpeed (motorB, 0);
	//setMotorSpeed (motorC, 0);

}
