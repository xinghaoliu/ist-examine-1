#include "Pid_controller.h"

/**
  * @brief PID结构体初始化函数
  * @param pid：指向PIDController结构体的指针
  * @param kp：比例参数
  * @param ki：积分参数
  * @param kd：微分参数
  * @param output_max：输出限幅值，PID算法的输出最大值不会大于此值，最小值不会小于此值的负数
  * @retval 无
  */
void PID_Init(PIDController *pid, double kp, double ki, double kd, double output_max)
{
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->integral = 0;
	pid->error = 0;
	pid->output_max = output_max;
}

/**
  * @brief PID算法函数
  * @param pid：指向PIDController结构体的指针
  * @param target：系统的目标值
  * @param feedback：系统的反馈值
  * @retval PID算法的输出值
  */
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
