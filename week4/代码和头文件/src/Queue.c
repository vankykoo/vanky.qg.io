#include "Queue.h" 

//初始化队列 
Status initLQueue(LinkQueue *s){
	if(s == NULL){
		printf("队列被销毁！请重新初始化！\n");
		return ERROR; 
	}
	(*s).count = 0;
	(*s).head = NULL;
	(*s).tail = NULL;
	return SUCCESS;
}

//入队列
Status pushLQueue(LinkQueue *s,NodePtr np){
	if(s == NULL){
		printf("队列不存在！\n");
		return ERROR;
	}	
	
	NodePtr nodePtr = (Node*)malloc(sizeof(Node));
	nodePtr = np; 
	//创建一个队列结点 
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

//出队列
Status popLQueue(LinkQueue *s){
	if(s == NULL || (*s).head == NULL){
		printf("队列不存在或队列为空！\n");
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
