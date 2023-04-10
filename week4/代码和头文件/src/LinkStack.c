#include "LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	if(s == NULL){
		printf("栈被销毁！请重新初始化！\n");
		return ERROR; 
	}
	(*s).count = 0;
	(*s).top = NULL;
	return SUCCESS;
	//printf("初始化栈成功！\n");
}

//入栈
Status pushLStack(LinkStack *s,NodePtr np){
	if(s == NULL){
		printf("栈不存在！\n");
		return ERROR;
	}
	
	if(np != NULL){
		//创建一个新的栈结点 
		StackNode *newNode = NULL;
		newNode = (StackNode*)malloc(sizeof(StackNode));
		newNode->nodePtr = np;
		newNode->next = (*s).top;
		(*s).top = newNode;
		(*s).count += 1;
	}
	
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s){
	if(s == NULL || (*s).top == NULL){
		printf("栈不存在或栈为空！\n");
		return ERROR;
	}
	int data;
	StackNode *pop;
	pop = (StackNode*)malloc(sizeof(StackNode));
	pop = (*s).top;
	data = pop->nodePtr->data; 
	(*s).top = ((*s).top)->next;
	(*s).count -= 1;
	free(pop);
	
	return SUCCESS;
}
