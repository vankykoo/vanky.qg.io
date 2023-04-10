#include "Queue.h" 

//��ʼ������ 
Status initLQueue(LinkQueue *s){
	if(s == NULL){
		printf("���б����٣������³�ʼ����\n");
		return ERROR; 
	}
	(*s).count = 0;
	(*s).head = NULL;
	(*s).tail = NULL;
	return SUCCESS;
}

//�����
Status pushLQueue(LinkQueue *s,NodePtr np){
	if(s == NULL){
		printf("���в����ڣ�\n");
		return ERROR;
	}	
	
	NodePtr nodePtr = (Node*)malloc(sizeof(Node));
	nodePtr = np; 
	//����һ�����н�� 
	QueueNode *newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->nodePtr = nodePtr;
	if((*s).count == 0){
		(*s).head = newNode;
		(*s).tail = newNode;
	}else{
		((*s).tail)->next = newNode;
		(*s).tail = ((*s).tail)->next;
	}
	(*s).count += 1;
	
	return SUCCESS;
}

//������
Status popLQueue(LinkQueue *s){
	if(s == NULL || (*s).head == NULL){
		printf("���в����ڻ����Ϊ�գ�\n");
		return ERROR;
	}
	
	QueueNode *head;
	head = (QueueNode*)malloc(sizeof(QueueNode));
	head = (*s).head;
	
	(*s).head = ((*s).head)->next;
	(*s).count -= 1;
	free(head);
	
	return SUCCESS;
}
