#include "Sort.h"
#include "LinkStack.h"

void swap(int*p1,int *p2){
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//�������� 
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

//�鲢���򣨺ϲ����飩
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int pointer1 = begin;//��һ������ָ�� 
	int pointer2 = mid + 1;//�ڶ�������ָ��
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

//�鲢���򣨵ݹ飩
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin >= end){
		return;
	}
	
	int mid = (begin + end) / 2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);
	
} 

//�������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin >= end){
		return;
	}
	int left = begin;
	int right = end;
	int pivot = Partition(a,begin,end);
	//��Ϊ��������ݹ�
	QuickSort_Recursion(a,left,pivot - 1);
	QuickSort_Recursion(a,pivot + 1,right);
}

int Partition(int *a, int begin, int end){
	//���������Ż���
	//�Ż�һ�����ѡ�񣬺�ֱ��ѡ���һ��һ�������ʶ������ 
	//�Ż���������ȡ�У����ﳢ����һ�֣��ֱ�ȡbegin��end��(begin+end)/2����������Ӧ����ȡ��
	int mid = (begin + end) / 2;
	int pivot = begin;
	//���м���
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
		//���ҿ�ʼ�� ,�ұ�a[pivot]С���� 
		while(a[end] >= a[pivot] && begin < end){
			end--;
		}
		while(a[begin] <= a[pivot] && begin < end){
			begin++;
		}
		swap(&a[begin],&a[end]); 
	}
	 
	//��ʱbegin==end����Ϊpivot����ȷλ�� 
	swap(&a[begin],&a[pivot]);
	
	return end;  
}

//�������򣨷ǵݹ�棩
void QuickSort(int *a,int size){
	LinkStack *L = NULL;
	L = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L);
	//�������β������ջ 
	pushLStack(L,0);
	pushLStack(L,size - 1);
	
	int begin,end;
	//��ջ��Ϊ��ʱ��˵������û����õ����� 
	while(!(isEmptyLStack(L))){
		popLStack(L,&end);
		popLStack(L,&begin);
		
		int pivot = Partition(a, begin,end);
		
		//������
		if (begin < pivot - 1){
			pushLStack(L,begin);
			pushLStack(L,pivot - 1);
		}
		if (pivot + 1 < end){
			pushLStack(L,pivot + 1);
			pushLStack(L,end);
		}
	}
	//����ջ 
	destroyLStack(L);
}

//��������С������ֵ����������ʺ� 
void CountSort(int *a, int size , int max){
	int i,j,k = 0;
	//�ҳ���Сֵ����ֹ���ָ���
	int min = a[0];
	for(i=1;i<size;i++){
		if(a[i]<min){
			min = a[i];
		}
	} 
	int *countArray;
	
	//�����������
	if(min < 0){
		countArray = (int*)malloc(sizeof(int)*(max- min + 1));
	} else{
		countArray = (int*)malloc(sizeof(int)*(max + 1));
	}
	
	//��ʼ���������� 
	for(i=0;i < max + 1;i++){
		countArray[i] = 0;
	}
	
	//���� 
	int data;//a[i] 
	for(i=0;i<size;i++){
		data = a[i];
		countArray[data]++;
	}
	
	//��ֵ��a������,i��countArray����ָ��(Ҳ�����ִ�С����j�����ָ�����k��a����ָ�� 
	for(i=0;i<max + 1;i++){
		//���������Ϊ0���Ϳ�ʼ��ֵ 
		if(countArray[i] != 0){
			for(j=0;j<countArray[i];j++){
				a[k++] = i;
			}
		}
	} 
}

