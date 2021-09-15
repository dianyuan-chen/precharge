#ifndef __PRECHARGE_H
#define __PRECHARGE_H
#include <time.h>
#include "Relay.h"
extern int v_bat, v_v1;
clock_t start,end;
void PrechargeM_Start();	//启动预充
void PrechargeM_Stop();	//停止预充
BOOL PrechargeM_IsFinish();	//判断V1是否大于95%Bat
BOOL PrechargeM_IsFail();	//超时
#endif