#include "Calculator.h" 

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

//��ʼ��ջ
Status initLNumStack(LinkNumStack *s){
	if(s == NULL){
		printf("ջ�����٣������³�ʼ����\n");
		return ERROR; 
	}
	(*s).count = 0;
	(*s).top = NULL;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	
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

//��ջ
Status pushLStack(LinkStack *s,char data){
	StackNode *newNode = NULL;
	newNode = (StackNode*)malloc(sizeof(StackNode));
	(*newNode).data = data;
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	
	return SUCCESS;
}

//���ַ���������ջ
int pushNumLStack(LinkNumStack *s,char *input,int index){
	NumStackNode *newNode = NULL;
	newNode = (NumStackNode*)malloc(sizeof(NumStackNode));
	double result=0,num=0;
	while(input[index] != '$'){
		num = input[index++] - '0';
		result = result * 10 + num; 
	}
	index++;
	(*newNode).data = result;
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	
	return index;
}

//ֱ��������ջ
Status pushDouble(LinkNumStack *s,double num){
	NumStackNode *newNode = NULL;
	newNode = (NumStackNode*)malloc(sizeof(NumStackNode)); 
	(*newNode).data = num;
	(*newNode).next = (*s).top;
	(*s).top = newNode;
	(*s).count += 1;
	
	return SUCCESS;
}
 

//��ջ
char popLStack(LinkStack *s){
	
	char output;
	
	StackNode *pop;
	pop = (StackNode*)malloc(sizeof(StackNode));
	pop = (*s).top;
	output = pop->data;
	(*s).top = ((*s).top)->next;
	(*s).count -= 1;
	free(pop);
	
	return output;
}

//������ջ����Ҫ�޸� 
double popNumLStack(LinkNumStack *s){
	
	double output = 0;
	
	NumStackNode *pop;
	pop = (NumStackNode*)malloc(sizeof(NumStackNode));
	pop = (*s).top;
	output = pop->data;
	(*s).top = ((*s).top)->next;
	(*s).count -= 1;
	free(pop);
	
	return output;
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

//��׺���ʽ��ʽ�ж� 
Status equaJudgment(char *input){
	int i,j;
	int temp;
	char operator[7] = {'+','-','*','/','(',')','$'};
	for(i = 0;input[i] != '\0';i++){
		temp = 0;
		for(j = 0;j < 7;j++){
			if(input[i] == operator[j]){
				temp = 1;
				break;
			}		
		}
		if(temp == 0 && !(input[i] >= '0' && input[i] <= '9')){
			return ERROR; 
		}
	} 
	
	return SUCCESS;
}

void inputForm(char *input){
	char output[50] = {0};
	int i,j=0;
	for(i=0;input[i] != '\0';){
		if(input[i] >= '0' && input[i] <= '9'){
			while(input[i] >= '0' && input[i] <= '9'){
				output[j++] = input[i++];
			}
			output[j++] = '$';
		}else{
			output[j++] = input[i++];
		}
	}
	for(i = 0,j = 0;output[i] != '\0';){
		input[i++] = output[j++];
	} 
	input[i] = '\0';
}


//������
void myCalculator(LinkStack *s,LinkNumStack *numLinkStack,char *input,char *output){
	bool isRight = equaJudgment(input);
	while(isRight == false){
		printf("����ĸ�ʽ�������������룺");
		scanf("%s", input); 
		isRight = equaJudgment(input);
	} 
	toPostfix(s,input,output);
	int i=0,j=0;
	double num1=0,num2=0,result=0;
	while(output[i] != '\0'){
		result = 0;
		switch(output[i]){
			case '+':
				num1 = popNumLStack(numLinkStack);
				num2 = popNumLStack(numLinkStack);
				result = num2 + num1;
				pushDouble(numLinkStack,result);
				i++;
				break;
			case '-':
				num1 = popNumLStack(numLinkStack);
				num2 = popNumLStack(numLinkStack);
				result = num2 - num1;
				pushDouble(numLinkStack,result);
				i++;
				break;
			case '*':
				num1 = popNumLStack(numLinkStack);
				num2 = popNumLStack(numLinkStack);
				result = num2 * num1;
				pushDouble(numLinkStack,result);
				i++;
				break;
			case '/':
				num1 = popNumLStack(numLinkStack);
				num2 = popNumLStack(numLinkStack);
				result = num2 / num1;
				pushDouble(numLinkStack,result);
				i++;
				break;
			
			default:
				i = pushNumLStack(numLinkStack,output,i);
		}

	}
	result = popNumLStack(numLinkStack);
	printf("������ = %.2f\n",result);
}

//��׺ת��׺
void toPostfix(LinkStack *s,char *input,char *output){
	int i = 0;
	int j = 0;
	StackNode *top;
	top = (StackNode*)malloc(sizeof(StackNode));
	top = (*s).top;
	
	while(input[i] != '\0'){
		switch(input[i]){
			case '(':
				pushLStack(s,'(');
				top = (*s).top;
				i++;
				break;
			case ')':
				while(top != NULL && top->data != '('){
					output[j] = top->data;
					popLStack(s);
					top = (*s).top;
					j++;
				}
				popLStack(s); 
				top = (*s).top;
				i++;
				break;
			case '+':
			case '-':
				while(top != NULL && (top->data == '*' || top->data == '/' || top->data == '+' || top->data == '-')){
					output[j] = top->data;
					popLStack(s);
					top = (*s).top;
					j++;
				}
				pushLStack(s,input[i]);
				top = (*s).top;
				i++;
				break;
			case '*':
			case '/':
				while(top != NULL && (top->data == '/' || top->data == '*')){
					output[j] = top->data;
					popLStack(s);
					top = (*s).top;
					j++;
				} 
				pushLStack(s,input[i]);
				top = (*s).top;
				i++;
				break;
			default:
				while(input[i] >= '0' && input[i] <= '9'){
					output[j++] = input[i++];
				}
				output[j++] = '$';
				i++;
				break;
		}
	}
	while(top != NULL){
		output[j++] = top->data;
		popLStack(s);
		top = (*s).top;
	}
	
} 


//��׺ת��׺���������
void toPostfixAndShow(LinkStack *s,char *input,char *output){
	toPostfix(s,input,output);
	int i,j;
	i = 0;
	double num1 = 0,result = 0;;
	while(output[i] != '\0'){
		switch(output[i]){
			case '+':
			case '-':
			case '*':
			case '/':
				printf("%c ",output[i]);
				i++;
				break;
			default:
				result = 0;
				while(output[i] >= '0' && output[i] <= '9'){
					num1 = output[i] - '0';
					result = result * 10 + num1;
					i++;
				}
				i++;
				printf("%.2f ",result);
		}

	}
} 

void showMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��ʾ��׺���ʽ\n");
	printf("\t\t			2.������\n");
	printf("\t\t			3.��������\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t\t----------------------------------------------\n");
	printf("\t\t	���� \n");
	printf("\t\t	��׺���ʽ��6 + ( 4 - 2 ) ��3 + 9 ��3 \n");
	printf("\t\t	��׺���ʽ��6 4 2 - 3 ��+ 9 3 ��+ \n");
	printf("\t\t\t----------------------------------------------\n");
	printf("\t\t		��ʾ����Ӣ�����뷨���룡\n");
	printf("\t\t		��ʾ������Ϊ'/'���˺�Ϊ'*'\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-3)��");
}




































