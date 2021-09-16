#include <stdio.h>
#include "Precharge.h"

void PrechargeM_Start()	//启动预充
{
	RelayM_Control(ONPRECHARGE);
	start = clock();
	printf("start time %ld\n", start);
}
void PrechargeM_Stop()	//停止预充
{
	RelayM_Control(OFFPRECHARGE);
}
BOOL PrechargeM_IsFinish()	//判断V1是否大于95%Bat
{
	if (Hv_Get(V1) * 100 >= Hv_Get(BAT) * 95)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL PrechargeM_IsFail(clock_t start)	//超时
{
	end = clock();
	printf("end time:%5ld  |  ", end);
	double time = (double)((double)end - (double)start) / CLOCKS_PER_SEC;
	printf("end - start time:%.3lf\n", time);
	if (time > FAIL_TIME)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}