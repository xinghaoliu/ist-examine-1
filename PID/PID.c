#include "PID.h"

void PID_Init(PID *pid,double p,double i,double d,double maxIntegral,double maxOut)
{
	pid->kp=p;
	pid->ki=i;
	pid->kd=d;
	pid->integral=0;
	pid->error=0;
	pid->maxIntegral=maxIntegral;
	pid->maxOutput=maxOut;
}

double PID_Calc(PID *pid,double target,double actual,double dt)
{
	pid->lastError=pid->error;
	pid->error=target-actual;
	
	double pout=pid->error*pid->kp;
	
	pid->integral+=pid->error*pid->ki;
	if(pid->integral > pid->maxIntegral) pid->integral=pid->maxIntegral;
    if(pid->integral < -pid->maxIntegral) pid->integral=-pid->maxIntegral;
	
	double dout=(pid->error-pid->lastError)*pid->kd;

	pid->output=pout+pid->integral+dout;
	
	if(pid->output > pid->maxOutput) pid->output=pid->maxOutput;
    if(pid->output < -pid->maxOutput) pid->output=-pid->maxOutput;
	
	return pid->output;
}
