#ifndef __RELAY_H
#define __RELAY_H
#define BOOL int
#define TRUE 1
#define FALSE 0
extern BOOL charge, pre_charge;
enum instruct
{
	ONCHARGE = 1,	//闭合总正
	ONPRECHARGE,	//闭合预充
	OFFCHARGE,	//段开总正
	OFFPRECHARGE	//段开预充
};
void RelayM_Control();	//控制继电器开关
#endif