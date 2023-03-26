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


//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status initLNumStack(LinkNumStack *s);
Status clearLStack(LinkStack *s);//���ջ
Status pushLStack(LinkStack *s,char data);//��ջ
int pushNumLStack(LinkNumStack *s,char *input,int index);//������ջ 
char popLStack(LinkStack *s);//��ջ 
double popNumLStack(LinkNumStack *s);//������ջ 
ElemType inputJudgment(char *arr);//��ʽ�ж�
Status equaJudgment(char *input);//��׺���ʽ��ʽ�ж� 
void myCalculator(LinkStack *s,LinkNumStack *numLinkStack,char *input,char *output);//������ 
void toPostfix(LinkStack *s,char *input,char *output);//��׺ת��׺ 
void toPostfixAndShow(LinkStack *s,char *input,char *output);
void showMenu();//�˵� 
Status pushDouble(LinkNumStack *s,double num);
void inputForm(char *input);//����������� 


#endif 