//������������
void RadixCountSort(int *a,int size,int *tempArray){
	int max = a[0];
	int bit = 1;//λ��
	int maxBitNum = 0;//���λ���м�λ 
	int i;
	//�����ֵ
	for(i=1;i<size;i++){
		if(a[i] >= max){
			max = a[i];
		}
	} 
	
	//�����ֵ�м�λ��
	while(max / bit){
		maxBitNum++;
		bit *= 10;
	}
	bit = 1;//bit��ԭΪ1 
	
	//��ʱ���� ���ٿռ� 
	tempArray = (int*)malloc(sizeof(int)*size); 
	
	int bitNum = 0;
	while(maxBitNum--){
		//ͳ��ÿһλ��Ӧ���ֵĸ��� 
		int perBitCount[10] = {0};
		for(i=0;i<size;i++){
			bitNum = a[i] / bit % 10;
			perBitCount[bitNum]++;
		} 
		
		//��perBitCount�����е�ֵ��ǰ��һλ�����ۼӣ�����֪�����������ַ�����ʱ�����ʲôλ�� 
		for(i=1;i<size;i++){
			perBitCount[i] += perBitCount[i-1];
		}
		
		int tempArrayKey = 0;
		for(i=size - 1;i>=0;i--){
			bitNum = a[i] / bit %10;	//�õ���Ӧλ�������� 
			tempArrayKey = perBitCount[bitNum] - 1;	//�õ�Ӧ�÷ŵ���λ�� 
			tempArray[tempArrayKey] = a[i];
			perBitCount[bitNum]--;	//����֮����Ҫ-1����Ϊ���ܳ��ֶ����ͬ�Ķ�Ӧ���� 
		} 
		
		//�Ż�ԭ���� 
		for(i=0;i<size;i++){
			a[i] = tempArray[i];
		}
		
		bit *= 10;
	} 
	free(tempArray);
}

//��ɫ���� ��һ��for�� 
void ColorSort(int *a,int size){
	int i,j;
	int flag;//�Ƿ񽻻� 
	int *traPointer;//������ָ��
	int p1Key = 0,p2Key = size - 1;
	int *p1 = &a[p1Key], *p2 = &a[p2Key];
	for(i=0;i<=p2Key && p1Key<=p2Key;i++){
		traPointer = &a[i];
		flag = 0;
		if(*p2 < *traPointer){
			swap(p2,traPointer);
			flag = 1;
			if(*p2 == 2){
				p2 = &a[--p2Key];//������ָ��ǰ�� 
			}
		}
		if(*p1 > *traPointer){
			swap(p1,traPointer);
			flag = 1;
			if(*p1 == 0){
				p1 = &a[++p1Key];//������ָ�����
			}	
		}
		while(*p1 == 0 && p1Key+1 <= i){
			p1 = &a[++p1Key];
		}
		while(*p2 == 2 && p2Key-1 >= i){
			p2 = &a[--p2Key];
		}
		
		if(flag = 0){	//�������Ļ���ѭ��ָ����ƣ���Ȼ���� 
			i--;
		}	
		
	}
}

//Ѱ�ҵ�K�� 
void findK(int *a,int begin,int end,int K){
	int pivot = Partition(a, begin, end);
	if(pivot + 1 == K){
		printf("��%d�����Ϊ��%d\n",K,a[K-1]);
		return;
	}
	if(pivot < K){
		findK(a, pivot+1, end, K);
	}else if (pivot  >= K){
		findK(a, begin, pivot, K);
	}
}

