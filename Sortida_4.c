#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// F - Forward; B - Backward. Recta direction definitions
// L - Left; R - Right. Turns direction definitions

// From max side to middle: 1.1
// Recta(Direction, Count, Power)
// Turn(Direction, Angle, Power)
// Align(Direction, Time)
// MoveMotor(Motor, Count, Power)
// MoveMotorAsync(Motor, Count, Power)

#define VEATRIZ
#include "Core/Core.h";

task main()
{
	//Fem M??
	//Align
	//MoveMotorTime(motorA, 3, -70)
	//MoveMotorTime(motorD, 4, 70)
	//MoveMotorTime(motorA, 0.05, 70)
	//MoveMotor(motorD, -6.2, 50);
	//resetGyro(S2);
	//waitForButtonPress();


	//Fer ajust inicial
	//delay(250);
	//Recta(Bwd, 0.08, 20);
	//delay(250);

	//Fem M2
	//Recta(Fwd, 6.5, 50);
	//setMotorSpeed(motorB, 50);
	//setMotorSpeed(motorC, 50);
	//delay(250);
	//setMotorSpeed(motorB, 0);
	//setMotorSpeed(motorC, 0);


	//Recta(Bwd, 1, 30);
	//MoveMotor(motorD, 2.2, 70);
	//delay(10);
	//Recta(Fwd, 0.8, 30);
	//delay(10);
	Turn(Lft, 90, 50);
	//MoveMotor(motorA, 1.1, 70);

	////Ens col�loquem a la paret
	//Recta(Bwd, 2, 50);

	//////Avan�em fins a la M14
	//Recta(Fwd, 1, 50);


	//////Fem la M14
	//MoveMotorAsync(motorA, 0.5, 20);
	//MoveMotor(motorD, 0.8, 70);
	//Recta(Fwd, 0.5, 20);
	//MoveMotor(motorD, -1, 20);
	//Recta(Bwd, 0.5, 20);
	//MoveMotorAsync(motorA, 1, 20);
	//MoveMotor(motorD, -2.5, 20);

	//////Avan�em fins a M8
	//Recta(Fwd, 2.5, 50);

	////Fem M8
	//Recta(Fwd, 1, 20);
	//Recta(Bwd, 1, 20);

	////Ens posicionem per M7
	//Turn(Lft, 45, 50);
	////Avan�em fins M7

	//Recta(Fwd, 0.5, 50);

	////Fem bailecito
	//int n = 0;
	//while(n == 0) {
	//	Recta(Fwd, 0.2, 70);
	//	Recta(Bwd, 0.2, 70);
	//	Turn(Lft, 360, 60);
	//	Turn(Rgt, 360, 60);
	//}
}
