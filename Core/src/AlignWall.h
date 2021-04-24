	/*
	Aliniar la wall sortida 1 temporada replay
	*/
	void AlignWall()
	{
	MoveMotorTime(motorA, 3, 70);
	MoveMotorTime(motorD, 4, 70);
	MoveMotor(motorD, -6.2, 50);
	}
