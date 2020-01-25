
void WaitForMotors()
{
	waitUntilMotorStop(motorA);
	waitUntilMotorStop(motorB);
	waitUntilMotorStop(motorC);
	waitUntilMotorStop(motorD);
}

bool InBetween(float x, float rangeMin, float rangeMax)
{
	return (x > rangeMin && x < rangeMax);
}
