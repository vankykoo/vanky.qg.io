#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

#define LH +1
#define EH 0
#define RH -1

typedef int ElemType;

typedef struct BiTNode{
  int data;
  int bf;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��������
void R_Rotate(BiTree *p); 
//��������
void L_Rotate(BiTree *p);
//��ƽ����ת����
void LeftBalance(BiTree *T);
//��ƽ����ת���� 
void RightBalance(BiTree *T);
//������� 
Status InsertAVL(BiTree *T,int e,Status *taller);

void TestAVLTree(BiTree *T,Status *taller);

#endif
