#include "state.h"

BOOL charge = FALSE;	//总正开关状态
BOOL pre_charge = FALSE;//预充开关状态
int v_bat = 100, v_v1 = 1;//定义BAT电压与V1电压

void main(void)
{
	Turn_On();
	for (;;)
	{
		;
	}
}