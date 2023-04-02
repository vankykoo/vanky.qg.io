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
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s == NULL){
		printf("栈不存在！\n");
		return ERROR;
	}else if((*s).count == 0){
		return SUCCESS; 
	}else{
		return ERROR;
	}
}


//销毁栈
Status destroyLStack(LinkStack *s){
	if(s == NULL){
		printf("栈不存在或栈为空！\n");
		return ERROR;
	}
	LinkStack *S = NULL;
	S = (LinkStack*)malloc(sizeof(LinkStack));
	S = s;
	
	LinkStackPtr top;
	while((*s).count != 0){
		top = (StackNode*)malloc(sizeof(StackNode));
		top = (*s).top;
		(*s).top = top->next;
		free(top);
		(*s).count -= 1;
	}
	free(S);
	
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if(s == NULL){
		printf("栈不存在！\n");
		return ERROR;
	}
	StackNode *newNode = NULL;
	newNode = (StackNode*)malloc(sizeof(StackNode));
	(*newNode).data = data;
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(s == NULL || (*s).top == NULL){
		printf("栈不存在或栈为空！\n");
		return ERROR;
	}
	
	StackNode *pop;
	pop = (StackNode*)malloc(sizeof(StackNode));
	pop = (*s).top;
	*data = pop->data;
	(*s).top = ((*s).top)->next;
	(*s).count -= 1;
	free(pop);
	
	return SUCCESS;
}
