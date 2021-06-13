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
		MoveMotorTime(motorA, 4, -30);
		MoveMotorTime(motorD, 4, 30);
		MoveMotorAsync(motorA, 1.2, 60);
		MoveMotor(motorD, -0.5, 40);
		MoveMotor(motorD, -2.55, 40);
	}
	waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	//Arribem fins a zona de gir
	Recta(Fwd, 1, 50, false, false);
	FollowLine(3.5, 40, Rgt, Lft, false, false);
	Recta(Fwd, 0.1, 30, false, false);
	WaitForLine(Fwd, 1, 20, Lft);
	MoveMotorAsync(motorD, 1.5, 70);
	Recta(Fwd, 0.5, 30, false, true);

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
	Recta(Bwd, 0.5, 40, false, false);
	Recta(Bwd, 0.3, 30, false, true);

	//Fem millores
	MoveMotor(motorA, 0.4, -70);
	MoveMotorAsync(motorA, 2, -70);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 0.75, 40, true, true);
	MoveMotorAsync(motorD, -0.3, 70);
	Recta(Bwd, 0.35, 10, true, true);
	setMotorBrakeMode(motorD, motorBrake);

	//Passem per sota
	MoveMotorAsync(motorA, 1.2, 70);
	MoveMotor(motorD, -1.2, 50);
	setMotorBrakeMode(motorD, motorBrake);
	FollowLine(1.6, 40, Rgt, Rgt, true, false);
	Recta(Fwd, 0.2, 40, false, false);

	Recta(Fwd, 1.2, 50, false, false);
	setMotorSpeed(motorD, 0);
	Recta(Fwd, 0.25, 50, false, true);
	//Fem bloc groc
	//MoveMotor(motorA, 1.2, 70);
	//setMotorBrakeMode(motorD, motorBrake);
	//Recta(Fwd, 1, 30, true, true);
	//setMotorBrakeMode(motorC, motorBrake);
	//setMotorBrakeMode(motorB, motorBrake);
	//MoveMotor(motorD, 0.5, 70);

	////Fem blocs
	//MoveMotorAsync(motorD, -0.5, 70);
	//MoveMotor(motorA, -1.2, 50);
	//setMotorBrakeMode(motorD, motorBrake);
	//Recta(Fwd, 0.1, 30, false, true);
	//delay(2500);


	//Anem a ballar
	//Recta(Bwd, 0.7, 50);
	//Turn(130, 60);
	//MoveMotorAsync(motorA, -1.2, 70);
	//Recta(Fwd, 1.5, 60, false, false);

	////Ballem
	//while(true)
	//{
	//Recta(Bwd, 0.2, 50, false, false);
	//Recta(Fwd, 0.2, 50, false, false);
	//}









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
