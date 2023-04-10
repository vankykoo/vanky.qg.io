#include "Heap.h"

//交换函数 
void swap(ElemType *a,ElemType *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//向上调整，保持堆的性质 
Status AdjustUp(HeapPtr H, int index){
	if(H == NULL){
		return ERROR;
	}
	
	while(index > 1 && H->arr[index / 2] < H->arr[index]){
		swap(&(H->arr[index / 2]),&(H->arr[index]));
		index /= 2;
	}
	return SUCCESS;
}

//向下调整，保持堆的性质 
Status AdjustDown(HeapPtr H, int index){
	if(!H){
		return ERROR;
	}
	while (2 * index <= H->count) {
        int i = 2 * index;
        
        if (i + 1 <= H->count && H->arr[i + 1] > H->arr[i]) {
            i += 1;
        }
        
        if (H->arr[index] >= H->arr[i]) {
            break;
        }
        
        swap(&H->arr[index], &H->arr[i]);
        index = i;
    }
    
    return SUCCESS;
}

//插入
Status Insert(HeapPtr H){
	if(!H){
		return ERROR;
	}
	
	if(H->count + 1 > MAXSIZE){
		return ERROR;
	}
	
	int data;
	printf("请输入你要插入的数据：");
	scanf("%d",&data);
	
	H->arr[H->count + 1] = data;
	H->count++;
	int index = H->count;
	AdjustUp(H,index);
	
	return SUCCESS;
}

//删除
Status Delete(HeapPtr H){
	int index;
	printf("请输入你要删除的数据的坐标：");
	scanf("%d",&index);
	
	if(index < 1 || index > H->count){
		printf("删除失败，坐标无效！\n");
		return ERROR;
	}
	
	int data = H->arr[index];
	swap(&(H->arr[index]),&(H->arr[H->count]));
	H->count--;
	AdjustUp(H, index);
	AdjustDown(H, index);
	printf("删除成功！删除的数据为：%d\n",data);
	return SUCCESS;
}

void TraverseHeap(HeapPtr H){
	if(H->count == 0){
		printf("堆为空！\n");
		return;
	}
	int i;
	for(i=0;i < (H->count);i++){
		printf("坐标%2d的数据为%d\n",i+1,H->arr[i+1]);
	}
}

//取堆顶数据
ElemType GetTopData(HeapPtr H){
	if(H->count == 0){
		printf("堆为空！\n");
		return;
	}
	printf("堆顶的数据为：%d\n",H->arr[1]);
	return H->arr[1];
}

//取堆的数据个数
ElemType GetHeapSize(HeapPtr H){
	printf("堆的数据个数为：%d\n",H->count);
	return H->count;
}

//判断堆是否为空 
Status IsEmpty(HeapPtr H){
	if(H->count == 0){
		printf("堆为空！\n");
		return SUCCESS;
	} else{
		printf("堆不为空！\n");
		return ERROR;
	}
}

//菜单 
void ShowMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.插入操作\n");
	printf("\t\t			2.删除操作\n");
	printf("\t\t			3.堆顶数据\n");
	printf("\t\t			4.堆的数据个数\n");
	printf("\t\t			5.判断堆是否为空\n");
	printf("\t\t			6.遍历堆\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t		提示：栈的数据为整数\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-6)：");
}

//测试 
void HeapTest(){
	HeapPtr H = (Heap*)malloc(sizeof(Heap));
	H->count = 0;
	int input;
	do{
		ShowMenu();
		printf("请输入你的选择：");
		scanf("%d",&input);
		while(!(input >= 0 && input <= 6)){
			printf("输入错误，请重新输入：");
			scanf("%d",&input);
		}
		switch(input){
			case 1:
				Insert(H);
				break;
			case 2:
				Delete(H);
				break;
			case 3:
				GetTopData(H);
				break;
			case 4:
				GetHeapSize(H);
				break;
			case 5:
				IsEmpty(H);
				break;
			case 6:
				TraverseHeap(H);
			case 0:
				break;
		}
		
		system("pause");
		system("cls");
		
	}while(input);
	
}














