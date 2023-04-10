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


//链栈
Status initLStack(LinkStack *s);//初始化栈
Status pushLStack(LinkStack *s,NodePtr np);//入栈
Status popLStack(LinkStack *s);//出栈


#endif 
