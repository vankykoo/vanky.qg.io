#include "LinkedList.h"

int main() {
	int choice;
	void (*Visit)(ElemType) = visit;
	LinkedList Head = NULL;
	InitList(&Head);
	ElemType* data = NULL;
	data = (int*)malloc(sizeof(int));
	LinkedList pointer1 = NULL;
	LinkedList pointer2 = NULL;
	do
	{
		ShowMenu();
		scanf_s("%d", &choice);
		while (!(choice >= 0 && choice <= 10)) {
			printf("\t\t\t输入错误！请重新输入：");
			scanf_s("%d", &choice);
		}
		switch (choice)
		{
		case 0:
			break;
		case 1:
			DestroyList(&Head);
			free(Head);
			break;
		case 2:
			FindMidNode(&Head);
			break;
		case 3:
			pointer1 = SelectLNode(Head);
			if (pointer1) {
				pointer2 = CreateLNode();
				InsertList(pointer1, pointer2);
			}
			break;
		case 4:
			pointer1 = SelectLNode(Head);
			if (pointer1)
				DeleteList(pointer1, data);
			break;
		case 5:
			TraverseList(Head, Visit);
			break;
		case 6:
			InitList(&Head);
			break;
		case 7:
			printf("请输入你要查找结点的数据：");
			ElemType e;
			scanf_s("%d", &e);
			SearchList(Head, e);
			break;
		case 8:
			ReverseList(&Head);
			if(Head)
				TraverseList(Head, Visit);
			break;
		case 9:
			IsLoopList(Head);
			break;
		case 10:
			ReverseEvenList(&Head);
			TraverseList(Head, Visit);
			break;
		default:
			printf("输入错误，请重新选择！");
			break;
		}

		system("pause");
		system("cls");
	} while (choice);

	printf("退出成功");
	return 0;
}