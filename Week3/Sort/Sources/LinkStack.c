#include "LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	if(s == NULL){
		printf("ջ�����٣������³�ʼ����\n");
		return ERROR; 
	}
	(*s).count = 0;
	(*s).top = NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s == NULL){
		printf("ջ�����ڣ�\n");
		return ERROR;
	}else if((*s).count == 0){
		return SUCCESS; 
	}else{
		return ERROR;
	}
}


//����ջ
Status destroyLStack(LinkStack *s){
	if(s == NULL){
		printf("ջ�����ڻ�ջΪ�գ�\n");
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

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	if(s == NULL){
		printf("ջ�����ڣ�\n");
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

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s == NULL || (*s).top == NULL){
		printf("ջ�����ڻ�ջΪ�գ�\n");
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
