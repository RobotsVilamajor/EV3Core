struct Accelerate
{
	float speed;
	float distance;

	float accMult;
	float decMult;

	float safeDist;

	float iniDist, endDist, medDist;
};

void InitAcc(Accelerate& acc, float speed, float distance, float accMult, float decMult, float safeDist)
{
	acc.speed = speed;
	acc.distance = distance - safeDist;

	acc.accMult = accMult;
	acc.decMult = decMult;
	acc.safeDist = safeDist;

	do
	{
		acc.iniDist = log(acc.speed / 5.0) / (log(2) * acc.accMult);
		acc.endDist = log((acc.speed - 5) / 5.0) / (log(2) * acc.decMult);
		acc.medDist = acc.distance - acc.iniDist - acc.endDist;

		acc.speed -= 1;
	}
	while (acc.medDist < 0.2);

	acc.speed += 1;
}

float UpdateAcc(Accelerate& acc, float x)
{
	// Accelerate
	if (x <= acc.iniDist)
		return (pow(2, x	* acc.accMult)) * 5;

	// Constant speed
	if (x <= acc.medDist + acc.iniDist)
		return acc.speed;

	// Decelerate
	if (x <= acc.distance)
		return acc.speed - (pow(2, (x - (acc.medDist + acc.iniDist)) * acc.decMult)) * 5.0;

	// Adjust
	if (x <= acc.distance + acc.safeDist)
		return 7;

	return 0;
}
