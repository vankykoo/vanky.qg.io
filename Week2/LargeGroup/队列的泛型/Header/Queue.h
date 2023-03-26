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
	int dataType;	//�������ͣ�1������2С����3�ַ��� 
	void *data;
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
Status isEmptyLQueue(LinkQueue *s);//�ж϶����Ƿ�Ϊ��
Status getHeadQueue(LinkQueue *s,void *e);//�õ�����ͷԪ��
Status clearLQueue(LinkQueue *s);//��ն���
Status destroyLQueue(LinkQueue *s);//���ٶ���
Status LQueueLength(LinkQueue *s,int *length);//�����г���
Status pushLQueue(LinkQueue *s,void* data);//�����
Status popLQueue(LinkQueue *s,void *data);//������

QueueNode* CreateQueueNode();//�������е� 
ElemType inputJudgment(char arr[]);//�����ʽ�ж�
void showMenu();//�˵� 
LinkQueue* getLinkQueue(LinkQueue *s);//������ 


#endif 
