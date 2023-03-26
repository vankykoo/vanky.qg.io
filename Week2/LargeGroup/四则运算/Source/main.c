#include "Calculator.h"

int main(){
	int input;
	int flag = 1; 
	char inputArr[20] = {0};//输入格式判断 
	char equation[50] = {0};//算式输入 
	char output[50] = {0};//用于中途计算 
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
			printf("输入错误，请重新输入：");
			scanf("%s", &inputArr);
			input = inputJudgment(inputArr);
		};
		if(flag == 1){
			printf("请输入中缀表达式:"); 
			scanf("%s",&equation);
			bool isEquation = equaJudgment(equation);
			while(isEquation != true){
				printf("输入格式错误，请重新输入：");
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
					printf("请输入中缀表达式:"); 
					scanf("%s",&equation);
					bool isEquation = equaJudgment(equation);
					while(isEquation != true){
						printf("输入格式错误，请重新输入：");
						scanf("%s",&equation);
						isEquation = equaJudgment(equation);
					}
					inputForm(equation);
				}
				printf("输入成功！\n");
				break; 
			case 0:
				printf("退出成功！\n");
				break;
		}
		
		system("pause");
		system("cls");
	}while(input != 0);
	
	return 0;
}
