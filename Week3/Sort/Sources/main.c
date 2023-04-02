#include "Sort.h"
#include "LinkStack.h"

int main() {
	int *arr = NULL;
	int *temp;
	int choice;
	do
	{
		UpdateData();
		ShowMenu();
		scanf_s("%d", &choice);
		while (!(choice >= 0 && choice <= 10)) {
			printf("\t\t\t����������������룺");
			scanf_s("%d", &choice);
		}
		switch (choice){
			case 1:
				//���� 
				insertSortPackage(arr);
				break;
			case 2:
				//�鲢 
				MergeSortPackage(arr,temp);
				break;
			case 3:
				//�������򣨵ݹ飩
				QuickSort_RecursionPackage(arr);
				break;
			case 4:
				//�������򣨷ǵݹ飩
				QuickSortPackage(arr);
				break;
			case 5:
				//��������
				CountSortPackage(arr);
				break;
			case 6:
				//������������
				RadixCountSortPackage(arr,temp);
				break;
			case 7:
				//7.ð������
				BubbleSortPackage(arr);
				break;			
			case 8:
				//��ɫ
				ColorSortPackage(arr);
				break;
			case 9:
				//��K�� 
				findK_Package(arr);
				break;
			case 0:
				break;
			default:
			printf("�������������ѡ��\n");
			break; 
		}
		if(arr != NULL){
			free(arr);
		}
		
		system("pause");
		system("cls");

	} while (choice);

	printf("�˳��ɹ�");
	return 0;
}
