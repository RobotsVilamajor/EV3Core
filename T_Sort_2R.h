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
	Recta(Fwd, 1.4, 30, false, false);
	setMotorSpeed(motorB, -35);
	setMotorSpeed(motorC, -25);
	delay(500);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	////setMotorSpeed(motorB, -17);
	////setMotorSpeed(motorC, -15);
	////delay(500);
	////setMotorSpeed(motorB, 0);
	////setMotorSpeed(motorC, 0);

	//	//anar a rodes
	//Recta(Bwd, 0.2, 50);
	//MoveMotor(motorA, -0.9, 70);
	//MoveMotorAsync(motorA, -1.2, 40);
	//Recta(Fwd, 0.9, 40);

	////////MoveMotorAsync(motorD, 1.5, 50);
	////////Recta(Fwd, 1.8, 20);

	////////WaitForLine (Fwd, 1, 30, Lft)
	////////MoveMotorAsync(motorD, -1.5, 50);
	////////Recta(Bwd, 1.5, 20);
	////////MoveMotorAsync(motorD, 1, 50);

	//	//fer rodes
	//MoveMotorAsync(motorD, 1.2, 40);
	//Recta(Fwd, 0.4, 20, true, false);
	//Recta(Fwd, 1, 30, false, true);

}
