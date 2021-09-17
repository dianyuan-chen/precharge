#include "Node.h"
#include "Diagnosis.h"
#include "Precharge.h"
#include "RelayM.h"

//Node0 判断故障
NodeType Node_Diag_True = { 0, Diagnosis, 2,1,No_Act, 0 };			//故障 继续判断故障 
NodeType Node_Diag_False = { 0, Diagnosis, 2,0,PrechargeM_Start,1 };	//无故障 开始预充 进入预充完成判断Node1
//Node1 预充完成判断
NodeType Node_Prechrge_True = { 1, PrechargeM_IsFinish,2,1, RelayM_Change, 2 };	//预充完成， 断开预充，闭合总正 进入下一节点Node2
NodeType Node_Prechrge_False = { 1, PrechargeM_IsFinish,2,0, No_Act, 3 };		//预充未完成 进入超时判断Node3
//Node2	充电中故障判断
NodeType Node_Charging_TRUE = { 2, Diagnosis,2,1, ChargeM_Stop, 0 };//故障 断开总正 进入Node0
NodeType Node_Charging_False = { 2, Diagnosis,2,0, No_Act, 2 };		//充电中 继续充电
//Node3 超时判断
NodeType Node_Fail_True = { 3, PrechargeM_IsFail, 2,1,PrechargeM_Stop, 0 };	//超时 预充停止 进入下一节点Node0
NodeType Node_Fail_False = { 3, PrechargeM_IsFail,2,0, No_Act, 1 };			//未超时 进入下一节点Node1继续判断预充是否完成

void No_Act()
{
	;
}
void Node_Start()
{
	NodeType Lcfg[4][2] =			//节点配置
	{
		Node_Diag_True, Node_Diag_False,
		Node_Prechrge_True, Node_Prechrge_False,
		Node_Charging_TRUE, Node_Charging_False,
		Node_Fail_True, Node_Fail_False
	};
	int CurrentNode = 0;//当前节点
	int N_num;//当前节点条件数
	while (1)
	{
		N_num = Lcfg[CurrentNode][0].N_num;
		for (int i = 0; i < N_num; i++)
		{
			if (Lcfg[CurrentNode][i].Condition() == Lcfg[CurrentNode][i].status)//判断
			{
				Lcfg[CurrentNode][i].Act();	//动作
				printf("TRUE判断当前状态正确Lcfg[%d][%d],即将指向Node%d\n", CurrentNode,i, Lcfg[CurrentNode][i].next_node);
				CurrentNode = Lcfg[CurrentNode][i].next_node;//下一节点
			}
		}

	}
}
