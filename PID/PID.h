typedef struct
{
	double kp,ki,kd;
	double error,lastError;
	double integral,maxIntegral;
	double output,maxOutput;
}PID;

#ifndef __PID_H__
#define __PID_H__

void PID_Init(PID *pid,double p,double i,double d,double maxIntegral,double maxOut);
double PID_Calc(PID *pid,double target,double actual);

#endif
