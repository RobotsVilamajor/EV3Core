void AlignWall()
{
	MoveMotorTime(motorA, 7, -20);
	MoveMotorTime(motorD, 7, -20);

	MoveMotor(motorD, 0.68, 40);
	MoveMotor(motorA, 3.72, 40);
}
