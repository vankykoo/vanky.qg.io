#include "binary_sort_tree.h"
#include "LinkStack.h"
#include "Queue.h"
#include "AVL_tree.h"

//��ʼ��
Status BST_init(BinarySortTreePtr BST){
	//BST = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	BST->root = NULL;
} 

NodePtr createNode(ElemType value){
	NodePtr nodePtr = (Node*)malloc(sizeof(Node));
	nodePtr->data = value;
	nodePtr->left = NULL;
	nodePtr->right = NULL;
	
	return nodePtr;
}

Status BST_insert(BinarySortTreePtr BST, ElemType value){
	NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    
    if(BST->root == NULL){
        BST->root = node;
        return SUCCESS;
    }
    
    NodePtr temp = BST->root;
    NodePtr parent;
    while(temp != NULL){
        parent = temp;
        if(temp->data > value){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    
    if(parent->data > value){
        parent->left = node;
    }else{
        parent->right = node;
    }
}

//ɾ����� 
Status BST_delete(BinarySortTreePtr BST, ElemType value){
	NodePtr current = BST->root;
    NodePtr parent = NULL;
    while(current != NULL && current->data != value){
        parent = current;
        if(value < current->data){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    
    if(current == NULL){
        return ERROR;
    }
    
     if(current->left == NULL && current->right == NULL){
        if(parent == NULL){
            BST->root = NULL;
        }else if(parent->left == current){
            parent->left = NULL;
        }else{
            parent->right = NULL;
        }
    }else if(current->left != NULL && current->right != NULL){
        NodePtr successor = current->right;
        NodePtr successorParent = current;
        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        
        if(successorParent == current){
            successorParent->right = successor->right;
        }else{
            successorParent->left = successor->right;
        }
    }else{
        NodePtr child = (current->left != NULL) ? current->left : current->right;
        
        if(parent == NULL){
            BST->root = child;
        }else if(parent->left == current){
            parent->left = child;
        }else{
            parent->right = child;
        }
    }
    
    free(current);
    printf("ɾ���ɹ���\n");
    
    return SUCCESS;
}

NodePtr BST_search(NodePtr nodePtr, ElemType value){
    if(nodePtr == NULL){
        return NULL;
    }
    
    if(nodePtr->data == value){
        printf("�ҵ��˽��%d\n",value);
        return nodePtr; 
    }
    
    if(nodePtr->data < value){
        return BST_search(nodePtr->right,value);
    }
    
    if(nodePtr->data > value){
        return BST_search(nodePtr->left,value);
    }
}

void visit(NodePtr NP){
	printf("%d ",NP->data);
} 

//�޵ݹ��ǰ�����  
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return ERROR;
	}
	LinkStack *L = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(L);
    NodePtr np = BST->root;
    
    while(np != NULL || L->count != 0){
        while(np != NULL){
            visit(np);
            pushLStack(L, np);
            np = np->left;
        }
        
        if(L->count != 0){
        	np = L->top->nodePtr;
            popLStack(L);
            np = np->right;
        }
    }
    
    return SUCCESS;
}

//�ݹ��ǰ����� 
Status BST_preorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return ERROR;
	}
	
	visit(np);
	
	BST_preorderR(np->left, visit);

	BST_preorderR(np->right, visit);
}

//�޵ݹ��������� 
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return ERROR;
	}
	LinkStack *L = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(L);
    NodePtr np = BST->root;
    
    while(np != NULL || L->count != 0){
        while(np != NULL){
            pushLStack(L, np);
            np = np->left;
        }
        
        if(L->count != 0){
        	np = L->top->nodePtr;
        	printf("%d ",L->top->nodePtr->data);
        	popLStack(L);
            np = np->right;
        }
    }
    
    return SUCCESS;
}

//�ݹ���������
Status BST_inorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return SUCCESS;
	}
	
	BST_inorderR(np->left, visit);
	visit(np);
	BST_inorderR(np->right, visit);
}

