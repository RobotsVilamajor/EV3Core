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


void T_Sort_1V(bool align = false)
{
	flushButtonMessages();
	if (align == true)
	{
		MoveMotorTime(motorA, 2, 70);
		MoveMotorTime(motorD, 4, 70);
	}

	resetGyro(S2);
	delay(300);
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
  waitForButtonPress();
	flushButtonMessages();
	//Fer ajust inicial
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	Recta(Bwd, 0.02, 10, false, false);

//	//Anem fins a la canasta
//	//Avancem fins humans
	MoveMotorAsync(motorA, 1.2, 40);
	MoveMotor(motorD, 2.65, 40);
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	Recta(Fwd, 2.4, 60);
	Turn(32, 15);
	Align(Fwd, 2);
	Recta(Fwd, 2.5, 60);
	//WaitForLine(Fwd, 5, 10, Rgt);
	Recta(Bwd, 0.05, 60);

//Pujem primer pis
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotor(motorA, -0.75, 60);
	MoveMotor(motorD, -1.4, 60);
	setMotorBrakeMode(motorD, motorBrake);

	//Pujem segon pis
	MoveMotor(motorA, 1.9, 60);
	MoveMotor(motorD, 1.4, 60);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotor(motorA, -1.9, 60);
	MoveMotor(motorD, -2.65, 70);
	MoveMotorAsync(motorD, 0.5, 70);
	Recta(Bwd, 0.5, 60);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(97, 30);
	Recta(Fwd, 4, 70, false, false);

}
