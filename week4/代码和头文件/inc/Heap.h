#ifndef HEAP_H
#define HEAP_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

typedef int ElemType;

typedef struct Heap
{
	ElemType arr[MAXSIZE];
	int count;
}Heap, *HeapPtr;

//���ϵ��������ֶѵ����� 
Status AdjustUp(HeapPtr H, int index);
//���µ��������ֶѵ����� 
Status AdjustDown(HeapPtr H, int index);
//����
Status Insert(HeapPtr H);
//ɾ��
Status Delete(HeapPtr H);
//ȡ�Ѷ�����
ElemType GetTopData(HeapPtr H);
//ȡ�ѵ����ݸ���
ElemType GetHeapSize(HeapPtr H);
//�ж϶��Ƿ�Ϊ�� 
Status IsEmpty(HeapPtr H);
//������
void TraverseHeap(HeapPtr H); 

//�������� 
void swap(ElemType *a,ElemType *b);

//����
void HeapTest();
void ShowMenu(); 

#endif
