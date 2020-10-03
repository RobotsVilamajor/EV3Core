#ifndef _MoveMotor
#define _MoveMotor


void MoveMotor(tMotor m, float target, float speed);
{

	resetMotorEncoder(m);
	setMotorTarget(m, target * 360, speed);
	waitUntilMotorStop(m);
	delay(10);
	resetMotorEncoder(m);

}
void MoveMotorTime(tMotor m, float time, float speed);
{

	setMotorSpeed(m, speed);
	delay(time * 1000);
	setMotorSpeed(m, 0);

}

#endif