//ð������ 
void BubbleSort(int *a,int size){
	int i,j;
	int flag = 1;//�Ż�1��1����0���� 
	int final;//�Ż�2����¼���Ƚϵ�λ�� 
	int begin = 0;//�Ż�3����ǰ�ȽϺ����Ƚϣ�begin��¼��ǰ�Ƚ����Ƚϵ�λ�� 
	int temp;
	int times = size - 1; 
	for(i=0;i<size - 1;i++){
		flag = 1;
		final = 0;
		for(j=begin;j < times;j++){//���Ƚ� 
			if(a[j] > a[j + 1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 0;	
				final = j;
			}
		}
		if(flag == 1){	//ѭ��δ�������ݽ������������� 
			return;
		}
		times = final;
		
		for(j=final;j > begin;j--){//��ǰ�Ƚ� 
			if(a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				flag = 0;	
			}
		}
		begin++;
		if(flag == 1){	//ѭ��δ�������ݽ������������� 
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



void ShowMenu() {	//�˵�
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��������\n");
	printf("\t\t			2.�鲢����\n");
	printf("\t\t			3.�������򣨵ݹ飩\n");
	printf("\t\t			4.�������򣨷ǵݹ飩\n");
	printf("\t\t			5.��������\n");
	printf("\t\t			6.������������\n");
	printf("\t\t			7.ð������\n");
	printf("\t\t			8.��ɫ����\n");
	printf("\t\t			9.Ѱ�ҵ�K������\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t\t        *****************************\n");
	printf("\t\t	       ˵�����ڰ���͵ھ������ֵ��ı�\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-9)��");
}

void SelectMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.�������ݽ�������\n");
	printf("\t\t			2.С�����ݶ������\n");
	printf("\t\t			3.���������Ƿ���ȷ\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(1-3)��");
}

//��������
void UpdateData(){
	srand(time(NULL));//�����
    FILE* src = fopen("Data_100.txt", "w+");

    setvbuf(src, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

	int i;
    for (i = 0; i < 100; i++)
    {
        fprintf(src, "%d\n", rand()%10000);//д���������.txt�ļ���
    }
    fclose(src);
} 


//���������װ�� 
void insertSortPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = NULL;
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    insertSort(arr,size);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݲ���������ʱ��%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��в�������100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
		    break;
		    
		    
		case 3:
			size = 15;

		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			insertSort(arr,size);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
		default:
		printf("�������������ѡ��");
		break;
	}

}

//�鲢�����װ�� 
void MergeSortPackage(int *arr,int *temp){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    MergeSort(arr,0,size - 1,temp);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݹ鲢������ʱ��%d ms\n", size, diff);
		    free(temp);
			break;
			
				
		case 2:
			size = 100;
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��й鲢����100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
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
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			MergeSort(arr,0,size - 1,temp);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			free(temp);
			break;
			
		default:
		printf("�������������ѡ��");
		break;
	}
	
	
}

//�������򣨵ݹ飩��װ�� 
void QuickSort_RecursionPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	int i;
	FILE* fp = fopen("Data_100.txt", "r"); 
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    QuickSort_Recursion(arr,0,size - 1);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݿ������򣨵ݹ飩��ʱ��%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��п������򣨵ݹ飩100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
		    break;
		    
		case 3:
			size = 15;
		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			QuickSort_Recursion(arr,0,size - 1);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("�������������ѡ��");
		break;
	}

}

//�������򣨷ǵݹ飩��װ�� 
void QuickSortPackage(int *arr){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    QuickSort(arr,size);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݿ������򣨷ǵݹ飩��ʱ��%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��п������򣨷ǵݹ飩100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
		    break;
		    
		case 3:
			size = 15;

		    arr = (int*)malloc(sizeof(int)*15);
		    fp = fopen("Data_100.txt", "r");
		    for (i = 0; i < 15; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			QuickSort(arr,size);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("�������������ѡ��");
		break;
	}

}

//���������װ�� 
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
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 max = arr[0]; 
			 for(i=1;i<size;i++){
			 	if(arr[i] > max){
			 		max = arr[i];
				 }
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    CountSort(arr,size,max);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݼ���������ʱ��%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			 
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��м�������100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
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
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			CountSort(arr,size,max);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("�������������ѡ��");
		break;
	}
}

