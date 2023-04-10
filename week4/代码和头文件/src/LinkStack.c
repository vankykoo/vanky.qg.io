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
	//printf("��ʼ��ջ�ɹ���\n");
}

//��ջ
Status pushLStack(LinkStack *s,NodePtr np){
	if(s == NULL){
		printf("ջ�����ڣ�\n");
		return ERROR;
	}
	
	if(np != NULL){
		//����һ���µ�ջ��� 
		StackNode *newNode = NULL;
		newNode = (StackNode*)malloc(sizeof(StackNode));
		newNode->nodePtr = np;
		newNode->next = (*s).top;
		(*s).top = newNode;
		(*s).count += 1;
	}
	
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s){
	if(s == NULL || (*s).top == NULL){
		printf("ջ�����ڻ�ջΪ�գ�\n");
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
