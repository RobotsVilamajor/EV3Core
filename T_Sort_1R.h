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

// Sortida 1 actualitzada Tenerife Veatriz

#include "Core/Core.h";

void T_Sort_1R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 4, -20);
		MoveMotorTime(motorD, 4, 40);
		delay(300);
		MoveMotor(motorD, 1, -70);
	}
  setMotorBrakeMode(motorD, motorBrake);
	waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorD, motorBrake);
  resetGyro(S2);
	delay(300);
	//Fer ajust inicial
	MoveMotorAsync(motorA, 1.2, 70);
	Recta(Bwd, 0.02, 10, false, false);

//	//Anem fins a la canasta
//	//Avancem fins humans
	MoveMotor(motorD, 2.05, -70);	//abans 2.1
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 2.4, 60);
	Turn(34, 15);
	Align(Fwd, 2);
	Recta(Fwd, 2.33, 60);

////Pujem primer pis
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotor(motorA, 1, -70);
	MoveMotor(motorD, 1.7, 70);
	setMotorBrakeMode(motorD, motorBrake);

//	//Pujem segon pis
	MoveMotor(motorA, 2.0, 70);
	MoveMotorTime (motorA, 0.2, 70);   //tope dreta 2.1
	MoveMotor(motorD, -1.7, 70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotor(motorA, 2, -70);			//1.9 i després 0.4
	MoveMotorAsync(motorA, 0.3, -40);
	MoveMotor(motorD, 2.65, 70);

	// Tornem
	MoveMotor(motorD, -0.65, 70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1.1, 20);
	Recta(Bwd, 0.7, 40, false, true);
	MoveMotor(motorD, -2, 70);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(90, 30);
	Recta(Fwd, 2.0, 60, false, false);		//2.8
	MoveMotorAsync(motorC, 1.8, -40);
	MoveMotor(motorB, 2.3, -60);

}
