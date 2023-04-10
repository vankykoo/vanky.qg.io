#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h" 

typedef int ElemType;

typedef  struct QueueNode
{
	NodePtr nodePtr;	//�������ͣ�1������2С����3�ַ��� 
	struct QueueNode *next;
}QueueNode, *LinkQueuePtr;

typedef  struct  LinkQueue
{
	LinkQueuePtr tail;
	LinkQueuePtr head;
	int	count;
}LinkQueue;

//��ջ
Status initLQueue(LinkQueue *s);//��ʼ������
Status pushLQueue(LinkQueue *s,NodePtr np);//�����
Status popLQueue(LinkQueue *s);//������

#endif 
