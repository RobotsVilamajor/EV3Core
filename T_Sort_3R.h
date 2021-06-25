// Motors:
//	Rigth: motorB
//	Left: motorC

// Wall:
// 	Vertical: motorD
//	Horizontal: motorA

// Fwd - Forward; Bwd - Backward. Recta direction definitions
// Lft - Left; Rgt - Right. Turns direction definitions

// From max side to middle: 1.1
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#include "Core/Core.h"

void T_Sort_3R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 3, -20);
		MoveMotorTime(motorD, 3, 60);
		MoveMotorAsync(motorA, 1.2, 60);
		MoveMotor(motorD, -3.05, 70);
	}
	setMotorBrakeMode(motorD, motorBrake);
	setMotorBrakeMode(motorA, motorBrake);
	waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	//Arribem fins a zona de gir
	Recta(Fwd, 1, 50, false, false);
	FollowLine(3.5, 40, Rgt, Lft, false, false);
	Recta(Fwd, 0.1, 30, false, false);
	WaitForLine(Fwd, 3, 20, Lft);
	MoveMotor(motorD, 1.55, 70);		//1.5
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 0.45, 30);   //acabar d'ajustar el retorn enrere

	//Girem
	MoveMotorAsync(motorA, 1.2, 70);
	while(getGyroDegrees(S2) < 24)
	{
	setMotorSpeed(motorB, -20);
	setMotorSpeed(motorC, 20);
	}
	setMotorSpeed(motorB, 20);
	setMotorSpeed(motorC, 20);
	delay(100);
	while(getGyroDegrees(S2) < 69)
	{
	setMotorSpeed(motorB, -20);
	setMotorSpeed(motorC, 20);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

	// Fem tope enrere

	Recta(Bwd, 0.5, 50, false, false);
	Recta(Bwd, 0.3, 40, false, true);
	resetGyro(S2);
	delay(300);

	//Fem millores
	//MoveMotor(motorA, 0.4, -70);
	MoveMotorAsync(motorA, 1.2, -70);			//2.4 en total. Fem tope esquerra
	Recta(Fwd, 0.82, 40, true, true);  //0.8
	MoveMotor(motorA, 1.2, -70);			//2.4 en total. Fem tope esquerra
	//MoveMotorTime (motorA,0.1,-70); ///Fem tope esquerra
	MoveMotorAsync(motorD, -0.35, 70);		//0.3
	Recta(Bwd, 0.42, 10, true, true);			//0.4
	setMotorBrakeMode(motorD, motorBrake);

	//Passem per sota
	MoveMotorAsync(motorA, 1.2, 70);
	MoveMotor(motorD, 1.2, -70);			// Intento arribar abaix de tot. tope abaix
	setMotorBrakeMode(motorD, motorBrake);
	FollowLine(1.6, 40, Rgt, Rgt, true, false);
	Recta(Fwd, 0.2, 20, false, false);

	MoveMotorAsync(motorA, 0.3, -40);		// això és nou 0.9
	Recta(Fwd, 1.2, 40, false, false);
	//setMotorSpeed(motorD, 0);
	MoveMotor(motorD, 0.05, -10);		//1.5
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 0.3, 20, false, true);   // 0.25


	//Fem bloc groc

	MoveMotorAsync(motorA, 1, 70);		//1.1
	Recta(Bwd, 0.3, 40);
	//Turn(-14,15);
	//MoveMotorTime(motorA, 0.2, 70);   // Fem tope
	//Turn(-5,10);
	MoveMotorAsync(motorD, 1, 70);
	delay(100);

	//Anem a ballar
	Turn(50,15);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync (motorA, 1.5, -50);		//1
	Recta(Fwd, 1.6, 60, false, false);

	//Ballem
	while(true)
	{
	Recta(Fwd, 0.3, 50, false, false);
	Recta(Bwd, 0.3, 50, false, false);
	}









 // waitForButtonPress();
	//flushButtonMessages();
	//setMotorBrakeMode(motorA, motorBrake);
 // setMotorBrakeMode(motorD, motorBrake);
	//resetGyro(S2);
	//delay(300);

	////Començem sortida
	//Recta(Fwd, 1, 50, true, true);
	//FollowLine(4, 30, Rgt, Rgt, true, true);
	//setMotorSync(motorB, motorC, 0, -30);
	//waitUntil(getColorReflected(S4) > LINE_WHITE_MIN);
	//setMotorSpeed(motorB, 0);
	//setMotorSpeed(motorC, 0);
	//Recta(Fwd, 0.2, 30, true, true);
	//Turn(65, 50);
	//Recta(Bwd, 0.5, 50, false, false);
	//Recta(Bwd, 0.5, 30, true, true);
	//MoveMotor(motorD, 1.5, 40);
	//MoveMotor(motorA, 1.2, -40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//delay(300);
	//Recta(Fwd, 0.7, 40, true, true);
	//MoveMotor(motorD, -0.3, 40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//delay(300);
	//Recta(Bwd, 0.3, 15, true, true);
	//MoveMotor(motorA, 0.8, 40);
	//MoveMotor(motorD, -1.2, 40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//delay(300);
	//FollowLine(1.8, 30, Rgt, Rgt, true, true);
	//MoveMotor(motorA, 1.6, 40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//delay(300);
	//Recta(Fwd, 1, 30, true, true);
	//MoveMotor(motorA, -1.7, 40);
	//MoveMotor(motorD, -0.1, 40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//delay(300);
	//Recta(Fwd, 0.5, 30, true, true);
	//MoveMotor(motorD, 1, 40);
	//setMotorBrakeMode(motorA, motorBrake);
	//setMotorBrakeMode(motorD, motorBrake);
	//Recta(Bwd, 0.5, 30, true, true);
	//Turn(40, 30);
	//Recta(Fwd, 1.5, 50, false, true);
	//delay(300);
}
