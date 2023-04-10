#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h" 

typedef int ElemType;

typedef  struct QueueNode
{
	NodePtr nodePtr;	//输入类型，1整数，2小数，3字符串 
	struct QueueNode *next;
}QueueNode, *LinkQueuePtr;

typedef  struct  LinkQueue
{
	LinkQueuePtr tail;
	LinkQueuePtr head;
	int	count;
}LinkQueue;

//链栈
Status initLQueue(LinkQueue *s);//初始化队列
Status pushLQueue(LinkQueue *s,NodePtr np);//入队列
Status popLQueue(LinkQueue *s);//出队列

#endif 
