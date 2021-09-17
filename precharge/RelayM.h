#ifndef __RELAYM_H
#define __RELAYM_H

#include "std.h"

typedef enum Switch
{
	RelayM_MasterSwitch = 0,
	RelayM_PreSwitch = 1
}RelayM_Switch;

BOOL charge;	//总正开关状态
BOOL pre_charge;//预充开关状态

void RelayM_Control(RelayM_Switch RelayM_switch, BOOL act);	//控制继电器开关
void RelayM_Change();//闭合总正，断开预充

#endif
