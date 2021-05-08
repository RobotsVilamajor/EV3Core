
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


	displayCenteredBigTextLine(2, "Checking Motors");
	setMotorSpeed(motorA, 30);
	setMotorSpeed(motorB, 30);
	setMotorSpeed(motorC, 30);
	setMotorSpeed(motorD, 30);
	delay(500);
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	setMotorSpeed(motorD, 0);

	eraseDisplay();
	if (getMotorEncoder(motorA) == 0)
	{
		displayCenteredBigTextLine(2, "A Not connected");
		failed = true;
	}
	if (getMotorEncoder(motorB) == 0)
	{
		displayCenteredBigTextLine(4, "B Not connected");
		failed = true;
	}
	if (getMotorEncoder(motorC) == 0)
	{
		displayCenteredBigTextLine(6, "C Not connected");
		failed = true;
	}
	if (getMotorEncoder(motorD) == 0)
	{
		displayCenteredBigTextLine(8, "D Not connected");
		failed = true;
	}

	if (failed)
	{
		setLEDColor(ledRed);
		delay(5000);
		return;
	}

	eraseDisplay();
	displayCenteredBigTextLine(2, "Press for recta");
	waitForButtonPress();
	flushButtonMessages();

	delay(250);
	Recta(Bwd, 0.08, 20);

	//Recta(Fwd, 3, 60);
	//waitForButtonPress();
	//flushButtonMessages();
	//delay(250);
	//Recta(Bwd, 0.08, 20);
	//Recta(Fwd, 5, 60);

}
