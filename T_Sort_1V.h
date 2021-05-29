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
		MoveMotorTime(motorA, 4, -40);
		MoveMotorTime(motorD, 4, -40);
	}
  waitForButtonPress();
	flushButtonMessages();
	setMotorBrakeMode(motorA, motorBrake);
  setMotorBrakeMode(motorD, motorBrake);
	resetGyro(S2);
	delay(300);
	//Fer ajust inicial
	Recta(Bwd, 0.02, 10, false, false);

//	//Anem fins a la canasta
//	//Avancem fins humans
	MoveMotor(motorA, 1.2, 60);
	MoveMotorAsync(motorD, 2.65, 40);
	Recta(Fwd, 2.4, 60);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(32, 15);
	Align(Fwd, 2);
	Recta(Fwd, 2.33, 60);

////Pujem primer pis
	setMotorBrakeMode(motorC, motorBrake);
	setMotorBrakeMode(motorB, motorBrake);
	MoveMotor(motorA, -0.95, 60);
	MoveMotor(motorD, -1.5, 60);
	setMotorBrakeMode(motorD, motorBrake);

//	//Pujem segon pis
	MoveMotor(motorA, 2.1, 60);
	MoveMotor(motorD, 1.5, 60);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotor(motorA, -2.1, 60);
	MoveMotor(motorD, -2.65, 70);
	setMotorBrakeMode(motorD, motorBrake);
	MoveMotor(motorA, 0.9, 60);
	MoveMotorAsync(motorD, 2.65, 70);
	Recta(Bwd, 0.7, 60);
	setMotorBrakeMode(motorD, motorBrake);
	Turn(90, 30);
	Recta(Fwd, 2.8, 60, false, false);
	MoveMotorAsync(motorC, 2, -30);
	MoveMotor(motorB, 2, -60);
}
