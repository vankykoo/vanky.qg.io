#include "Sort.h"
#include "LinkStack.h"

void swap(int*p1,int *p2){
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//插入排序 
void insertSort(int *a,int n){
	int i,j,pointer;
	for(i=1;i<n;i++){
		pointer = i;
		for(j=i-1;j>=0;j--){
			if(a[pointer] < a[j]){
				swap(&a[pointer],&a[j]);
				pointer = j;
			}
		}
	}
}

//归并排序（合并数组）
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int pointer1 = begin;//第一个数组指针 
	int pointer2 = mid + 1;//第二个数组指针
	int i = 0;
	while(pointer1 <= mid && pointer2 <= end){
		if(a[pointer1] <= a[pointer2]){
			temp[i++] = a[pointer1++];
		}else{
			temp[i++] = a[pointer2++];
		}
	}
	
	while(pointer1 <= mid){
		temp[i++] = a[pointer1++];
	}
	while(pointer2 <= end){
		temp[i++] = a[pointer2++];
	}
	
	int length = end - begin + 1;
	for(i=0;i<length;i++){
		a[begin + i] = temp[i];
	}
	
}

//归并排序（递归）
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin >= end){
		return;
	}
	
	int mid = (begin + end) / 2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);
	
} 

//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin >= end){
		return;
	}
	int left = begin;
	int right = end;
	int pivot = Partition(a,begin,end);
	//分为两个区间递归
	QuickSort_Recursion(a,left,pivot - 1);
	QuickSort_Recursion(a,pivot + 1,right);
}

int Partition(int *a, int begin, int end){
	//快速排序优化：
	//优化一：随机选择，和直接选择第一个一样，本质都是随机 
	//优化二：三数取中，这里尝试这一种，分别取begin，end，(begin+end)/2，这三个对应的数取中
	int mid = (begin + end) / 2;
	int pivot = begin;
	//找中间数
	if(a[begin] >= a[end]){
		if(a[begin] > a[mid]){
			swap(&a[mid],&a[begin]);
		}
	} else{
		if(a[end] <= a[mid]){
			swap(&a[end],&a[begin]);
		}else{
			swap(&a[mid],&a[begin]);
		}
	}
	
	while(begin < end){
		//从右开始走 ,找比a[pivot]小的数 
		while(a[end] >= a[pivot] && begin < end){
			end--;
		}
		while(a[begin] <= a[pivot] && begin < end){
			begin++;
		}
		swap(&a[begin],&a[end]); 
	}
	 
	//此时begin==end，且为pivot的正确位置 
	swap(&a[begin],&a[pivot]);
	
	return end;  
}

//快速排序（非递归版）
void QuickSort(int *a,int size){
	LinkStack *L = NULL;
	L = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L);
	//数组的首尾坐标入栈 
	pushLStack(L,0);
	pushLStack(L,size - 1);
	
	int begin,end;
	//当栈不为空时，说明还有没排序好的区间 
	while(!(isEmptyLStack(L))){
		popLStack(L,&end);
		popLStack(L,&begin);
		
		int pivot = Partition(a, begin,end);
		
		//分区间
		if (begin < pivot - 1){
			pushLStack(L,begin);
			pushLStack(L,pivot - 1);
		}
		if (pivot + 1 < end){
			pushLStack(L,pivot + 1);
			pushLStack(L,end);
		}
	}
	//销毁栈 
	destroyLStack(L);
}

