#ifndef __PID_CONTROLLER_H__
#define __PID_CONTROLLER_H__

typedef struct
{
	double kp,ki,kd;
	double error,prev_error;
	double integral;
	double output,output_max;
}PIDController;

//PID_Exported_Functions
void PID_Init(PIDController *pid,double kp,double ki,double kd,double output_max);
double PID_Iterate(PIDController *pid,double target,double actual,double dt);

#endif
