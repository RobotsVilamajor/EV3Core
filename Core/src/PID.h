#ifndef _PID
#define _PID

struct PID
{
	float k_p, k_i, k_d;
	float integ;
	float prevError;
};

void InitPID(PID& pid, float k_p, float k_i, float k_d)
{
	pid.k_p = k_p;
	pid.k_i = k_i;
	pid.k_d = k_d;

	pid.integ = 0;
	pid.prevError = 0;
}

float UpdatePID(PID& pid, float error)
{
	pid.integ += error;

	float out = pid.k_p * error + pid.k_i * pid.integ + pid.k_d * (error - pid.prevError);

	pid.prevError = error;

	return out;
}

#endif