//计数排序：小数、最值相差大的数不适合 
void CountSort(int *a, int size , int max){
	int i,j,k = 0;
	//找出最小值，防止出现负数
	int min = a[0];
	for(i=1;i<size;i++){
		if(a[i]<min){
			min = a[i];
		}
	} 
	int *countArray;
	
	//定义计数数组
	if(min < 0){
		countArray = (int*)malloc(sizeof(int)*(max- min + 1));
	} else{
		countArray = (int*)malloc(sizeof(int)*(max + 1));
	}
	
	//初始化计数数组 
	for(i=0;i < max + 1;i++){
		countArray[i] = 0;
	}
	
	//计数 
	int data;//a[i] 
	for(i=0;i<size;i++){
		data = a[i];
		countArray[data]++;
	}
	
	//赋值到a数组中,i是countArray遍历指针(也是数字大小），j是数字个数，k是a数组指针 
	for(i=0;i<max + 1;i++){
		//如果个数不为0，就开始赋值 
		if(countArray[i] != 0){
			for(j=0;j<countArray[i];j++){
				a[k++] = i;
			}
		}
	} 
}

//基数计数排序
void RadixCountSort(int *a,int size,int *tempArray){
	int max = a[0];
	int bit = 1;//位数
	int maxBitNum = 0;//最高位数有几位 
	int i;
	//找最大值
	for(i=1;i<size;i++){
		if(a[i] >= max){
			max = a[i];
		}
	} 
	
	//求最大值有几位数
	while(max / bit){
		maxBitNum++;
		bit *= 10;
	}
	bit = 1;//bit还原为1 
	
	//临时数组 开辟空间 
	tempArray = (int*)malloc(sizeof(int)*size); 
	
	int bitNum = 0;
	while(maxBitNum--){
		//统计每一位对应数字的个数 
		int perBitCount[10] = {0};
		for(i=0;i<size;i++){
			bitNum = a[i] / bit % 10;
			perBitCount[bitNum]++;
		} 
		
		//将perBitCount数组中的值于前面一位依次累加，方便知道后续把数字放入临时数组的什么位置 
		for(i=1;i<size;i++){
			perBitCount[i] += perBitCount[i-1];
		}
		
		int tempArrayKey = 0;
		for(i=size - 1;i>=0;i--){
			bitNum = a[i] / bit %10;	//得到对应位数的数字 
			tempArrayKey = perBitCount[bitNum] - 1;	//得到应该放到的位置 
			tempArray[tempArrayKey] = a[i];
			perBitCount[bitNum]--;	//放入之后需要-1，因为可能出现多个相同的对应数字 
		} 
		
		//放回原数组 
		for(i=0;i<size;i++){
			a[i] = tempArray[i];
		}
		
		bit *= 10;
	} 
	free(tempArray);
}

//颜色排序 （一个for） 
void ColorSort(int *a,int size){
	int i,j;
	int flag;//是否交换 
	int *traPointer;//遍历的指针
	int p1Key = 0,p2Key = size - 1;
	int *p1 = &a[p1Key], *p2 = &a[p2Key];
	for(i=0;i<=p2Key && p1Key<=p2Key;i++){
		traPointer = &a[i];
		flag = 0;
		if(*p2 < *traPointer){
			swap(p2,traPointer);
			flag = 1;
			if(*p2 == 2){
				p2 = &a[--p2Key];//交换后指针前移 
			}
		}
		if(*p1 > *traPointer){
			swap(p1,traPointer);
			flag = 1;
			if(*p1 == 0){
				p1 = &a[++p1Key];//交换后指针后移
			}	
		}
		while(*p1 == 0 && p1Key+1 <= i){
			p1 = &a[++p1Key];
		}
		while(*p2 == 2 && p2Key-1 >= i){
			p2 = &a[--p2Key];
		}
		
		if(flag = 0){	//交换过的话，循环指针后移，不然不动 
			i--;
		}	
		
	}
}

//寻找第K大 
void findK(int *a,int begin,int end,int K){
	int pivot = Partition(a, begin, end);
	if(pivot + 1 == K){
		printf("第%d大的数为：%d\n",K,a[K-1]);
		return;
	}
	if(pivot < K){
		findK(a, pivot+1, end, K);
	}else if (pivot  >= K){
		findK(a, begin, pivot, K);
	}
}

