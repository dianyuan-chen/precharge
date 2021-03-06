#include <stdio.h>
#include "PrechargeM.h"
#include "RelayM.h"
#include "HighVoltage.h"

void PrechargeM_StartMaster()	//启动总正
{
	RelayM_Control(RelayM_MasterSwitch, ON);
}
void PreChargeM_StopMaster()	//停止总正
{
	RelayM_Control(RelayM_MasterSwitch, OFF);
}
void PrechargeM_StartPre()	//启动预充
{
	RelayM_Control(RelayM_PreSwitch, ON);
	start = clock();	//初始时间
	printf("start time %ld\n", start);
}
void PrechargeM_StopPre()	//停止预充
{
	RelayM_Control(RelayM_PreSwitch, OFF);
}
BOOL PrechargeM_IsFinish()	//判断V1是否大于95%Bat
{
	if (Hv_Get(Hv_V1) * 100 >= Hv_Get(Hv_Bat) * 95)
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
	end = clock();		//此刻时间
	printf("end time:%5ld  |  ", end);
	double time = (double)((double)end - (double)start) / CLOCKS_PER_SEC;//经过的时间
	printf("end - start time:%.3lf\n", time);
	if (time > FAIL_TIME)//判断是否超过3秒
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
