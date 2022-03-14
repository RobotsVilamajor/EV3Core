
task main()
{
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	setMotorSpeed(motorB, 10);
	setMotorSpeed(motorC, 10);
	float countS3;
	float countS4;

	waitUntil(getColorReflected(S3)<= 70);

	while (getColorReflected(S3)>= 20){
		countS3 = getMotorEncoder(motorB);
	}
	waitUntil (getColorReflected(S4)<= 70);

	while (getColorReflected(S4)>= 20){
		countS4 = getMotorEncoder(motorB);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	resetGyro(S2);

	float corr = ((countS4-countS3-80)/10)*3;
	float sid;
	if (corr > 1){
		sid = Lft;
	}
	else if (corr < -1){
		sid = Rgt;
	}
	Turn(corr, 10, sid);


}
