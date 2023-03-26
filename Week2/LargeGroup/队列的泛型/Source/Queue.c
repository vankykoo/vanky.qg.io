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

//判断队列是否为空
Status isEmptyLQueue(LinkQueue *s){
	if(s == NULL){
		printf("队列不存在！\n");
		return ERROR;
	}else if((*s).count == 0){
		printf("队列为空！\n");
		return SUCCESS; 
	}else{
		printf("队列不为空！\n");
		return ERROR;
	}
}

//得到队列首元素
Status getHeadQueue(LinkQueue *s,void *e){
	if(s == NULL || (*s).head == NULL){
		printf("队列不存在或者队列为空！\n"); 
		return ERROR;
	}
	
	LinkQueuePtr head;
	head = (QueueNode*)malloc(sizeof(QueueNode)); 
	head = (*s).head;
	e = (*head).data;
	int dataType = (*head).dataType;
	
	switch(dataType){
		case 1:
			printf("出队列数据类型为整数类型，数据为 %d\n",*(int*)(e));
			break;
		case 2:
			printf("出队列数据类型为小数类型，数据为 %f\n",*(double*)(e));
			break;		
		case 3:
			printf("出队列数据类型为字符类型，数据为 %s\n",(char*)(e));
			break;
	}
	
	return SUCCESS;
}

//清空队列
Status clearLQueue(LinkQueue *s){
	if(s == NULL || (*s).head == NULL){
		printf("队列不存在或者队列为空！\n"); 
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
	
	printf("清空完成！\n");
	return SUCCESS;
}

//销毁队列
Status destroyLQueue(LinkQueue *s){
	if(s == NULL){
		printf("队列不存在或队列为空！\n");
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
	
	printf("销毁成功！\n");
	return SUCCESS;
}

//检测队列长度
Status LQueueLength(LinkQueue *s,int *length){
	if(s == NULL){
		printf("队列不存在！\n");
		return ERROR;
	}
	
	(*length) = (*s).count;
	printf("队列的长度 = %d\n",(*length));
	
	return SUCCESS;
}

//入队列
Status pushLQueue(LinkQueue *s,void* data){
	if(s == NULL){
		printf("队列不存在！\n");
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
			printf("成功入队列，新元素数据为 = %d\n",*(int*)(newNode->data));
			break;
		case 2:
			data = (*newNode).data;
			printf("成功入队列，新元素数据为 = %f\n",*(double*)(newNode->data));
			break;
		case 3:
			data = (*newNode).data;
			printf("成功入队列，新元素数据为 = %s\n",(char*)(newNode->data));
			break;
	}
	
	return SUCCESS;
}

//出队列
Status popLQueue(LinkQueue *s,void *data){
	if(s == NULL || (*s).head == NULL){
		printf("队列不存在或队列为空！\n");
		return ERROR;
	}
	
	QueueNode *head;
	head = (QueueNode*)malloc(sizeof(QueueNode));
	head = (*s).head;
	int dataType = head->dataType;
	data = head->data;
	
	switch(dataType){
		case 1:
			printf("出队列数据类型为整数类型，数据为 %d\n",*(int*)(data));
			break;
		case 2:
			printf("出队列数据类型为小数类型，数据为 %f\n",*(double*)(data));
			break;		
		case 3:
			printf("出队列数据类型为字符类型，数据为 %s\n",(char*)(data));
			break;
	}
	
	(*s).head = ((*s).head)->next;
	(*s).count -= 1;
	free(head);
	
	return SUCCESS;
}

//创建队列点
QueueNode* CreateQueueNode(){
	char arr[20] = {0};
	int data;
	
	 
	char *arrs = (char*)malloc(sizeof(char) * 50);
	int *Integer;
	double *Double;
	
	char inputArr[20] = {0};
	printf("请选择输入数据的类型：\n");
	printf("1.整数\n");
	printf("2.小数\n");
	printf("3.字符或字符串\n"); 
	printf("请输入你的选择：");
	scanf("%s", &inputArr);
	int input = inputJudgment(inputArr);
	while(!(input >= 1 && input <= 3)){
		printf("输入错误，请重新输入：");
		scanf("%s", &inputArr);
		input = inputJudgment(inputArr);
	};
	
	
	QueueNode *newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	
	
	switch(input){
		case 1:
			printf("请输入你的数据：");
			Integer = (int*)malloc(sizeof(int));
			scanf("%d",Integer);
			break;
		case 2:
			Double = (double*)malloc(sizeof(double));
			printf("请输入你的数据：");
			scanf("%lf",Double);
			break;
		case 3:
			printf("请输入你的数据：");
			scanf("%s",arrs);
			break;
	}
	
	newNode->dataType = input;
	//赋值
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
			printf("输入格式错误！请重新输入："); 
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
	printf("\t\t			1.初始化队列\n");
	printf("\t\t			2.判断队列是否为空\n");
	printf("\t\t			3.显示队列首元素\n");
	printf("\t\t			4.清空队列\n");
	printf("\t\t			5.销毁队列\n");
	printf("\t\t			6.检测队列长度\n");
	printf("\t\t			7.创建新结点入队列\n");
	printf("\t\t			8.队列首结点出队列\n");
	printf("\t\t			9.开启一个新的队列（销毁后开启）\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-9)：");
}

LinkQueue* getLinkQueue(LinkQueue *s){
	if(s != NULL){
		printf("队列存在，无需开队列！\n");
		return s; 
	}
	LinkQueue *L = (LinkQueue*)malloc(sizeof(LinkQueue));
	initLQueue(L);
	printf("开队列成功！\n");
	return L;
}
