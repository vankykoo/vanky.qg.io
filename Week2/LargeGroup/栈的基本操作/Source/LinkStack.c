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

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s == NULL){
		printf("栈不存在！\n");
		return ERROR;
	}else if((*s).count == 0){
		printf("栈为空！\n");
		return SUCCESS; 
	}else{
		printf("栈不为空！\n");
		return ERROR;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s == NULL || (*s).top == NULL){
		printf("栈不存在或者栈为空！\n"); 
		return ERROR;
	}
	
	LinkStackPtr top;
	top = (StackNode*)malloc(sizeof(StackNode));
	top = (*s).top;
	*e = (*top).data;
	printf("栈顶元素数据 = %d\n",(*e));
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	if(s == NULL || (*s).top == NULL){
		printf("栈不存在或者栈为空！\n"); 
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
	
	printf("清空完成！\n");
	return SUCCESS;
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
	
	printf("销毁成功！\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s == NULL){
		printf("栈不存在！\n");
		return ERROR;
	}
	
	(*length) = (*s).count;
	printf("栈的长度 = %d\n",(*length));
	
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
	newNode = CreateStackNode();
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	data = (*newNode).data;
	printf("成功入栈，新元素数据为 = %d\n",data);
	
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
	printf("出栈成功！出栈元素的数据为 %d\n", *data);
	
	return SUCCESS;
}

//创建栈点
StackNode* CreateStackNode(){
	char arr[20] = {0};
	int data;
	//判断输入格式 
	printf("请输入栈的元素数据：");
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
	printf("\t\t			1.初始化栈\n");
	printf("\t\t			2.判断栈是否为空\n");
	printf("\t\t			3.得到栈顶元素\n");
	printf("\t\t			4.清空栈\n");
	printf("\t\t			5.销毁栈\n");
	printf("\t\t			6.检测栈长度\n");
	printf("\t\t			7.入栈\n");
	printf("\t\t			8.出栈\n");
	printf("\t\t			9.开栈\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t		提示：栈的数据为整数\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-9)：");
}

LinkStack* getLinkStack(){
	LinkStack *L = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L);
	printf("开栈成功！\n");
	return L;
}
