#ifndef _ACCELERATE
#define _ACCELERATE

struct Accelerate
{
	float speed;
	float accMult, decMult;
	float accExp, decExp;
	float distance;
	float safeDist;
	float startSpeed, endSpeed;
	float iniDist, medDist, endDist;
};

void InitAcc (Accelerate& acc, float speed, float distance, float accMult, float decMult, float accExp, float decExp, float startSpeed, float endSpeed, float safeDist)
{
	acc.speed = speed;
	acc.distance = distance - safeDist;
	acc.accMult = accMult;
	acc.decMult = decMult;
	acc.accExp = accExp;
	acc.decExp = decExp;
	acc.startSpeed = startSpeed;
	acc.endSpeed = endSpeed;
	acc.safeDist = safeDist;


	do
	{
		acc.iniDist = pow((acc.speed - acc.startSpeed) / acc.accMult, 1.0 / acc.accExp);
		acc.endDist = pow((acc.speed - acc.endSpeed) / acc.decMult, 1.0 / acc.decExp);
		acc.medDist = acc.distance - acc.iniDist - acc.endDist;

		acc.speed -= 1;
	}
	while (acc.medDist < 0.2);

	acc.speed += 1;
}


float GetSpeed (Accelerate& acc, float x)
{
	if (x < acc.iniDist)
		return acc.startSpeed + acc.accMult * pow(x, acc.accExp);

	else if (x < acc.iniDist + acc.medDist)
		return acc.speed;

	else if (x < acc.distance)
		return acc.speed - acc.decMult * pow(x - (acc.iniDist + acc.medDist), acc.decExp);

	else if (x < acc.distance + acc.safeDist)
		return acc.endSpeed;

	else
		return acc.endSpeed;
}

#endif
