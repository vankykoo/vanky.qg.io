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
			printf("\t\t\t输入错误！请重新输入：");
			scanf_s("%d", &choice);
		}
		switch (choice){
			case 1:
				//插入 
				insertSortPackage(arr);
				break;
			case 2:
				//归并 
				MergeSortPackage(arr,temp);
				break;
			case 3:
				//快速排序（递归）
				QuickSort_RecursionPackage(arr);
				break;
			case 4:
				//快速排序（非递归）
				QuickSortPackage(arr);
				break;
			case 5:
				//计数排序
				CountSortPackage(arr);
				break;
			case 6:
				//基数计数排序
				RadixCountSortPackage(arr,temp);
				break;
			case 7:
				//7.冒泡排序
				BubbleSortPackage(arr);
				break;			
			case 8:
				//颜色
				ColorSortPackage(arr);
				break;
			case 9:
				//找K大 
				findK_Package(arr);
				break;
			case 0:
				break;
			default:
			printf("输入错误，请重新选择！\n");
			break; 
		}
		if(arr != NULL){
			free(arr);
		}
		
		system("pause");
		system("cls");

	} while (choice);

	printf("退出成功");
	return 0;
}
