#include "Pid_controller.h"

// 初始化函数，设置kp、ki、kd参数
void PID_Init(PIDController *pid, double kp, double ki, double kd, double output_max)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->integral = 0;
	pid->error = 0;
	pid->output_max = output_max;
}

double PID_Iterate(PIDController *pid, double target, double feedback)
{
	pid->prev_error = pid->error;				
	pid->error = target - feedback;
	
	pid->integral += pid->error;
	
	double derivative = pid->error - pid->prev_error;

	pid->output = pid->error * pid->kp + pid->integral * pid->ki +derivative * pid->kd;
	
	if(pid->output > pid->output_max) pid->output = pid->output_max;
    	if(pid->output < -pid->output_max) pid->output = -pid->output_max;
	
	return pid->output;
}
