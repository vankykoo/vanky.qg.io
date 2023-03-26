#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	char data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct NumStackNode
{
	double data;
	struct NumStackNode *next;
}NumStackNode, *LinkNumStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

typedef  struct  LinkNumStack
{
	LinkNumStackPtr top;
	int	count;
}LinkNumStack;


//链栈
Status initLStack(LinkStack *s);//初始化栈
Status initLNumStack(LinkNumStack *s);
Status clearLStack(LinkStack *s);//清空栈
Status pushLStack(LinkStack *s,char data);//入栈
int pushNumLStack(LinkNumStack *s,char *input,int index);//入数字栈 
char popLStack(LinkStack *s);//出栈 
double popNumLStack(LinkNumStack *s);//出数字栈 
ElemType inputJudgment(char *arr);//格式判断
Status equaJudgment(char *input);//中缀表达式格式判断 
void myCalculator(LinkStack *s,LinkNumStack *numLinkStack,char *input,char *output);//计算器 
void toPostfix(LinkStack *s,char *input,char *output);//中缀转后缀 
void toPostfixAndShow(LinkStack *s,char *input,char *output);
void showMenu();//菜单 
Status pushDouble(LinkNumStack *s,double num);
void inputForm(char *input);//输入数组改造 


#endif 
