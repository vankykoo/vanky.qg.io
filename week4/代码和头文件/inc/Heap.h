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

//向上调整，保持堆的性质 
Status AdjustUp(HeapPtr H, int index);
//向下调整，保持堆的性质 
Status AdjustDown(HeapPtr H, int index);
//插入
Status Insert(HeapPtr H);
//删除
Status Delete(HeapPtr H);
//取堆顶数据
ElemType GetTopData(HeapPtr H);
//取堆的数据个数
ElemType GetHeapSize(HeapPtr H);
//判断堆是否为空 
Status IsEmpty(HeapPtr H);
//遍历堆
void TraverseHeap(HeapPtr H); 

//交换数据 
void swap(ElemType *a,ElemType *b);

//测试
void HeapTest();
void ShowMenu(); 

#endif
