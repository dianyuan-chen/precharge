#include "state.h"
void Turn_On(void)
{
	PrechargeM_Start();//启动预充 闭合总正开关
	while (!PrechargeM_IsFinish())//判断预充是否完成（V1>95%BAT）
	{
		v_v1 += 1;//V1电压缓慢上升
		printf("charge：%d  |  ", charge);	//查看总正开关状态
		printf("pre_charge：%d  |  ", pre_charge);//查看预充开关状态
		printf("v_v1 = %5d  |  ", v_v1);	//查看V1端电压
		if (PrechargeM_IsFail(start))	//判断是否超时
		{
			PrechargeM_Stop();			//若超时，则重启
			PrechargeM_Start();
		}
	}
	RelayM_Control(ONCHARGE);	//预充完成，闭合总正开关
	PrechargeM_Stop();			//断开预充
	printf("charge：%d  |  ", charge);//查看总正开关状态
	printf("pre_charge：%d  |  ", pre_charge);//查看预充开关状态
	printf("v_v1 = %5d  |  ", v_v1);//查看V1端电压
}