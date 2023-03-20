#include "LinkedList.h"
Status InitList(LinkedList* L) {	//��ʼ������
	if (L == NULL) {
		printf("�������ڣ�\n");
	}else if (*L == NULL) {
		*L = (LNode*)malloc(sizeof(LNode));
		(*L)->data = 0;
		(*L)->next = NULL;
	}
}


void DestroyList(LinkedList* L) {	//��������
	if (*L == NULL) {
		printf("�������ڣ�\n");
	}
	LinkedList p,q;
	p = (LinkedList)malloc(sizeof(LNode));
	p = *L;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L) = NULL;	//����Ұָ��
	printf("�����ɹ���\n");
}


Status InsertList(LNode* p, LNode* q) {	//��������q��p�ĺ���
	LNode* newLNode = (LNode*)malloc(sizeof(LNode));
	
	if (p && newLNode) {
		newLNode->data = q->data;
		newLNode->next = p->next;
		p->next = newLNode;
		printf("�������ݳɹ���\n");
		return SUCCESS;
	}
	printf("��������ʧ�ܣ�\n");
	return ERROR;
}


Status DeleteList(LNode* p, ElemType* e) {	//ɾ������
	if (p && p->next) {
		LinkedList q;
		q = p->next;
		p->next = q->next;
		(*e) = q->data;
		free(q);
		printf("ɾ���ɹ�\n");
		return SUCCESS;
	}
	printf("ɾ��ʧ�ܣ�\n");
	return ERROR;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {	//������������
	if (L == NULL) {
		printf("�������ڣ�\n");
		return;
	}
	LinkedList p;
	p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void visit(ElemType e) {
	printf("%d->", e);
}


Status SearchList(LinkedList L, ElemType e) {	//��������
	if (L == NULL) {
		printf("�������ڣ�\n");
		return ERROR;
	}
	LinkedList p;
	p = L->next;
	while (p) {
		if (p->data == e) {
			printf("�����������ݣ�%d\n", e);
			return SUCCESS;
		}
		p = p->next;
	}
	printf("����ʧ�ܣ���������������ݣ�\n");
	return ERROR;
}


Status ReverseList(LinkedList* L) {		//��ת����
	if (*L == NULL) {
		printf("�������ڣ�\n");
		return ERROR;
	}
	LinkedList p, q, r;
	p = (*L)->next;
	q = p->next;
	r = NULL;
	if (p==NULL || q==NULL) {
		return ERROR;
	}
	while (p) {
		p->next = r;
		r = p;
		if (q == NULL)
			break;
		p = q;
		q = p->next;
	}
	(*L)->next = p;
	return SUCCESS;
}


Status IsLoopList(LinkedList L) {	//�ж��Ƿ�Ϊ��
	if ( L == NULL || L->next == NULL) {
		printf("����Ϊ�ջ򲻴���\n");
		return SUCCESS;
	}
	printf("����Ϊ��\n");
	return ERROR;
}


LNode* ReverseEvenList(LinkedList* L) {	//ż����ת
	if (*L == NULL) {
		printf("�������ڣ�\n");
		return;
	}
	LinkedList p, q, r;
	r = *L;
	p = (*L)->next;
	if (p == NULL || p->next == NULL)
		return *L;
	q = p->next;
	while (q) {
		if ((q->data) % 2 == 0) {	//�����ż���ͽ���
			r->next = q;
			p->next = q->next;
			q->next = p;
			r = q;
			q = p->next;
		}
		else {		//������ֻ�ƶ����
			r = p;
			p = q;
			q = p->next;
		}
	}
	return *L;
}

LNode* FindMidNode(LinkedList* L) {	//Ѱ���м���
	if (*L == NULL) {
		printf("�������ڣ�\n");
		return;
	}
	LinkedList slow, fast;
	slow = (LNode*)malloc(sizeof(LNode));
	slow = *L;		//ʹ�ÿ���ָ��
	fast = *L;
	if (slow->next == NULL) {
		printf("����Ϊ��\n");
		return *L;
	}
	while (fast->next) {
		fast = fast->next;
		if (fast)
			fast = fast->next;
		slow = slow->next;
	}
	//�������������㣬�Ͳ������ͷ���
	//�����ż������㣬�ͻ����ͷ��㣬�����м���
	printf("�м�������Ϊ��%d\n", slow->data);
	return slow;
}

void ShowMenu() {	//�˵�
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��������\n");
	printf("\t\t			2.Ѱ���м���\n");
	printf("\t\t			3.����н���������½��\n");
	printf("\t\t			4.ɾ�����\n");
	printf("\t\t			5.��������\n");
	printf("\t\t			6.��ʼ������\n");
	printf("\t\t			7.���ҽ��\n");
	printf("\t\t			8.��ת����\n");
	printf("\t\t			9.�ж��Ƿ�Ϊ��\n");
	printf("\t\t			10.ż����ת\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t		��ʾ��ͷ���������0��ʾ\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-10)��");
}

LNode* CreateLNode() {		//�����½�����ڲ���
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));
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
	return q;
}

LNode* SelectLNode(LNode* L) {	//���������ȡ���
	if (L == NULL) {
		printf("�������ڣ�\n");
		return NULL;
	}
	ElemType data2;
	printf("�����������ڽ������ݣ�");
	scanf_s("%d", &data2);
	LNode* q;
	q = L;
	while (q) {
		if (q->data == data2) {
			q->data = data2;
			break;
		}
		q = q->next;
	}
	if (q == NULL)
		printf("������δ�ҵ�Ŀ���㣡\n");
	return q;
}
