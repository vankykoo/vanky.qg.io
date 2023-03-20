#include "duLinkedList.h"

Status InitList_DuL(DuLinkedList* L) {
	if (*L == NULL) {
		*L = (DuLNode*)malloc(sizeof(DuLNode));
		(*L)->next = NULL;
		(*L)->prior = NULL;
		(*L)->data = 0;		//��ʼ����ֵΪ0 
	}
	else
		printf("�����ʼ����\n");
}//��ʼ������


void DestroyList_DuL(DuLinkedList* L){
	if(*L == NULL){
		printf("�������ڣ�\n");
		return;
	}
	DuLinkedList p, q;
	p = *L;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;		//����Ұָ�� 
	printf("��������ɹ���\n");
}//��������


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	DuLinkedList r;
	if (p == NULL || q == NULL){
		printf("���ʧ�ܣ��������Ϊ�գ�\n");
		return ERROR;
	}
	r = p->prior;
	r->next = q;
	p->prior = q;
	q->prior = r;
	q->next = p;
	printf("��ӳɹ���\n");
	return SUCCESS;
}//ͷ�巨����


Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	DuLinkedList r;
	if (p == NULL || q == NULL) {
		printf("���ʧ�ܣ��������Ϊ�գ�\n");
		return ERROR;
	}
	r = p->next;
	p->next = q;
	q->prior = p;
	q->next = r;
	if (r)
		r->prior = q;
	printf("��ӳɹ���\n");
	return SUCCESS;
}//β�巨����


Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	DuLinkedList q, r;
	if (p == NULL || p->next == NULL) {
		printf("ɾ��ʧ�ܣ��������Ϊ��\n");
		return ERROR;
	}
	r = p->next;
	q = r->next;
	p->next = q;
	if(q)
		q->prior = p;
	*e = r->data;
	free(r);
	printf("ɾ���ɹ���\n");
	return SUCCESS;
}//ɾ����㣬��ֵ��e


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L == NULL){
		printf("�������ڣ�\n");
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
}//��������

void visit(ElemType e) {
	printf("%d->", e);
}

void ShowMenu() {
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��������\n");
	printf("\t\t			2.��ǰ����\n");
	printf("\t\t			3.�Ӻ����\n");
	printf("\t\t			4.ɾ����һ�����\n");
	printf("\t\t			5.��������\n");
	printf("\t\t			6.��ʼ������\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t		   ��ʾ��ͷ�������Ϊ0\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0~6)��");
}

DuLNode* CreateDuLNode() {		//�����½�����ڲ��� 
	DuLNode* q;
	q = (DuLNode*)malloc(sizeof(DuLNode));
	char input[20]={0}; 
	int i,num,flag = 0;
	ElemType data1 = 0;
	printf("�����봴���������ݣ���������");
	do {		//����һ���������ֵ����飡 
		scanf_s("%s", &input);
		flag = 0; 
		for (i = 0;input[i] != '\0';i++){
			if(!(input[i] >= '0' && input[i] <= '9')){
				flag = 1;
				printf("��ʽ�������������봴���������ݣ���������") ;
				break;
			}
		}
	}while(flag);
	for(i = 0;input[i] != '\0';i++){
		num = input[i] - '0';
		data1 = data1 * 10 + num;
	}
	q->data = data1;
	q->next = NULL;
	q->prior = NULL;
	return q;
}

DuLNode* SelectDuLNode(DuLNode *L) {	//�������ҽ�� 
	if(L == NULL){
		printf("�������ڣ�\n");
		return NULL; 
	}
	ElemType data2;
	printf("�����������ڽ������ݣ�");
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
