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

//�ж϶����Ƿ�Ϊ��
Status isEmptyLQueue(LinkQueue *s){
	if(s == NULL){
		printf("���в����ڣ�\n");
		return ERROR;
	}else if((*s).count == 0){
		printf("����Ϊ�գ�\n");
		return SUCCESS; 
	}else{
		printf("���в�Ϊ�գ�\n");
		return ERROR;
	}
}

//�õ�������Ԫ��
Status getHeadQueue(LinkQueue *s,void *e){
	if(s == NULL || (*s).head == NULL){
		printf("���в����ڻ��߶���Ϊ�գ�\n"); 
		return ERROR;
	}
	
	LinkQueuePtr head;
	head = (QueueNode*)malloc(sizeof(QueueNode)); 
	head = (*s).head;
	e = (*head).data;
	int dataType = (*head).dataType;
	
	switch(dataType){
		case 1:
			printf("��������������Ϊ�������ͣ�����Ϊ %d\n",*(int*)(e));
			break;
		case 2:
			printf("��������������ΪС�����ͣ�����Ϊ %f\n",*(double*)(e));
			break;		
		case 3:
			printf("��������������Ϊ�ַ����ͣ�����Ϊ %s\n",(char*)(e));
			break;
	}
	
	return SUCCESS;
}

//��ն���
Status clearLQueue(LinkQueue *s){
	if(s == NULL || (*s).head == NULL){
		printf("���в����ڻ��߶���Ϊ�գ�\n"); 
		return ERROR;
	}
	
	LinkQueuePtr head;
	while((*s).count != 0){
		head = (QueueNode*)malloc(sizeof(QueueNode));
		head = (*s).head;
		(*s).head = head->next;
		free(head);
		(*s).count -= 1;
	}
	
	printf("�����ɣ�\n");
	return SUCCESS;
}

//���ٶ���
Status destroyLQueue(LinkQueue *s){
	if(s == NULL){
		printf("���в����ڻ����Ϊ�գ�\n");
		return ERROR;
	}
	LinkQueue *S = NULL;
	S = (LinkQueue*)malloc(sizeof(LinkQueue));
	S = s;
	
	LinkQueuePtr head;
	while((*s).count != 0){
		head = (QueueNode*)malloc(sizeof(QueueNode));
		head = (*s).head;
		(*s).head = head->next;
		free(head);
		(*s).count -= 1;
	}
	free(S);
	
	printf("���ٳɹ���\n");
	return SUCCESS;
}

//�����г���
Status LQueueLength(LinkQueue *s,int *length){
	if(s == NULL){
		printf("���в����ڣ�\n");
		return ERROR;
	}
	
	(*length) = (*s).count;
	printf("���еĳ��� = %d\n",(*length));
	
	return SUCCESS;
}

//�����
Status pushLQueue(LinkQueue *s,void* data){
	if(s == NULL){
		printf("���в����ڣ�\n");
		return ERROR;
	}	
	
	QueueNode *newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode = CreateQueueNode();
	int dataType = newNode->dataType;
	if((*s).count == 0){
		(*s).head = newNode;
		(*s).tail = newNode;
	}else{
		((*s).tail)->next = newNode;
		(*s).tail = ((*s).tail)->next;
	}
	(*s).count += 1;
	
	switch(dataType){
		case 1:
			data = (*newNode).data;
			printf("�ɹ�����У���Ԫ������Ϊ = %d\n",*(int*)(newNode->data));
			break;
		case 2:
			data = (*newNode).data;
			printf("�ɹ�����У���Ԫ������Ϊ = %f\n",*(double*)(newNode->data));
			break;
		case 3:
			data = (*newNode).data;
			printf("�ɹ�����У���Ԫ������Ϊ = %s\n",(char*)(newNode->data));
			break;
	}
	
	return SUCCESS;
}

