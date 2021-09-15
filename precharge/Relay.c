#include "Relay.h"


void RelayM_Control(enum instruct ins)
{
	switch(ins)
	{
		case 1: charge = TRUE;break;
		case 2: pre_charge = TRUE;break;
		case 3: charge = FALSE;break;
		case 4: pre_charge = FALSE;break;
	}
}