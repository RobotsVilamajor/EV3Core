
void StartCheck()
{
	setLEDColor(ledOrange);
	bool failed = false;
	if (SensorType[S2] != 95)
	{
		displayCenteredBigTextLine(2, "S2 (GYRO) Not connected properly");
		failed = true;
	}
	if (SensorType[S3] != 93)
	{
		displayCenteredBigTextLine(4, "S3 Not connected properly");
		failed = true;
	}
	if (SensorType[S4] != 93)
	{
		displayCenteredBigTextLine(6, "S4 Not connected properly");
		failed = true;
	}

	if (failed)
	{
		setLEDColor(ledRed);
		delay(5000);
		return;
	}

	resetGyro(S2);
	displayCenteredBigTextLine(2, "Checking GYRO");
	delay(5000);
	if (getGyroDegrees(S2) != 0)
	{
		displayCenteredBigTextLine(8, "!!!DRIFT!!!");
		setLEDColor(ledRedFlash);

		delay(5000);
		return;
	}

	setLEDColor(ledGreen);
}
