#include "stm32f10x.h"                  // Device header
#include "pwm.h"
#include "OLED.h"
#include "Delay.h"
#include "Pid_controller.h"

int main(void)
{
//	OLED_Init();
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14|GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	
//	GPIO_ResetBits(GPIOB, GPIO_Pin_12);

//	int i=0;
	PIDController pid1, pid2;
    
    // 初始化PID控制器
    PID_Init(&pid1, 1.0, 0.5, 0.2, 10.0);
    PID_Init(&pid2, 0.5, 0.2, 0.1, 5.0);
    
    // 设置设定值
	double target1 = 10.0;
	double target2 = 5.0;
    
    while(1)
	{
		// 模拟更新PID控制器
		double actual1 = 5.0;
		double actual2 = 2.0;
		double dt = 0.1;
		
		PID_Iterate( &pid1, target1, actual1, dt );
		PID_Iterate( &pid2, target2, actual2, dt );


	}
	
}

//	while(1)
//	{
//		double target,actual;
//		actual=50;
//		target=40;
////		PID_Calc(&myPid,target, actual);
////		myPid.output;
//		Delay_ms(10);
//		
//		OLED_ShowNum(1, 1, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12), 2);
//		OLED_ShowNum(1, 4, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13), 2);
//		OLED_ShowNum(1, 7, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14), 2);
//		OLED_ShowNum(1, 10, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15), 2);

////		OLED_ShowNum(5, 1, i, 5);
////		i++;
//	}
//}