//冒泡排序 
void BubbleSort(int *a,int size){
	int i,j;
	int flag = 1;//优化1：1有序，0无序 
	int final;//优化2：记录最后比较的位置 
	int begin = 0;//优化3：向前比较后，向后比较，begin记录向前比较最后比较的位置 
	int temp;
	int times = size - 1; 
	for(i=0;i<size - 1;i++){
		flag = 1;
		final = 0;
		for(j=begin;j < times;j++){//向后比较 
			if(a[j] > a[j + 1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 0;	
				final = j;
			}
		}
		if(flag == 1){	//循环未进行数据交换，代表有序 
			return;
		}
		times = final;
		
		for(j=final;j > begin;j--){//向前比较 
			if(a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				flag = 0;	
			}
		}
		begin++;
		if(flag == 1){	//循环未进行数据交换，代表有序 
			return;
		}
	}
}

void BubbleSortBefore(int *arr,int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}



void ShowMenu() {	//菜单
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.插入排序\n");
	printf("\t\t			2.归并排序\n");
	printf("\t\t			3.快速排序（递归）\n");
	printf("\t\t			4.快速排序（非递归）\n");
	printf("\t\t			5.计数排序\n");
	printf("\t\t			6.基数计数排序\n");
	printf("\t\t			7.冒泡排序\n");
	printf("\t\t			8.颜色排序\n");
	printf("\t\t			9.寻找第K大排序\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t\t        *****************************\n");
	printf("\t\t	       说明：第八项和第九项的数值会改变\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-9)：");
}

void SelectMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.大量数据进行排序\n");
	printf("\t\t			2.小量数据多次排序\n");
	printf("\t\t			3.检验排序是否正确\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(1-3)：");
}

//更新数组
void UpdateData(){
	srand(time(NULL));//随机数
    FILE* src = fopen("Data_100.txt", "w+");

    setvbuf(src, NULL, _IONBF, 0);//设置缓冲模式为无缓冲

	int i;
    for (i = 0; i < 100; i++)
    {
        fprintf(src, "%d\n", rand()%10000);//写入随机数到.txt文件中
    }
    fclose(src);
} 


//插入排序封装后 
void insertSortPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = NULL;
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){

			    arr = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){

			    arr = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){

			    arr = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    insertSort(arr,size);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据插入排序用时：%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			for(i=0;i<100000;i++){
				//CreateArray(arr,4);

				int j;
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }

		    	clock_t start = clock();
				insertSort(arr,size);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行插入排序100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;
		    
		    
		case 3:
			size = 15;

		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			insertSort(arr,size);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
		default:
		printf("输入错误，请重新选择！");
		break;
	}

}

//归并排序封装后 
void MergeSortPackage(int *arr,int *temp){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){

			    arr = (int*)malloc(sizeof(int)*50000);
			    temp = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){

			    arr = (int*)malloc(sizeof(int)*100000);
			    temp = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){

			    arr = (int*)malloc(sizeof(int)*200000);
			    temp = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    MergeSort(arr,0,size - 1,temp);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据归并排序用时：%d ms\n", size, diff);
		    free(temp);
			break;
			
				
		case 2:
			size = 100;
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			temp = (int*)malloc(sizeof(int)*100);
			for(i=0;i<100000;i++){
				//CreateArray(arr,4);

				int j;
			    
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }

		    	clock_t start = clock();
				MergeSort(arr,0,size - 1,temp);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行归并排序100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
			free(temp);
		    break;
		    
		case 3:
			size = 15;
			int i;
		    arr = (int*)malloc(sizeof(int)*15);
		    temp = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			MergeSort(arr,0,size - 1,temp);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			free(temp);
			break;
			
		default:
		printf("输入错误，请重新选择！");
		break;
	}
	
	
}

