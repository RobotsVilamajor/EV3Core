void AlignWall()
{
	MoveMotorTime(motorA, 1.5, -50);
	MoveMotorTime(motorD, 1.5, -40);

	MoveMotor(motorD, 0.68, 40);
	MoveMotor(motorA, 3.65, 40);
}
