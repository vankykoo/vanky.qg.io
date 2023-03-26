#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct QueueNode
{
	int dataType;	//输入类型，1整数，2小数，3字符串 
	void *data;
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
Status isEmptyLQueue(LinkQueue *s);//判断队列是否为空
Status getHeadQueue(LinkQueue *s,void *e);//得到队列头元素
Status clearLQueue(LinkQueue *s);//清空队列
Status destroyLQueue(LinkQueue *s);//销毁队列
Status LQueueLength(LinkQueue *s,int *length);//检测队列长度
Status pushLQueue(LinkQueue *s,void* data);//入队列
Status popLQueue(LinkQueue *s,void *data);//出队列

QueueNode* CreateQueueNode();//创建队列点 
ElemType inputJudgment(char arr[]);//输入格式判断
void showMenu();//菜单 
LinkQueue* getLinkQueue(LinkQueue *s);//开队列 


#endif 
