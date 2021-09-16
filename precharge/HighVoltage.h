#ifndef __HIGHVOLTAGE_H
#define __HIGHVOLTAGE_H
int v_bat, v_v1;//定义BAT电压与V1电压
enum Voltage
{
	BAT = 0,//定义BAT端电压名称为BAT值为0
	V1 = 1 //定义V1端电压名称为V1值为1
};
int Hv_Get(enum Voltage v_type);	//获取电压
#endif