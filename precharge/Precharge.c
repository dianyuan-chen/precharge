#include "Precharge.h"

void PrechargeM_Start()	//启动预充
{
	RelayM_Control(ONPRECHARGE);
}
void PrechargeM_Stop()	//停止预充
{
	RelayM_Control(OFFPRECHARGE);
}
BOOL PrechargeM_IsFinish()	//判断V1是否大于95%Bat
{
	if(v_v1*100 >= v_bat * 95)//Hv_Get()获取电压
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL PrechargeM_IsFail()	//超时
{
	if(/*判断是否超时*/)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}