#include "LinkStack.h"

int main(){
	ElemType length,data;
	int input;
	char inputArr[20] = {0};
	LinkStack *L = NULL;
	L = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L);
	
	
	do{
		showMenu();
		scanf("%s", &inputArr);
		input = inputJudgment(inputArr);
		while(!(input >= 0 && input <= 9)){
			printf("输入错误，请重新输入：");
			scanf("%s", &inputArr);
			input = inputJudgment(inputArr);
		};
		
		switch(input){
			case 1:
				initLStack(L);
				break;
			case 2:
				isEmptyLStack(L);
				break;
			case 3:
				getTopLStack(L,&data);
				break;
			case 4:
				clearLStack(L);
				break;
			case 5:
				destroyLStack(L);
				L = NULL;
				break;
			case 6:
				LStackLength(L,&length);
				break;
			case 7:
				pushLStack(L,&data);
				break;
			case 8:
				popLStack(L,&data);
				break;
			case 9:
				L = getLinkStack();
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