//�ǵݹ�������� 
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return ERROR;
	}
	LinkStack *L1 = (LinkStack*)malloc(sizeof(LinkStack));
	LinkStack *L2 = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(L1);
	initLStack(L2);
	NodePtr np = BST->root;
    
    while(np != NULL || L1->count != 0){
        while(np != NULL){
            pushLStack(L1, np);
            pushLStack(L2, np);
            np = np->right;
        }
        
        if(L1->count != 0){
        	np = L1->top->nodePtr;
            popLStack(L1);
            np = np->left;
        }
    }
    
    while(L2->count != 0){
    	np = L2->top->nodePtr;
        popLStack(L2);
        visit(np);
    }
    
    return SUCCESS;
}

//�ݹ��������
Status BST_postorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return SUCCESS;
	} 
	BST_postorderR(np->left, visit);
	BST_postorderR(np->right, visit);
	visit(np);
} 

//��������ǵݹ� 
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return ERROR;
	}
	LinkQueue *L = (LinkQueue*)malloc(sizeof(LinkQueue));
	initLQueue(L);
	NodePtr np = BST->root;
	
	//����� 
		pushLQueue(L,np);
	
	while(L->count != 0 && np != NULL){

		np = L->head->nodePtr;
		visit(np);
		popLQueue(L);
		
		if(np->left != NULL){
			pushLQueue(L,np->left);
		}
		
		if(np->right != NULL){
			pushLQueue(L,np->right);
		}
		
	}
	
	return SUCCESS;
}

void Menu(){
	printf("\t\t\t**********************************************\n");
	printf("\t\t			1.��ӽ��\n");
	printf("\t\t			2.ɾ�����\n");
	printf("\t\t			3.���ҽ��\n");
	printf("\t\t			4.ǰ������ǵݹ�\n");
	printf("\t\t			5.ǰ������ݹ�\n");
	printf("\t\t			6.��������ǵݹ�\n");
	printf("\t\t			7.��������ݹ�\n");
	printf("\t\t			8.��������ǵݹ�\n");
	printf("\t\t			9.��������ݹ�\n");
	printf("\t\t			10.�������\n");
	printf("\t\t			11.�ѵ�ʵ��\n");
	printf("\t\t			0.�˳�����\n");
	printf("\t\t		��ʾ������Ϊ����\n");
	printf("\t\t		��ʾ��AVL���޷�ʵ��\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t���������ѡ��(0-11)��");
}

void TestInsert(BinarySortTreePtr BST){
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	int data;
	printf("��������Ҫ��ӵ����ݣ�");
	scanf("%d",&data); 
	
	if(!BST_search(BST->root, data)){
		BST_insert(BST, data);
		printf("������ɹ���\n");
	}else{
		printf("����Ѵ��ڣ�\n");
	}
}


void TestDelete(BinarySortTreePtr BST){
	int data;
	printf("��������Ҫɾ�������ݣ�");
	scanf("%d",&data);
	
	if(BST_search(BST->root, data)){
		BST_delete(BST, data);
	}else{
		printf("δ�ҵ��ý�㣡");
	}
}


void TestSearch(BinarySortTreePtr BST){
	int data;
	printf("��������Ҫ���ҵ����ݣ�");
	scanf("%d",&data);
	
	if(BST_search(BST->root, data) == NULL){
		printf("δ�ҵ���㣡\n");
	}
	 
}


ElemType inputJudgment(char arr[]){
	char arrs[20] = {0};
	int i,num,result = 0;
	for(i=0;arr[i] != '\0';i++){
		arrs[i] = arr[i];
	}
	arr[i] = '\0';
	
	int isInteger = 0;
	
	while(isInteger != 1){
		isInteger = 1;
		for(i=0;arrs[i] != '\0';i++){
			if(!(arrs[i] >= '0' && arrs[i] <= '9')){
				isInteger = 0;
				break;
			}
		}
		if(isInteger == 0){
			printf("�����ʽ�������������룺"); 
			scanf("%s",&arrs);
		}
	}
	
	if(isInteger == 1){
		for(i = 0;arrs[i] != '\0';i++){
			num = arrs[i] - '0';
			result = result * 10 + num;
		}
		
		return result;
	}
	
}

void TestInorderR(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return;
	}
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_inorderR(node, visit);
}

void TestPostorderR(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return;
	}
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_postorderR(node, visit);
}

void TestPreorderR(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("��Ϊ�գ�\n");
		return;
	}
	
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_preorderR(node, visit);
}









