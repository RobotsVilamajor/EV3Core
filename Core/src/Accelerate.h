#ifndef _ACCELERATE
#define _ACCELERATE

struct Accelerate
{
	float speed;
	float distance;
	float accMult, decMult;
	float safeDist;
	float startSpeed, endSpeed;
	float iniDist, medDist, endDist;
};

void InitAcc (Accelerate& acc, float speed, float distance, float accMult, float decMult, float startSpeed, float endSpeed, float safeDist)
{
	acc.speed = speed;
	acc.distance = distance - safeDist;
	acc.accMult = accMult;
	acc.decMult = decMult;
	acc.startSpeed = startSpeed;
	acc.endSpeed = endSpeed;
	acc.safeDist = safeDist;


	do
	{
		acc.iniDist = log(acc.speed - acc.startSpeed + 1) / acc.accMult * log(2);
		acc.endDist = log(acc.speed - acc.endSpeed + 1) / acc.accMult * log(2);
		acc.medDist = acc.distance - acc.iniDist - acc.endDist;

		acc.speed -= 1;
	}
	while (acc.medDist < 0.2);

	acc.speed += 1;
}

#endif
