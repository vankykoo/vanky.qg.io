#include "Calculator.h"

int main(){
	int input;
	int flag = 1; 
	char inputArr[20] = {0};//�����ʽ�ж� 
	char equation[50] = {0};//��ʽ���� 
	char output[50] = {0};//������;���� 
	LinkStack *charL = NULL;
	LinkNumStack *numL = NULL;
	charL = (LinkStack*)malloc(sizeof(LinkStack));
	numL = (LinkNumStack*)malloc(sizeof(LinkNumStack));
	initLStack(charL);
	initLNumStack(numL);
	
	
	do{
		showMenu();
		scanf("%s", &inputArr);
		input = inputJudgment(inputArr);
		while(!(input >= 0 && input <= 3)){
			printf("����������������룺");
			scanf("%s", &inputArr);
			input = inputJudgment(inputArr);
		};
		if(flag == 1){
			printf("��������׺���ʽ:"); 
			scanf("%s",&equation);
			bool isEquation = equaJudgment(equation);
			while(isEquation != true){
				printf("�����ʽ�������������룺");
				scanf("%s",&equation);
				isEquation = equaJudgment(equation);
			}
			inputForm(equation);
			
			flag = 0;
		}
		
		switch(input){
			case 1:
				toPostfixAndShow(charL,equation,output);
				flag = 2;
				break;
			case 2:
				myCalculator(charL,numL,equation,output);
				flag = 2;
				break;
			case 3:
				if(flag == 2){
					printf("��������׺���ʽ:"); 
					scanf("%s",&equation);
					bool isEquation = equaJudgment(equation);
					while(isEquation != true){
						printf("�����ʽ�������������룺");
						scanf("%s",&equation);
						isEquation = equaJudgment(equation);
					}
					inputForm(equation);
				}
				printf("����ɹ���\n");
				break; 
			case 0:
				printf("�˳��ɹ���\n");
				break;
		}
		
		system("pause");
		system("cls");
	}while(input != 0);
	
	return 0;
}
