#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Pid_controller.h"

int main(void)
{
	PIDController pid1, pid2;
    
   	 // 初始化PID控制器
    	PID_Init(&pid1, 1.0, 0.5, 0.2, 10.0);
    	PID_Init(&pid2, 0.5, 0.2, 0.1, 5.0);
    
    	// 设置设定值
	double target1 = 10.0;
	double target2 = 5.0;
	double output1,output2;
    
	// 模拟更新PID控制器
	double actual1 = 5.0;
	double actual2 = 2.0;
	double dt = 0.1;
		
    	while(1)
	{
		
		output1=PID_Iterate( &pid1, target1, actual1, dt );
		output2=PID_Iterate( &pid2, target2, actual2, dt );
		
		// 模拟输入变化
		actual1 += 1.0;
        	actual2 += 0.5;
	}
}
