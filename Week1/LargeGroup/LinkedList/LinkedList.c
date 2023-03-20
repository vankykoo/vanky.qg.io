#include "LinkedList.h"
Status InitList(LinkedList* L) {	//初始化链表
	if (L == NULL) {
		printf("链表不存在！\n");
	}else if (*L == NULL) {
		*L = (LNode*)malloc(sizeof(LNode));
		(*L)->data = 0;
		(*L)->next = NULL;
	}
}


void DestroyList(LinkedList* L) {	//销毁链表
	if (*L == NULL) {
		printf("链表不存在！\n");
	}
	LinkedList p,q;
	p = (LinkedList)malloc(sizeof(LNode));
	p = *L;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L) = NULL;	//避免野指针
	printf("操作成功！\n");
}


Status InsertList(LNode* p, LNode* q) {	//插入数据q到p的后面
	LNode* newLNode = (LNode*)malloc(sizeof(LNode));
	
	if (p && newLNode) {
		newLNode->data = q->data;
		newLNode->next = p->next;
		p->next = newLNode;
		printf("插入数据成功！\n");
		return SUCCESS;
	}
	printf("插入数据失败！\n");
	return ERROR;
}


Status DeleteList(LNode* p, ElemType* e) {	//删除数据
	if (p && p->next) {
		LinkedList q;
		q = p->next;
		p->next = q->next;
		(*e) = q->data;
		free(q);
		printf("删除成功\n");
		return SUCCESS;
	}
	printf("删除失败！\n");
	return ERROR;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {	//遍历链表数据
	if (L == NULL) {
		printf("链表不存在！\n");
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


Status SearchList(LinkedList L, ElemType e) {	//查找数据
	if (L == NULL) {
		printf("链表不存在！\n");
		return ERROR;
	}
	LinkedList p;
	p = L->next;
	while (p) {
		if (p->data == e) {
			printf("链表内有数据：%d\n", e);
			return SUCCESS;
		}
		p = p->next;
	}
	printf("查找失败！链表内无相关数据！\n");
	return ERROR;
}


Status ReverseList(LinkedList* L) {		//反转链表
	if (*L == NULL) {
		printf("链表不存在！\n");
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


Status IsLoopList(LinkedList L) {	//判断是否为空
	if ( L == NULL || L->next == NULL) {
		printf("链表为空或不存在\n");
		return SUCCESS;
	}
	printf("链表不为空\n");
	return ERROR;
}


LNode* ReverseEvenList(LinkedList* L) {	//偶数反转
	if (*L == NULL) {
		printf("链表不存在！\n");
		return;
	}
	LinkedList p, q, r;
	r = *L;
	p = (*L)->next;
	if (p == NULL || p->next == NULL)
		return *L;
	q = p->next;
	while (q) {
		if ((q->data) % 2 == 0) {	//如果是偶数就交换
			r->next = q;
			p->next = q->next;
			q->next = p;
			r = q;
			q = p->next;
		}
		else {		//奇数就只移动光标
			r = p;
			p = q;
			q = p->next;
		}
	}
	return *L;
}

LNode* FindMidNode(LinkedList* L) {	//寻找中间结点
	if (*L == NULL) {
		printf("链表不存在！\n");
		return;
	}
	LinkedList slow, fast;
	slow = (LNode*)malloc(sizeof(LNode));
	slow = *L;		//使用快慢指针
	fast = *L;
	if (slow->next == NULL) {
		printf("链表为空\n");
		return *L;
	}
	while (fast->next) {
		fast = fast->next;
		if (fast)
			fast = fast->next;
		slow = slow->next;
	}
	//如果是奇数个结点，就不会包括头结点
	//如果是偶数个结点，就会包括头结点，返回中间结点
	printf("中间结点数据为：%d\n", slow->data);
	return slow;
}

void ShowMenu() {	//菜单
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.销毁链表\n");
	printf("\t\t			2.寻找中间结点\n");
	printf("\t\t			3.向表中结点后面插入新结点\n");
	printf("\t\t			4.删除结点\n");
	printf("\t\t			5.遍历数组\n");
	printf("\t\t			6.初始化链表\n");
	printf("\t\t			7.查找结点\n");
	printf("\t\t			8.反转链表\n");
	printf("\t\t			9.判断是否为空\n");
	printf("\t\t			10.偶数反转\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t		提示：头结点用数字0表示\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-10)：");
}

LNode* CreateLNode() {		//创建新结点用于插入
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode));
	char input[20]={0}; 
	int i,num,flag = 0;
	ElemType data1 = 0;
	printf("请输入创建结点的数据（整数）：");
	do {		//返回一个都是数字的数组！ 
		scanf_s("%s", &input);
		flag = 0; 
		for (i = 0;input[i] != '\0';i++){
			if(!(input[i] >= '0' && input[i] <= '9')){
				flag = 1;
				printf("格式有误！请重新输入创建结点的数据（整数）：") ;
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

LNode* SelectLNode(LNode* L) {	//遍历链表获取结点
	if (L == NULL) {
		printf("链表不存在！\n");
		return NULL;
	}
	ElemType data2;
	printf("请输入链表内结点的数据：");
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
		printf("链表内未找到目标结点！\n");
	return q;
}
