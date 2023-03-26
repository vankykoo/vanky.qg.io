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

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s == NULL){
		printf("ջ�����ڣ�\n");
		return ERROR;
	}else if((*s).count == 0){
		printf("ջΪ�գ�\n");
		return SUCCESS; 
	}else{
		printf("ջ��Ϊ�գ�\n");
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s == NULL || (*s).top == NULL){
		printf("ջ�����ڻ���ջΪ�գ�\n"); 
		return ERROR;
	}
	
	LinkStackPtr top;
	top = (StackNode*)malloc(sizeof(StackNode));
	top = (*s).top;
	*e = (*top).data;
	printf("ջ��Ԫ������ = %d\n",(*e));
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(s == NULL || (*s).top == NULL){
		printf("ջ�����ڻ���ջΪ�գ�\n"); 
		return ERROR;
	}
	
	LinkStackPtr top;
	while((*s).count != 0){
		top = (StackNode*)malloc(sizeof(StackNode));
		top = (*s).top;
		(*s).top = top->next;
		free(top);
		(*s).count -= 1;
	}
	
	printf("�����ɣ�\n");
	return SUCCESS;
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
	
	printf("���ٳɹ���\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(s == NULL){
		printf("ջ�����ڣ�\n");
		return ERROR;
	}
	
	(*length) = (*s).count;
	printf("ջ�ĳ��� = %d\n",(*length));
	
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
	newNode = CreateStackNode();
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	data = (*newNode).data;
	printf("�ɹ���ջ����Ԫ������Ϊ = %d\n",data);
	
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
	printf("��ջ�ɹ�����ջԪ�ص�����Ϊ %d\n", *data);
	
	return SUCCESS;
}

//����ջ��
StackNode* CreateStackNode(){
	char arr[20] = {0};
	int data;
	//�ж������ʽ 
	printf("������ջ��Ԫ�����ݣ�");
	scanf_s("%s",&arr);
	data = inputJudgment(arr);
	StackNode *newNode = NULL;
	newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = data;
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
	printf("\t\t			1.��ʼ��ջ\n");
	printf("\t\t			2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t\t			3.�õ�ջ��Ԫ��\n");
	printf("\t\t			4.���ջ\n");
	printf("\t\t			5.����ջ\n");
	printf("\t\t			6.���ջ����\n");
	printf("\t\t			7.��ջ\n");
	printf("\t\t			8.��ջ\n");
	printf("\t\t			9.��ջ\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t		��ʾ��ջ������Ϊ����\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-9)��");
}

LinkStack* getLinkStack(){
	LinkStack *L = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L);
	printf("��ջ�ɹ���\n");
	return L;
}
