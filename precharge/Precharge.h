#ifndef __PRECHARGE_H
#define __PRECHARGE_H
#include <time.h>
#include "Relay.h"
#include "HighVoltage.h"
#define FAIL_TIME 3	//超时时间3S
clock_t start, end;
void PrechargeM_Start();	//启动预充
void PrechargeM_Stop();	//停止预充
BOOL PrechargeM_IsFinish();	//判断V1是否大于95%Bat
BOOL PrechargeM_IsFail(clock_t start);	//超时
#endif