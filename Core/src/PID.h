#ifndef _PID
#define _PID


struct PID
{
	float kp, ki, kd;
	float integ;
	float prevError;
	float dt;
}

void InitPID(PID& pid, float kp, float ki, float kd, float dt)
{
	pid.kp = kp;
	pid.ki = ki;
	pid.kd = kd;
	pid.dt = dt;
	pid.integ = 0;
	pid.prevError = 0;
}

float UpdatePID(PID& pid, float error)
{
	pid.integ += error * pid.dt;
	float output = pid.kp * error + pid.ki * pid.integ * pid.dt + pid.kd * (error - pid.prevError) / pid.dt;
	pid.prevError = error;
	delay (pid.dt * 1000);
	return output;
}

#endif
