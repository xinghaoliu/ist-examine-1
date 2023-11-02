#include "Pid_controller.h"

void PID_Init(PIDController *pid,double kp,double ki,double kd,double output_max)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->integral = 0;
	pid->error = 0;
	pid->output_max = output_max;
}

double PID_Iterate(PIDController *pid,double target,double actual,double dt)
{
	pid->prev_error = pid->error;
	pid->error = target - actual;
	
	pid->integral += pid->error * dt;
	
	double derivative = (pid->error - pid->prev_error) / dt;

	pid->output = pid->error * pid->kp + pid->integral * pid->kp +derivative * pid->kd;
	
	if(pid->output > pid->output_max) pid->output = pid->output_max;
    	if(pid->output < -pid->output_max) pid->output = -pid->output_max;
	
	return pid->output;
}
