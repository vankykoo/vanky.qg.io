#include "Heap.h"

//�������� 
void swap(ElemType *a,ElemType *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//���ϵ��������ֶѵ����� 
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

//���µ��������ֶѵ����� 
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

//����
Status Insert(HeapPtr H){
	if(!H){
		return ERROR;
	}
	
	if(H->count + 1 > MAXSIZE){
		return ERROR;
	}
	
	int data;
	printf("��������Ҫ��������ݣ�");
	scanf("%d",&data);
	
	H->arr[H->count + 1] = data;
	H->count++;
	int index = H->count;
	AdjustUp(H,index);
	
	return SUCCESS;
}

//ɾ��
Status Delete(HeapPtr H){
	int index;
	printf("��������Ҫɾ�������ݵ����꣺");
	scanf("%d",&index);
	
	if(index < 1 || index > H->count){
		printf("ɾ��ʧ�ܣ�������Ч��\n");
		return ERROR;
	}
	
	int data = H->arr[index];
	swap(&(H->arr[index]),&(H->arr[H->count]));
	H->count--;
	AdjustUp(H, index);
	AdjustDown(H, index);
	printf("ɾ���ɹ���ɾ��������Ϊ��%d\n",data);
	return SUCCESS;
}

void TraverseHeap(HeapPtr H){
	if(H->count == 0){
		printf("��Ϊ�գ�\n");
		return;
	}
	int i;
	for(i=0;i < (H->count);i++){
		printf("����%2d������Ϊ%d\n",i+1,H->arr[i+1]);
	}
}

//ȡ�Ѷ�����
ElemType GetTopData(HeapPtr H){
	if(H->count == 0){
		printf("��Ϊ�գ�\n");
		return;
	}
	printf("�Ѷ�������Ϊ��%d\n",H->arr[1]);
	return H->arr[1];
}

//ȡ�ѵ����ݸ���
ElemType GetHeapSize(HeapPtr H){
	printf("�ѵ����ݸ���Ϊ��%d\n",H->count);
	return H->count;
}

//�ж϶��Ƿ�Ϊ�� 
Status IsEmpty(HeapPtr H){
	if(H->count == 0){
		printf("��Ϊ�գ�\n");
		return SUCCESS;
	} else{
		printf("�Ѳ�Ϊ�գ�\n");
		return ERROR;
	}
}

//�˵� 
void ShowMenu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.�������\n");
	printf("\t\t			2.ɾ������\n");
	printf("\t\t			3.�Ѷ�����\n");
	printf("\t\t			4.�ѵ����ݸ���\n");
	printf("\t\t			5.�ж϶��Ƿ�Ϊ��\n");
	printf("\t\t			6.������\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t		��ʾ��ջ������Ϊ����\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-6)��");
}

//���� 
void HeapTest(){
	HeapPtr H = (Heap*)malloc(sizeof(Heap));
	H->count = 0;
	int input;
	do{
		ShowMenu();
		printf("���������ѡ��");
		scanf("%d",&input);
		while(!(input >= 0 && input <= 6)){
			printf("����������������룺");
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














