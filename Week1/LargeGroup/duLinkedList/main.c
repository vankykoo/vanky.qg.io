#include "duLinkedList.h"

int main() {
	int choice;
	void (*Visit)(ElemType) = visit;
	DuLinkedList Head = NULL;
	InitList_DuL(&Head);
	ElemType* data = NULL;
	DuLNode* pointer1 = NULL;
	DuLNode* pointer2 = NULL;
	do
	{
		ShowMenu();
		scanf_s("%d", &choice);
		while (!(choice >= 0 && choice <= 6)) {
			printf("\t\t\t输入错误！请重新输入：");
			scanf_s("%d", &choice);
		}
		switch (choice)
		{
		case 0:
			break;
		case 1:
			DestroyList_DuL(&Head);
			break;
		case 2:
			pointer1 = SelectDuLNode(Head);
			if(pointer1){
				pointer2 = CreateDuLNode();
				InsertBeforeList_DuL(pointer1, pointer2);
			}
			break;
		case 3:
			pointer1 = SelectDuLNode(Head);
			if(pointer1){
				pointer2 = CreateDuLNode();
				InsertAfterList_DuL(pointer1, pointer2);
			}
			break;
		case 4:
			pointer1 = SelectDuLNode(Head);
			DeleteList_DuL(pointer1, data);
			break;
		case 5:
			TraverseList_DuL(Head, Visit);
			break;
		case 6:
			InitList_DuL(&Head);
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	} while (choice);

	printf("退出成功");
	return 0;
}
