#include <stdio.h>
#include "Precharge.h"
#include "RelayM.h"
#include "HighVoltage.h"

void PrechargeM_Start()	//启动预充
{
	RelayM_Control(RelayM_PreSwitch, ON);
	start = clock();	//初始时间
	printf("start time %ld\n", start);
}
void PrechargeM_Stop()	//停止预充
{
	RelayM_Control(RelayM_MasterSwitch, OFF);
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
BOOL PrechargeM_IsFail(clock_t start_time)	//超时
{
	end = clock();		//此刻时间
	printf("end time:%5ld  |  ", end);
	double time = (double)((double)end - (double)start_time) / CLOCKS_PER_SEC;//经过的时间
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