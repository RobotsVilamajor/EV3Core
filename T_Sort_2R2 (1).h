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

void T_Sort_2R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		//aling
		MoveMotorTime(motorA, 3, -10);
		MoveMotorTime(motorD, 4, 40);
		delay(100);
		MoveMotor(motorA, 1.85, 50);		//2.05
		MoveMotor(motorD, 1.6, -40);	 //2.15
		setMotorBrakeMode(motorD, motorBrake);
		}

  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);

	// Fer comptapassos
	Recta(Fwd, 4.7, 70, true, false);
	Recta(Fwd, 1.3, 35, false, false);
	setMotorSpeed(motorB, -15);
	setMotorSpeed(motorC, -8);
	delay(1000);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//enganxar-se a la paret
	setMotorSpeed(motorB, -25);
	setMotorSpeed(motorC, 25);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//tornem a fer tope
	setMotorSpeed(motorB, -8);
	setMotorSpeed(motorC, -8);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//anar a rodes
	//Recta(Bwd, 0.2, 40);
	MoveMotor(motorA, 0.9, -70);
	MoveMotor(motorD, 1.45, -70);	// 0.9
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1, -25);		//1.2
	Recta(Fwd, 0.7, 50);		//

	//girar roda blava
	MoveMotorAsync(motorD, 1.2, 40);
	Recta(Fwd, 0.4, 20, true, false);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 1, 30, false, true);
	Turn(0, 30);

	// Fer "rem"
	MoveMotorAsync(motorA, 0.8, 70);  //0.7
	Recta(Fwd, 1, 20);
	MoveMotor(motorD, -1.2, 40);
	setMotorBrakeMode(motorD, motorBrake);

	MoveMotorAsync(motorA, 1, 15);		//1.1
	Recta(Bwd, 0.7, 18);
	MoveMotor(motorA, 1.6, -50);
	Turn(0, 40);

	//sortir de "rem"
	MoveMotor(motorD, 1, 40);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.1, 40);
	MoveMotor(motorD, 0.7, -40);  //1
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 1.1, 40);

	//anar a l'altre secció

	MoveMotor(motorD, 2.2, 40);	//2.5
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1.1, 40);
	Recta(Fwd, 1.8, 40);  // amb Leo 1.7
	Turn (89, 20);//dona problemes.
	Recta(Fwd, 2, 40);
	WaitForLine(Fwd, 1, 20, Lft);
	Align(Fwd, 4);
	resetGyro(S2);
	delay(300);

	//  ninu
	MoveMotor(motorD, 1.8, -70);		//2
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 0.8, -40);
	Recta(Bwd, 1.3, 40);
	MoveMotorAsync (motorD, 0.8, -70); //0.65
	Recta(Fwd, 0.5 , 20);
	setMotorSpeed(motorD, 0);
	Turn(0,10);

	//	Anar cap a palanca
	MoveMotor(motorD, 2.2, 70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotorAsync(motorA, 1, 30);
	Recta(Fwd, 2.25, 50);
	Recta(Bwd, 0.3, 40);

	// Fer palanca
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotorTime(motorA, 1, 30);
	MoveMotor(motorD, 2.1, -70);
	MoveMotor(motorD, 1.3, 70);
	setMotorBrakeMode(motorD, motorBrake);

	//	Agafar mòvil
	Turn(20,10);
	MoveMotor(motorD, 0.45, 70);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(45,10);
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotorTime(motorA, 0.6, 70);
	Recta(Fwd, 0.65, 40);
	MoveMotor(motorD, 1, -70);
	setMotorBrakeMode(motorD, motorBrake);

	// Tornem
	// Sortim enrere
	MoveMotorAsync (motorA, 1.6, -30);
	Recta(Bwd, 0.6, 40);
	Turn(0,10);
	Recta(Bwd, 0.8, 40);
	Align(Bwd, 4);
	resetGyro(S2);
	delay(300);

	// encarem recta llarga
	MoveMotorAsync(motorA, 0.4, 30);
	Recta(Fwd, 0.7, 40);
	Turn(90,20);

	// Fem recta llarga
	Recta(Fwd, 0.2, 40);		//0.85
	MoveMotor (motorA, 1, 60);  //no pot ser async
	MoveMotorTime(motorA, 0.2, 70);
	MoveMotor(motorD, 2.7, 70);  //2.3
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 6, 60);

	// Recuperem mòvil i entrem a base
	Recta(Bwd, 0.4, 40);
	MoveMotor(motorD, 2.5, -70);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(135,10);

	// aliniem pala
	Recta(Fwd, 4.5, 50);
}
