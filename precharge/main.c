#include "Relay.h"
#include "Precharge.h"
#include "HighVoltage.h"
BOOL charge = FALSE;	//总正开关状态
BOOL pre_charge = FALSE;//预充开关状态
int v_bat = 100, v_v1 = 10;
void main(void)
{
	PrechargeM_Start();//启动预充，闭合预充
	while(!PrechargeM_IsFinish())//判断V1是否大于95%BAT
	{	//若不大于95%
		if(PrechargeM_IsFail())//判断是否超时
		{	//若超时
			PrechargeM_Stop();//停止预充
			PrechargeM_Start();//重新开始
		}
	}
	RelayM_Control(ONCHARGE);//闭合总正
	PrechargeM_Stop();//断开预充

	for(;;)
	{
		;
	}
}