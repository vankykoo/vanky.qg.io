#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"


typedef int ElemType;

typedef  struct StackNode
{
	NodePtr nodePtr;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status pushLStack(LinkStack *s,NodePtr np);//��ջ
Status popLStack(LinkStack *s);//��ջ


#endif 
