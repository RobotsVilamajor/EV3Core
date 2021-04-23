
bool InBetween(float x, float rangeMin, float rangeMax)
{
	return x >= rangeMin && x <= rangeMax;
}

void AdjustWheel(tMotor m, float target)
{
	float error = getMotorEncoder(m) / 360.0 - target;

	if (!InBetween(error, -0.005, 0.005))
	{
		float dir = 0;

		if (error < 0)
			dir = -1;
		else
			dir = 1;

		setMotorSpeed(m, -6 * dir);

		waitUntil((getMotorEncoder(m) / 360.0 - target) * dir <= 0);

		setMotorSpeed(m, 0);

		delay(100);
	}
}

/*float tanh(float x)
{
	return (exp(x)-exp(-x)) / (exp(x)+exp(-x));
}*/

/*inline float map(const float& value, const float& inputMin, const float& inputMax, const float& outputMin, const float& outputMax)
{
	return outputMin + ((outputMax - outputMin) / (inputMax - inputMin)) * (value - inputMin);
}*/
