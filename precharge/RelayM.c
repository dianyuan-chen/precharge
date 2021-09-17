#include "RelayM.h"

charge = FALSE;	//总正开关状态初始为关
pre_charge = FALSE;//预充开关状态初始为关

void RelayM_Control(RelayM_Switch RelayM_switch, BOOL act)
{
	if (RelayM_switch == RelayM_MasterSwitch)
	{
		charge = act;
	}
	else
	{
		pre_charge = act;
	}
}
void RelayM_Change()//预充闭合总正断开情况下，闭合总正 断开预充
{
	charge = 1;
	pre_charge = 0;
}
