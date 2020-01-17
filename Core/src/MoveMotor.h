void MoveMotor(tMotor m, float target, float speed)
{
	resetMotorEncoder(m);

	setMotorTarget(m, target * 360, speed);
	waitUntilMotorStop(m);
	delay(100);

	resetMotorEncoder(m);
}

void MoveMotorAsync(tMotor m, float target, float speed)
{
	resetMotorEncoder(m);

	setMotorTarget(m, target * 360, speed);
}

void MoveMotorTime(tMotor m, float time, float speed)
{
	setMotorSpeed(m, speed);

	delay(time * 1000.0);

	setMotorSpeed(m, 0);
}