//快速排序（递归）封装后 
void QuickSort_RecursionPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	int i;
	FILE* fp = fopen("Data_100.txt", "r"); 
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){
			 	//CreateArray(arr,1);
			 	
			    arr = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){
			 	//CreateArray(arr,2);
			 	
			    arr = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){

			    arr = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    QuickSort_Recursion(arr,0,size - 1);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据快速排序（递归）用时：%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			for(i=0;i<100000;i++){
				//CreateArray(arr,4);

				int j;
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }

		    	clock_t start = clock();
				QuickSort_Recursion(arr,0,size - 1);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行快速排序（递归）100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;
		    
		case 3:
			size = 15;
		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			QuickSort_Recursion(arr,0,size - 1);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("输入错误，请重新选择！");
		break;
	}

}

//快速排序（非递归）封装后 
void QuickSortPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){

			    arr = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){

			    arr = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){

			    arr = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    QuickSort(arr,size);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据快速排序（非递归）用时：%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			for(i=0;i<100000;i++){
				
				int j;
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }

		    	clock_t start = clock();
				QuickSort(arr,size);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行快速排序（非递归）100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;
		    
		case 3:
			size = 15;

		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			QuickSort(arr,size);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("输入错误，请重新选择！");
		break;
	}

}

//计数排序封装后 
void CountSortPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	int max = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){

			    arr = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){

			    arr = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){

			    arr = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 max = arr[0]; 
			 for(i=1;i<size;i++){
			 	if(arr[i] > max){
			 		max = arr[i];
				 }
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    CountSort(arr,size,max);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据计数排序用时：%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			 
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			for(i=0;i<100000;i++){
				

				int j;
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }
			    
			    max = arr[0]; 
				for(j=1;j<size;j++){
				 	if(arr[j] > max){
				 		max = arr[j];
					 }
				 }
			    

		    	clock_t start = clock();
				CountSort(arr,size,max);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行计数排序100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;
		    
		case 3:
			size = 15;
			int i;
		    arr = (int*)malloc(sizeof(int)*15);
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    max = arr[0]; 
			 for(i=1;i<size;i++){
			 	if(arr[i] > max){
			 		max = arr[i];
				 }
			 }
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			CountSort(arr,size,max);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("输入错误，请重新选择！");
		break;
	}
}

