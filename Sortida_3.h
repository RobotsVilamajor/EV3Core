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
	if (align = true){
		//Align
	MoveMotorTime(motorA, 3, -70);
	MoveMotorTime(motorD, 4, 70);
	delay(200);
	MoveMotor(motorA, 0.8, 70); //1.1
	MoveMotor(motorD, 2.5, -70);
	}

	waitForButtonPress();
	flushButtonMessages();

		// corregir rodes
	delay(250);
	Recta(Bwd, 0.08, 8);

	//anar a M11
	MoveMotor(motorA, 0.3, 70);
	Recta(Fwd, 8.3, 70);

	//anem a M12

	MoveMotorAsync(motorA, 0.1, 70);
	Turn(Rgt, 16, 8);
	MoveMotorAsync(motorA, 0.3, -70);
	MoveMotor(motorD, 1.35, -70);
	Recta(Bwd, 1.6, 50);
	MoveMotorAsync(motorA, 0.4, 70);
	Turn(Lft, 15, 8);
	MoveMotorAsync(motorD, 0.6, 70);
	Recta(Bwd, 0.8, 30);

	//Preparem rodes
	MoveMotor(motorA, 0.5, 70);
	MoveMotorTime(motorA, 0.2, 70);
	MoveMotor(motorD, 2.7, -70);
	Recta(Fwd, 0.4, 70);
	setMotorSpeed (motorB, 9);
	setMotorSpeed (motorC, -9);
	delay(500);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);

	// Girem rodes
	MoveMotorAsync(motorD, 6, 70);
	Recta(Fwd, 1, 30);

	// Anem pel rem
	setMotorSpeed (motorB, -8);
	setMotorSpeed (motorC, 8);
	delay(400);
	setMotorSpeed (motorB, 0);
	setMotorSpeed (motorC, 0);
	Recta(Fwd, 0.9, 70);
	MoveMotor(motorD, 4.5, -70);
	Recta(Bwd, 0.5, 70);
	Turn(Lft, 10, 10);

	// tornem
	MoveMotor(motorD, 2, 70);
	MoveMotorAsync(motorD, 2, -20);
	Turn(Rgt, 10, 10);
	Recta(Bwd, 1.5, 20);
	MoveMotorAsync(motorD, 4, 70);
	MoveMotor(motorA, 1.6, -70);
	MoveMotorTime(motorA, 0.2, -70);
	Recta(Bwd, 8, 70);

	// posicionem pala. Preparar pala sortida 4
	MoveMotorAsync(motorA, 0.9, 70);
	MoveMotor(motorD, 5.8, -70);

}
