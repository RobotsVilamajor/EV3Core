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
#include "Core/Core.h"

// Sortida 1 actualitzada Tenerife Veatriz

void T_Sort_2R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		//aling
		MoveMotorTime(motorA, 3, -25);
		MoveMotorTime(motorD, 3, 50);
		delay(100);
		MoveMotor(motorA, 1.85, 70);		//2.05
		MoveMotor(motorD, 1.6, -70);	 //2.15
		setMotorBrakeMode(motorD, motorBrake);
		}
	setMotorBrakeMode(motorD, motorBrake);
  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	// Fer comptapassos
	Recta(Fwd, 4.7, 70, true, false);
	Recta(Fwd, 1.3, 45, false, false);   //speed = 35
	setMotorSpeed(motorB, -12);
	setMotorSpeed(motorC, -7);
	delay(500);
	//setMotorSpeed(motorB, 0);
	//setMotorSpeed(motorC, 0);

		//enganxar-se a la paret
	setMotorSpeed(motorB, -30);
	setMotorSpeed(motorC, 30);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//tornem a fer tope
	setMotorSpeed(motorB, -8);
	setMotorSpeed(motorC, -8);
	delay(300);
	//setMotorSpeed(motorB, 0);
	//setMotorSpeed(motorC, 0);

	//anar a rodes
	MoveMotor(motorA, 0.9, -70);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	MoveMotor(motorD, 1.45, -70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1, -25);
	Recta(Fwd, 0.7, 50);		//

	////girar roda blava
	//MoveMotorAsync(motorD, 1.2, 40);
	//Recta(Fwd, 0.4, 20, true, false);
	//setMotorBrakeMode(motorD, motorBrake);
	//Recta(Fwd, 0.5, 30, false, false);		//1

	//girar roda blava
	MoveMotorAsync(motorD, 1.2, 50);
	Recta(Fwd, 0.5, 30, true, false);
	MoveMotorAsync(motorD, 0.5, -40);
	Recta(Fwd, 0.4, 40, false, true);
	MoveMotor(motorD, 0.5, 50);
	setMotorBrakeMode(motorD, motorBrake);

	//// Fer "rem"
	if (getColorReflected(S3)<65 && getColorReflected(S3)> 10)
	{
		while(getColorReflected(S3)<65 )
		{
			setMotorSpeed(motorB, -15);
			setMotorSpeed(motorC, 15);
		}
	}
	if (getColorReflected(S3)>65 )
	{
		while(getColorReflected(S3)>40 )
		{
			setMotorSpeed(motorB, -15);
			setMotorSpeed(motorC, 15);
		}
	}
	MoveMotorAsync(motorA, 1.45, 20);			//abans 1.4
	FollowLine(1, 40, Rgt, Lft, false, false);
	Recta(Fwd, 0.1, 30, false, false);
	WaitForLine(Fwd, 3, 15, Lft);		//20
	WaitForBlack(Fwd, 3, 7, Lft);		//10
	Recta(Bwd, 0.02, 20);			// Per corregir quan calibrem
	MoveMotor(motorD, 1.2, -30);			//1.2
	//setMotorBrakeMode(motorD, motorBrake);


	//// Estirem
	MoveMotorAsync(motorA, 0.6, 20);
	Recta(Bwd, 0.65, 30);
	MoveMotorAsync(motorD, 0.1, -10);
	MoveMotor(motorA, 1.4, -70);		//1.2

	//sortir de "rem"
	MoveMotor(motorD, 0.9, 70);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.1, 15, false, false);
	MoveMotorAsync(motorA, 0.3, -30);	//0.5
	MoveMotor(motorD, 0.6, -70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorTime(motorA, 0.2, -70);
	Recta(Bwd, 0.85, 60);		//0.9

	////anar a l'altre secció
	MoveMotor(motorD, 1.6, 70);	//1.8
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 0.05, 30, true, false);
	MoveMotorAsync(motorA, 1.1, 40);
	FollowLine(1.3, 40, Rgt, Lft, false, false);   //1.4
	WaitForLine(Fwd, 3, 15, Lft);
	Recta(Bwd, 0.07, 20, false, true);

	Turn (90, 30);
	Align(Bwd, 4);
	resetGyro(S2);
	delay(300);
	Recta(Fwd, 2.5, 60);

	//  ninu
	MoveMotor(motorD, 1.5, -70);		//1.7
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1, -45);  //0.8
	Recta(Bwd, 1, 50);
	Recta(Fwd, 0.01 , 15);
	MoveMotorAsync (motorD, 0.3, -70); //0.65
	delay(200);
	Recta(Fwd, 0.2 , 15);
	//Turn(0,10);
	//setMotorSpeed(motorD, 0);

	//	Anar cap a palanca
	MoveMotor(motorD, 2, 70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1.2, 30);
	Recta(Fwd, 2.4, 50);		//2.3

	// Fer palanca
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotorTime(motorA, 0.7, 40);   //1;35
	MoveMotor(motorD, 2.1, -70);
	MoveMotor(motorD, 1.3, 70);
	setMotorBrakeMode(motorD, motorBrake);

	////	Agafar mòvil
	MoveMotor(motorD, 0.2, 70);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(46,20);			//20,10
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotorTime(motorA, 0.2, 70);	//Fem tope
	MoveMotor(motorA, 0.1, -70);		//0.3
	Recta (Fwd, 0.3, 20, false, true);
	MoveMotor(motorD, 0.6, -70);			// Ho divideixo en dos
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1.2, -70);   //1.3 en total ... abans 1
	delay(400);
	Recta (Fwd, 0.4, 20, false, true);	//+0.05
	MoveMotor(motorD, 0.7, -70);
	setMotorBrakeMode(motorD, motorBrake);

	//// Tornem 2

	//Tornem
	MoveMotorAsync(motorA, 1.2, 10);
	Recta(Bwd, 1.25, 60);
	Turn(89, 20);
	MoveMotorTime(motorA, 0.2, 70);

	//// aixequem pala per esquivar i marxem
	MoveMotor(motorD, 3.2, 70);  //2.3. Fem tope adalt
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 5.6, 60);
	MoveMotor(motorD, 2.8, -70);		//3.05
	setMotorBrakeMode(motorD, motorBrake);
	Turn(135,20);


	////// Recuperem mòbil i a base
	////MoveMotorAsync(motorD, 3.05, -70);
	////Recta(Bwd, 0.4, 20, false, true);  //0.4 true, true
	////setMotorBrakeMode(motorD, motorBrake);
	////Turn(135,20);

	// aliniem pala
	MoveMotorAsync(motorA, -1.3, 50);
	Recta(Fwd, 2.8, 60, false, false);			//4.5
	MoveMotorAsync(motorC, 2.5, -60);
	MoveMotor(motorB, 1.9, -40);
	MoveMotor(motorD, 0.25, -70);		//3.05
	setMotorBrakeMode(motorD, motorBrake);

}