//������
Status popLQueue(LinkQueue *s,void *data){
	if(s == NULL || (*s).head == NULL){
		printf("���в����ڻ����Ϊ�գ�\n");
		return ERROR;
	}
	
	QueueNode *head;
	head = (QueueNode*)malloc(sizeof(QueueNode));
	head = (*s).head;
	int dataType = head->dataType;
	data = head->data;
	
	switch(dataType){
		case 1:
			printf("��������������Ϊ�������ͣ�����Ϊ %d\n",*(int*)(data));
			break;
		case 2:
			printf("��������������ΪС�����ͣ�����Ϊ %f\n",*(double*)(data));
			break;		
		case 3:
			printf("��������������Ϊ�ַ����ͣ�����Ϊ %s\n",(char*)(data));
			break;
	}
	
	(*s).head = ((*s).head)->next;
	(*s).count -= 1;
	free(head);
	
	return SUCCESS;
}

//�������е�
QueueNode* CreateQueueNode(){
	char arr[20] = {0};
	int data;
	
	 
	char *arrs = (char*)malloc(sizeof(char) * 50);
	int *Integer;
	double *Double;
	
	char inputArr[20] = {0};
	printf("��ѡ���������ݵ����ͣ�\n");
	printf("1.����\n");
	printf("2.С��\n");
	printf("3.�ַ����ַ���\n"); 
	printf("���������ѡ��");
	scanf("%s", &inputArr);
	int input = inputJudgment(inputArr);
	while(!(input >= 1 && input <= 3)){
		printf("����������������룺");
		scanf("%s", &inputArr);
		input = inputJudgment(inputArr);
	};
	
	
	QueueNode *newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	
	
	switch(input){
		case 1:
			printf("������������ݣ�");
			Integer = (int*)malloc(sizeof(int));
			scanf("%d",Integer);
			break;
		case 2:
			Double = (double*)malloc(sizeof(double));
			printf("������������ݣ�");
			scanf("%lf",Double);
			break;
		case 3:
			printf("������������ݣ�");
			scanf("%s",arrs);
			break;
	}
	
	newNode->dataType = input;
	//��ֵ
	switch(input){
		case 1:
			newNode->data = Integer;
			break;
		case 2:
			newNode->data = Double;
			break;
		case 3:
			newNode->data = arrs;
			break;
	}
	newNode->next = NULL;
	return newNode; 
} 

ElemType inputJudgment(char arr[]){
	char arrs[20] = {0};
	int i,num,result = 0;
	for(i=0;arr[i] != '\0';i++){
		arrs[i] = arr[i];
	}
	arr[i] = '\0';
	
	int isInteger = 0;
	
	while(isInteger != 1){
		isInteger = 1;
		for(i=0;arrs[i] != '\0';i++){
			if(!(arrs[i] >= '0' && arrs[i] <= '9')){
				isInteger = 0;
				break;
			}
		}
		if(isInteger == 0){
			printf("�����ʽ�������������룺"); 
			scanf("%s",&arrs);
		}
	}
	
	if(isInteger == 1){
		for(i = 0;arrs[i] != '\0';i++){
			num = arrs[i] - '0';
			result = result * 10 + num;
		}
		
		return result;
	}
	
}

void showMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��ʼ������\n");
	printf("\t\t			2.�ж϶����Ƿ�Ϊ��\n");
	printf("\t\t			3.��ʾ������Ԫ��\n");
	printf("\t\t			4.��ն���\n");
	printf("\t\t			5.���ٶ���\n");
	printf("\t\t			6.�����г���\n");
	printf("\t\t			7.�����½�������\n");
	printf("\t\t			8.�����׽�������\n");
	printf("\t\t			9.����һ���µĶ��У����ٺ�����\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-9)��");
}

LinkQueue* getLinkQueue(LinkQueue *s){
	if(s != NULL){
		printf("���д��ڣ����迪���У�\n");
		return s; 
	}
	LinkQueue *L = (LinkQueue*)malloc(sizeof(LinkQueue));
	initLQueue(L);
	printf("�����гɹ���\n");
	return L;
}
