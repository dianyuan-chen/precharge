#include "Relay.h"

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