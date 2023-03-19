#include "duLinkedList.h"

Status InitList_DuL(DuLinkedList* L) {
	if (*L == NULL) {
		*L = (DuLNode*)malloc(sizeof(DuLNode));
		(*L)->next = NULL;
		(*L)->prior = NULL;
		(*L)->data = 0;		//初始化赋值为0 
	}
	else
		printf("无需初始化！\n");
}//初始化链表


void DestroyList_DuL(DuLinkedList* L){
	if(*L == NULL){
		printf("链表不存在！\n");
		return;
	}
	DuLinkedList p, q;
	p = *L;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;		//避免野指针 
	printf("销毁链表成功！\n");
}//销毁链表


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	DuLinkedList r;
	if (p == NULL || q == NULL){
		printf("添加失败，链表或结点为空！\n");
		return ERROR;
	}
	r = p->prior;
	r->next = q;
	p->prior = q;
	q->prior = r;
	q->next = p;
	printf("添加成功！\n");
	return SUCCESS;
}//头插法插入


Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	DuLinkedList r;
	if (p == NULL || q == NULL) {
		printf("添加失败，链表或结点为空！\n");
		return ERROR;
	}
	r = p->next;
	p->next = q;
	q->prior = p;
	q->next = r;
	if (r)
		r->prior = q;
	printf("添加成功！\n");
	return SUCCESS;
}//尾插法插入


Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	DuLinkedList q, r;
	if (p == NULL || p->next == NULL) {
		printf("删除失败，链表或结点为空\n");
		return ERROR;
	}
	r = p->next;
	q = r->next;
	p->next = q;
	if(q)
		q->prior = p;
	*e = r->data;
	free(r);
	printf("删除成功！");
	return SUCCESS;
}//删除结点，赋值给e


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L == NULL){
		printf("链表不存在！\n");
		return;
	}
	DuLNode* p;
	p = L->next;
	ElemType e;
	while (p) {
		e = p->data;
		visit(e);
		p = p->next;
	}
	printf("NULL\n");
}//遍历数组

void visit(ElemType e) {
	printf("%d->", e);
}

void ShowMenu() {
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.销毁链表\n");
	printf("\t\t			2.从前插入\n");
	printf("\t\t			3.从后插入\n");
	printf("\t\t			4.删除下一个结点\n");
	printf("\t\t			5.遍历数组\n");
	printf("\t\t			6.初始化链表\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0~6)：");
}

DuLNode* CreateDuLNode() {		//创建新结点用于插入 
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	ElemType data1;
	printf("请输入创建结点的数据：");
	scanf_s("%d", &data1);
	q->data = data1;
	q->next = NULL;
	q->prior = NULL;
	return q;
}

DuLNode* SelectDuLNode(DuLNode *L) {	//遍历查找结点 
	if(L == NULL){
		printf("链表不存在！\n");
		return NULL; 
	}
	ElemType data2;
	printf("请输入链表内结点的数据：");
	scanf_s("%d", &data2);
	DuLNode *q;
	q = L;
	while (q) {
		if (q->data == data2) {
			q->data = data2;
			break;
		}
		q = q->next;
	}
	return q;
}
