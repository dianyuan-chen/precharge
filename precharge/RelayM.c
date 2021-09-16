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
