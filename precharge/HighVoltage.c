#include "HighVoltage.h"

v_bat = 10000; v_v1 = 1;//定义BAT电压与V1电压的值
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