#include "Relay.h"
charge = FALSE;	//总正开关状态初始为关
pre_charge = FALSE;//预充开关状态初始为关
void RelayM_Control(enum instruct ins)
{
	switch (ins)
	{
	case ONCHARGE: charge = TRUE; break;
	case ONPRECHARGE: pre_charge = TRUE; break;
	case OFFCHARGE: charge = FALSE; break;
	case OFFPRECHARGE: pre_charge = FALSE; break;
	}
}