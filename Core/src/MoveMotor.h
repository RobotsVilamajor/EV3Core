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
