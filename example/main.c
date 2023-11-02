#include "stm32f10x.h"                 
#include "Pid_controller.h"

int main(void)
{
	PIDController pid1, pid2;
    
   	 // 初始化PID控制器
    	PID_Init(&pid1, 1.0, 0.5, 0.2, 10.0);
    	PID_Init(&pid2, 0.5, 0.2, 0.1, 5.0);
    
    	// 设置目标值
	double target1 = 10.0;
	double target2 = 5.0;
	double output1, output2;
    
	// 模拟更新PID控制器
	double feedback1 = 5.0;
	double feedback2 = 2.0;
		
    	while(1)
	{
		
		output1 = PID_Iterate(&pid1, target1, feedback1);
		output2 = PID_Iterate(&pid2, target2, feedback2);
		
		// 模拟实际值的变化
		feedback1 += output1;
        	feedback2 += output2;
	}
}
