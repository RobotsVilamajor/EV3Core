#ifndef _PID
#define _PID

struct PID
{
	float k_p, k_i, k_d;
	float integ;
	float prevError;
	float dt;
};

void InitPID(PID& pid, float k_p, float k_i, float k_d, float dt = 0.01)
{
	pid.k_p = k_p;
	pid.k_i = k_i;
	pid.k_d = k_d;

	pid.dt = dt;

	pid.integ = 0;
	pid.prevError = 0;
}

float UpdatePID(PID& pid, float error)
{
	pid.integ += error;

	float prop = pid.k_p * error;
	float integ = pid.k_i * pid.integ * pid.dt;
	float deriv = pid.k_d * ((error - pid.prevError) / pid.dt);

	float out = prop + integ + deriv;

	pid.prevError = error;

	//displayCenteredBigTextLine(4, "%lf", 1 / pid.dt);

	delay(pid.dt * 1000.0);

	return out;
}

#endif
