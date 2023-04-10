#include "binary_sort_tree.h"
#include "AVL_tree.h"

int main(){
	BinarySortTreePtr BST = (BinarySortTree*)malloc(sizeof(BinarySortTree));	
//	BinarySortTree Tree;
//	Tree.root = NULL;
//	BST = &Tree;
	BST_init(BST);
	BiTree biTree = NULL;
	char inputArr[50] = {0};
	int input;
	Status taller; 
	
	do{
		Menu();
		scanf("%s", &inputArr);
		input = inputJudgment(inputArr);
		while(!(input >= 0 && input <= 11)){
			printf("输入错误，请重新输入：");
			scanf("%s", &inputArr);
			input = inputJudgment(inputArr);
		};
		
		switch(input){
			case 1:
				TestInsert(BST);
				break;
			case 2:
				TestDelete(BST);
				break;
			case 3:
				TestSearch(BST);
				break;
			case 4:
				BST_preorderI(BST, visit);
				break;
			case 5:
				TestPreorderR(BST, visit);
				break;
			case 6:
				BST_inorderI(BST, visit);
				break;
			case 7:
				TestInorderR(BST, visit);
				break;
			case 8:
				BST_postorderI(BST, visit);
				break;
			case 9:
				TestPostorderR(BST, visit);
				break;
			case 10:
				BST_levelOrder(BST, visit);
				break;
			case 11:
				HeapTest();
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
