#ifndef __RELAY_H
#define __RELAY_H
#define BOOL int
#define TRUE 1
#define FALSE 0
BOOL charge;	//总正开关状态
BOOL pre_charge;//预充开关状态
enum instruct
{
	ONCHARGE = 1,//闭合总正
	ONPRECHARGE,//闭合预充
	OFFCHARGE,//断开总正
	OFFPRECHARGE//断开预充
};
void RelayM_Control(enum instruct ins);	//控制继电器开关
#endif