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
			printf("\t\t\t����������������룺");
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
			printf("��������Ҫ���ҽ������ݣ�");
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
			printf("�������������ѡ��");
			break;
		}

		system("pause");
		system("cls");
	} while (choice);

	printf("�˳��ɹ�");
	return 0;
}