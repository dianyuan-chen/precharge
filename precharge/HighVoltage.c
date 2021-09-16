#include "HighVoltage.h"

int Hv_Get(enum Voltage v_type)	//获取电压
{
	if (v_type == BAT)	//若获取电压为BAT，则返回BAT端电压v_bat
	{
		return v_bat;
	}
	else	//若获取电压为V1，则返回V1端电压v_v1
	{
		return v_v1;
	}
}