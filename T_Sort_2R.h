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


void T_Sort_2R(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		//aling
		MoveMotorTime(motorA, 5, -10);
		MoveMotorTime(motorD, 4, 40);
		delay(100);
		MoveMotor(motorA, 2.1, 50);
		MoveMotor(motorD, 3.05, -40);
		setMotorBrakeMode(motorD, motorBrake);
	}
  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);
	//Fer ajust inicial
	Recta(Bwd, 0.02, 10, false, false);

		// Fer comptapassos
	Recta(Fwd, 4.7, 70, true, false);
	Recta(Fwd, 1.3, 35, false, false);
	setMotorSpeed(motorB, -15);
	setMotorSpeed(motorC, -8);
	delay(1000);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//enganxar-se a la paret
	setMotorSpeed(motorB, -20);
	setMotorSpeed(motorC, 20);
	delay(400);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//tornem a fer tope
	setMotorSpeed(motorB, -8);
	setMotorSpeed(motorC, -8);
	delay(400);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);

		//anar a rodes
	Recta(Bwd, 0.2, 40);
	MoveMotor(motorA, -0.9, 70);
	MoveMotorAsync(motorA, -1.2, 30);
	Recta(Fwd, 0.9, 50);

	//girar roda blava
	MoveMotorAsync(motorD, 1.2, 40);
	Recta(Fwd, 0.4, 20, true, false);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 1, 30, false, true);
	Turn(0, 30);

	// Fer "rem"
	MoveMotorAsync(motorA, 0.7, 70);
	Recta(Fwd, 0.9, 20);
	MoveMotor(motorD, -1.2, 40);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.6, 40);
	MoveMotor(motorA, -0.7, 70);
	Turn(0, 40); //abans era 12

	//sortir de "rem"
	MoveMotor(motorD, 1, 40);
	setMotorBrakeMode(motorD, motorBrake);
	//Turn(0, 30);
	Recta(Bwd, 0.2, 40);
	MoveMotor(motorD, -1, 40);
	setMotorBrakeMode(motorD, motorBrake);

	//collocar roda
	Recta(Bwd, 0.8, 40); //encara no es sap el n

	//anar a l'altre secció

	MoveMotor(motorD, 2.5, 40);
	setMotorBrakeMode(motorD, motorBrake);
	delay (500);
	MoveMotorAsync(motorA, 1.1, 40);
	Recta(Fwd, 1.5, 40);
	Turn (90, 30);//dona problemes.
	Recta(Fwd, 2, 40);
	WaitForLine(Fwd, 1, 20, Lft);
	Align(Fwd, 4);

	//ninu
	MoveMotorAsync(motorA, -0.5, 40);
	Recta(Bwd, 0.8, 40);

	MoveMotor(motorD, -2.2, 40);
	setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.5, 30);
	MoveMotor(motorD, -0.3, 40);
	setMotorBrakeMode(motorD, motorBrake);


}
