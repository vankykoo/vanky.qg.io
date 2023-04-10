#include "binary_sort_tree.h"
#include "LinkStack.h"
#include "Queue.h"
#include "AVL_tree.h"

//初始化
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

//删除结点 
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
    printf("删除成功！\n");
    
    return SUCCESS;
}

NodePtr BST_search(NodePtr nodePtr, ElemType value){
    if(nodePtr == NULL){
        return NULL;
    }
    
    if(nodePtr->data == value){
        printf("找到了结点%d\n",value);
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

//无递归版前序遍历  
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
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

//递归版前序遍历 
Status BST_preorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return ERROR;
	}
	
	visit(np);
	
	BST_preorderR(np->left, visit);

	BST_preorderR(np->right, visit);
}

//无递归版中序遍历 
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
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

//递归版中序遍历
Status BST_inorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return SUCCESS;
	}
	
	BST_inorderR(np->left, visit);
	visit(np);
	BST_inorderR(np->right, visit);
}

//非递归版后序遍历 
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
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

//递归版后序遍历
Status BST_postorderR(NodePtr np, void (*visit)(NodePtr NP)){
	if(np == NULL){
		return SUCCESS;
	} 
	BST_postorderR(np->left, visit);
	BST_postorderR(np->right, visit);
	visit(np);
} 

//层序遍历非递归 
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
		return ERROR;
	}
	LinkQueue *L = (LinkQueue*)malloc(sizeof(LinkQueue));
	initLQueue(L);
	NodePtr np = BST->root;
	
	//入队列 
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
	printf("\t\t			1.添加结点\n");
	printf("\t\t			2.删除结点\n");
	printf("\t\t			3.查找结点\n");
	printf("\t\t			4.前序遍历非递归\n");
	printf("\t\t			5.前序遍历递归\n");
	printf("\t\t			6.中序遍历非递归\n");
	printf("\t\t			7.中序遍历递归\n");
	printf("\t\t			8.后序遍历非递归\n");
	printf("\t\t			9.后序遍历递归\n");
	printf("\t\t			10.层序遍历\n");
	printf("\t\t			11.堆的实现\n");
	printf("\t\t			0.退出程序\n");
	printf("\t\t		提示：数据为整数\n");
	printf("\t\t		提示：AVL树无法实现\n");
	printf("\t\t\t**********************************************\n");
	printf("\t\t\t请输入你的选择(0-11)：");
}

void TestInsert(BinarySortTreePtr BST){
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	int data;
	printf("请输入你要添加的数据：");
	scanf("%d",&data); 
	
	if(!BST_search(BST->root, data)){
		BST_insert(BST, data);
		printf("插入结点成功！\n");
	}else{
		printf("结点已存在！\n");
	}
}


void TestDelete(BinarySortTreePtr BST){
	int data;
	printf("请输入你要删除的数据：");
	scanf("%d",&data);
	
	if(BST_search(BST->root, data)){
		BST_delete(BST, data);
	}else{
		printf("未找到该结点！");
	}
}


void TestSearch(BinarySortTreePtr BST){
	int data;
	printf("请输入你要查找的数据：");
	scanf("%d",&data);
	
	if(BST_search(BST->root, data) == NULL){
		printf("未找到结点！\n");
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
			printf("输入格式错误！请重新输入："); 
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
		printf("树为空！\n");
		return;
	}
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_inorderR(node, visit);
}

void TestPostorderR(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
		return;
	}
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_postorderR(node, visit);
}

void TestPreorderR(BinarySortTreePtr BST, void (*visit)(NodePtr NP)){
	if(BST->root == NULL){
		printf("树为空！\n");
		return;
	}
	
	NodePtr node = (Node*)malloc(sizeof(Node));
	node = BST->root;
	
	BST_preorderR(node, visit);
}









