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

//右旋处理
void R_Rotate(BiTree *p); 
//左旋处理
void L_Rotate(BiTree *p);
//左平衡旋转处理
void LeftBalance(BiTree *T);
//右平衡旋转处理 
void RightBalance(BiTree *T);
//插入操作 
Status InsertAVL(BiTree *T,int e,Status *taller);

void TestAVLTree(BiTree *T,Status *taller);

#endif