//�������������װ�� 
void RadixCountSortPackage(int *arr,int *tempArray){
	int choice;
	int size = 0;
	int sum = 0;
	FILE* fp = fopen("Data_100.txt", "r");
	int i;
	
	SelectMenu();
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 3)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
			 printf("1.5w������\n");
			 printf("2.10w������\n");
			 printf("3.20w������\n");
			 printf("���������ѡ��");
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
			 	printf("�������");
			 	break;
			 }
			 printf("���Ժ󡣡���\n");
			 //��ʼʱ��
		    clock_t start = clock();
			
		    RadixCountSort(arr,size,tempArray);
		
		    //������ʱ
		    clock_t diff = clock() - start;
		    printf("%d�����ݻ�������������ʱ��%d ms\n", size, diff);
			break;
			
				
		case 2:
			size = 100;
			 
			printf("���Ժ󡣡���\n");
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
			printf("%d�����ݽ��л�����������100k����ʱ��%d ms\n", size, sum);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
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
		    
		    
		    printf("����ǰ��");
			for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			
			RadixCountSort(arr,size,tempArray);
		    
			printf("�����");
		    for(i=0;i<15;i++){
		    	printf("%5d",arr[i]);
			}
			printf("\n");
			break;
			
		default:
		printf("�������������ѡ��");
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
	printf("\t\t			1.10w�����ݽ�������\n");
	printf("\t\t			2.С�����ݶ������\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��");
	scanf_s("%d", &choice);
	while (!(choice >= 1 && choice <= 2)) {
		printf("\t\t\t����������������룺");
		scanf_s("%d", &choice);
	}
	switch (choice){
		case 1:
			 //�������ݽ�������
		 	size = 100000;
		    arr = (int*)malloc(sizeof(int)*100000);
		    FILE* fp = fopen("Data_10w.txt", "r");
		    for (i = 0; i < 100000; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
		    printf("���Ժ󣨿����е�ã�������\n");
			 //��ʼʱ��
		    clock_t start1 = clock();
		    BubbleSort(arr,size);
		    //������ʱ
		    int good = clock() - start1;
		    
		    for (i = 0; i < 100000; i++)
		    {
		        fscanf(fp, "%d", &arr[i]);
		    }
			 //��ʼʱ��
		    clock_t start2 = clock();
		    BubbleSortBefore(arr,size);
		    //������ʱ
		    int bad = clock() - start2;
		    
		    printf("�Ż�ǰ��%d������ð��������ʱ��%d ms\n", size, bad);
		    printf("�Ż���%d������ð��������ʱ��%d ms\n", size, good);
		    printf("�Ż�����Ż�ǰ��ʡ�˴�Լ��%d ms\n",(bad-good));
			break;
			
		case 2:
			size = 100;
			arr = (int*)malloc(sizeof(int)*100);
			fp = fopen("Data_100.txt", "r");
			printf("���Ժ󣨿����е�ã�������\n");
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
				
			printf("�Ż�ǰ��%d�����ݽ���100000��ð��������ʱ��%d ms\n", size, sumOfBad);
		    printf("�Ż���%d�����ݽ���100000��ð��������ʱ��%d ms\n", size, sumOfGood);
		    printf("�Ż�����Ż�ǰ��ʡ�˴�Լ��%d ms\n",sumOfBad-sumOfGood);
			printf("˵�����ȴ�ʱ��󲿷�Ϊ���������ʱ�䡣\n");
		    break;	
		    
		default:
		printf("�������������ѡ��");
		break;
	}
	
}

void ColorSortPackage(int *arr){
	printf("**********\n");
	printf("*��ɫ����*\n");
	printf("**********\n");
	int size = 15;
	int i = 0;
    arr = (int*)malloc(sizeof(int)*15);
    FILE* fp = fopen("Data_100.txt", "r");
    for (i = 0; i < 15; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    
    printf("����ǰΪ��");
    for(i=0;i<15;i++){
    	arr[i] %= 3;
    	printf("%d ",arr[i]);
	}
	printf("\n");
	
	ColorSort(arr,size);
	
	printf("�����Ϊ��");
	 for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
}


void findK_Package(int *arr){
	printf("**********\n");
	printf("*�ҵ�K�� *\n");
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
    
    printf("����ǰΪ��");
    for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n������Kֵ(1-15)��");
	scanf("%d",&K);
	while(!(K >= 1 && K <= 15)){
		printf("����������������룺");
		scanf("%d",&K);
	}
	printf("\n");
	findK(arr,0,14,K);
	printf("\n");
	insertSort(arr,15);//Ϊ����ʾ���������ʹ�ò������� 
	printf("���ڼ���Ľ��Ϊ��");
    for(i=0;i<15;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
}
