#ifndef __PRECHARGE_H
#define __PRECHARGE_H

#include <time.h>
#include "std.h"

#define FAIL_TIME 3	//超时时间3S

clock_t start, end;

void PrechargeM_StartPre();	//启动预充
void PrechargeM_StopPre();	//停止预充
void PrechargeM_StartMaster();	//启动总正
void PrechargeM_StopMaster();	//停止总正
BOOL PrechargeM_IsFinish();	//判断V1是否大于95%Bat
BOOL PrechargeM_IsFail();	//超时

#endif
