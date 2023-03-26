#include "Queue.h"

int main(){
	ElemType length;
	void *data = NULL;
	int input;
	char inputArr[20] = {0};
	LinkQueue *L = NULL;
	L = (LinkQueue*)malloc(sizeof(LinkQueue));
	initLQueue(L);
	
	
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
				initLQueue(L);
				break;
			case 2:
				isEmptyLQueue(L);
				break;
			case 3:
				getHeadQueue(L,&data);
				break;
			case 4:
				clearLQueue(L);
				break;
			case 5:
				destroyLQueue(L);
				L = NULL;
				break;
			case 6:
				LQueueLength(L,&length);
				break;
			case 7:
				pushLQueue(L,&data);
				break;
			case 8:
				popLQueue(L,&data);
				break;
			case 9:
				L = getLinkQueue(L);
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