//基数计数排序封装后 
void RadixCountSortPackage(int *arr,int *tempArray){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
			 printf("1.5w数据量\n");
			 printf("2.10w数据量\n");
			 printf("3.20w数据量\n");
			 printf("请输入你的选择：");
			 scanf("%d",&choice);
			 if(choice == 1){
			 	//CreateArray(arr,1);
			 	
			 	int i;
			    arr = (int*)malloc(sizeof(int)*50000);
			    fp = fopen("Data_5w.txt", "r");
			    for (i = 0; i < 50000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 50000;
			 }else if(choice == 2){
			 	//CreateArray(arr,2);
			 	
			 	int i;
			    arr = (int*)malloc(sizeof(int)*100000);
			    fp = fopen("Data_10w.txt", "r");
			    for (i = 0; i < 100000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }
			 	
			 	size = 100000;
			 }else if(choice == 3){
//			 	CreateArray(arr,3);

				int i;
			    arr = (int*)malloc(sizeof(int)*200000);
			    fp = fopen("Data_20w.txt", "r");
			    for (i = 0; i < 200000; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

			 	size = 200000;
			 }else{
			 	printf("输入错误！");
			 	break;
			 }
			 printf("请稍后。。。\n");
			 //开始时间
		    clock_t start = clock();
			
		    RadixCountSort(arr,size,tempArray);
		
		    //计算用时
		    clock_t diff = clock() - start;
		    printf("%d条数据基数计数排序用时：%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			 
			printf("请稍后。。。\n");
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			for(i=0;i<100000;i++){
				//CreateArray(arr,4);

				int i;
			    for (i = 0; i < 100; i++)
			    {
			        fscanf(fp, "%d", &arr[i]);
			    }

		    	clock_t start = clock();
				RadixCountSort(arr,size,tempArray);
				clock_t diff = clock() - start;
				
				sum += diff;
			}
			printf("%d条数据进行基数计数排序100k次用时：%d ms\n", size, sum);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;
		    
		case 3:
			size = 15;
			int i;
		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    
		    printf("排序前：");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			RadixCountSort(arr,size,tempArray);
		    
			printf("排序后：");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("输入错误，请重新选择！");
		break;
	}
}

void BubbleSortPackage(int *arr){
	int choice;
	int size = 0;
	int good = 0,bad = 0;
	int sumOfGood = 0,sumOfBad = 0; 
	FILE* fp = fopen("Data_10w.txt", "r");
	int i,j;
	
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.10w条数据进行排序\n");
	printf("\t\t			2.小量数据多次排序\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择：");
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 2)) {
		printf("\t\t\t输入错误！请重新输入：");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //大量数据进行排序
		 	size = 100000;
		    arr = (int*)malloc(sizeof(int)*100000);
		    FILE* fp = fopen("Data_10w.txt", "r");
		    for (i = 0; i < 100000; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    printf("请稍后（可能有点久）。。。\n");
			 //开始时间
		    clock_t start1 = clock();
		    BubbleSort(arr,size);
		    //计算用时
		    int good = clock() - start1;
		    
		    for (i = 0; i < 100000; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
			 //开始时间
		    clock_t start2 = clock();
		    BubbleSortBefore(arr,size);
		    //计算用时
		    int bad = clock() - start2;
		    
		    printf("优化前：%d条数据冒泡排序用时：%d ms\n", size, bad);
		    printf("优化后：%d条数据冒泡排序用时：%d ms\n", size, good);
		    printf("优化后比优化前节省了大约：%d ms\n",(bad-good));
			break;
			
		case 2:
			size = 100;
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			printf("请稍后（可能有点久）。。。\n");
			for(i=0;i<100000;i++){
			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }
		    	clock_t start1 = clock();
				BubbleSort(arr,size);
				clock_t diff = clock() - start1;
				
				sumOfGood += diff;
			}
			
			for(i=0;i<100000;i++){

			    for (j = 0; j < 100; j++)
			    {
			        fscanf(fp, "%d", &arr[j]);
			    }
		    	clock_t start2 = clock();
				BubbleSortBefore(arr,size);
				clock_t diff = clock() - start2;
				
				sumOfBad += diff;
			}
				
			printf("优化前：%d条数据进行100000次冒泡排序用时：%d ms\n", size, sumOfBad);
		    printf("优化后：%d条数据进行100000次冒泡排序用时：%d ms\n", size, sumOfGood);
		    printf("优化后比优化前节省了大约：%d ms\n",sumOfBad-sumOfGood);
			printf("说明：等待时间大部分为更新数组的时间。\n");
		    break;	
		    
		default:
		printf("输入错误，请重新选择！");
		break;
	}
	
}

void ColorSortPackage(int *arr){
	printf("**********\n");
	printf("*颜色排序*\n");
	printf("**********\n");
	int size = 15;
	int i = 0;
    arr = (int*)malloc(sizeof(int)*15);
    FILE* fp = fopen("Data_100.txt", "r");
    for (i = 0; i < 15; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    
    printf("排序前为：");
    for(i=0;i<15;i++){
    	arr[i] %= 3;
    	printf("%d ",arr[i]);
	}
	printf("\n");
	
	ColorSort(arr,size);
	
	printf("排序后为：");
	 for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
}


void findK_Package(int *arr){
	printf("**********\n");
	printf("*找第K大 *\n");
	printf("**********\n");
	int size = 15;
	int i = 0;
	int K;
    arr = (int*)malloc(sizeof(int)*15);
    FILE* fp = fopen("Data_100.txt", "r");
    for (i = 0; i < 15; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    
    printf("排序前为：");
    for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n请输入K值(1-15)：");
	scanf("%d",&K);
	while(!(K >= 1 && K <= 15)){
		printf("输入错误！请重新输入：");
		scanf("%d",&K);
	}
	printf("\n");
	findK(arr,0,14,K);
	printf("\n");
	insertSort(arr,15);//为了显示排序后结果，使用插入排序 
	printf("用于检验的结果为：");
    for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
}
