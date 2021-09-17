#ifndef __NODE_H
#define __NODE_H

#include "std.h"

typedef struct node
{
	int node_num;	//节点号
	BOOL(*Condition)(void);//条件
	int N_num;	//条件数
	int status;	//条件匹配
	void (*Act)(void);//动作
	int next_node;//下个节点
}NodeType;

void Node_Start(void);
void No_Act(void);

#endif
