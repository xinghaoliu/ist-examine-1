#include "stm32f10x.h"                 
#include "Pid_controller.h"
#include <stdio.h>

int main(void)
{
	PIDController pid1, pid2;
    
   	 // 初始化PID控制器，设置kp、ki、kd参数
    	PID_Init(&pid1, 1.23, 0.2, 0.1, 10.0);
    	PID_Init(&pid2, 0.5, 0.05, 0.2, 5.0);
    
    	// 设置目标值
	double target1 = 10.0;
	double target2 = 13.7;
	double output1, output2;
    
	// 模拟采样，得到反馈值
	double feedback1 = 4.2;
	double feedback2 = 2.0;

	int i=0;
		
    	// 模拟不断采样的过程
	while(i<=100)
	{
		// PID计算输出值
		output1 = PID_Iterate(&pid1, target1, feedback1);
		output2 = PID_Iterate(&pid2, target2, feedback2);
		printf("output1=%lf\n",output1);
		printf("output2=%lf\n",output2);
		
		// 模拟PID输出值作用于反馈值
		feedback1 += output1;
        	feedback2 += output2;
		printf("feedback1=%lf\n",feedback1);
        	printf("feedback2=%lf\n\n",feedback2);

		i++;
	}
}
