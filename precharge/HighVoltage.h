#ifndef __HIGHVOLTAGE_H
#define __HIGHVOLTAGE_H
extern int v_bat, v_v1;
enum Voltage
{
	BAT = 0,//BAT电压
	V1 = 1//V1电压
};

unsigned char Hv_Get(int v_type);	//获取电压

#endif