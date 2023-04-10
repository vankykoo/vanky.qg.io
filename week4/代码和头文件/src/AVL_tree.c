#include "AVL_tree.h"

//右旋处理
void R_Rotate(BiTree *p){
	BiTree L;
	L = (*p)->lchild;	
	(*p)->lchild = L->rchild;
	L->rchild = (*p);	
	*p = L;
}

//左旋处理
void L_Rotate(BiTree *p){
	BiTree R;
  	R = (*p)->rchild;
  	(*p)->rchild = R->lchild;
 	 R->lchild = (*p);	
  	*p = R;	
}

//左平衡旋转处理
void LeftBalance(BiTree *T){
	BiTree L,Lr;
	L = (*T)->lchild;
	switch(L->bf){	//检查T的左子树的平衡度，并作相应的平衡处理
	  case LH:	//新结点插入在T的左孩子的左子树上，要作单左旋处理
	    (*T)->bf = L->bf = EH;
	    R_Rotate(T);
	    break;
	  case RH:	//新结点插入在T的左孩子的右子树上，要作双旋处理
	    Lr = L->rchild;	//Lr指向T的左孩子的右子树根
	    switch(Lr->bf){	//修改T及其左孩子的平衡因子
	      case LH:	
	        (*T)->bf = RH;
	        L->bf = EH;
	        break;
	      case EH:
	        (*T)->bf = L->bf = EH;
	        break;
	      case RH:
	        (*T)->bf = EH;
	        L->bf = LH;
	        break;
	    }
	    Lr->bf = EH;
	    L_Rotate(&(*T)->lchild);	//对T的左子树作左旋平衡处理
	    R_Rotate(T);			//对T作右旋平衡处理
	}
}

//右平衡旋转处理 
void RightBalance(BiTree *T){
	BiTree R,Rl;
  	R = (*T)->rchild;
  	switch(R->bf){	//检查T的右子树的平衡度，并作相应的平衡处理
      case RH:	//新结点插入在T的右孩子的右子树上，要作单右旋处理
      	(*T)->bf = R->bf = EH;
      	L_Rotate(T);
      	break;
      case LH:	//新结点插入在T的右孩子的左子树上，要作双旋处理
      	Rl = R->lchild;	//Rl指向T的右孩子的左子树根
      	switch(Rl->bf){	//修改T及其右孩子的平衡因子
          case RH:	
          	(*T)->bf = LH;
          	R->bf = EH;
          	break;
          case EH:
          	(*T)->bf = R->bf = EH;
          	break;
          case LH:
          	(*T)->bf = EH;
          	R->bf = RH;
          	break;
      	}
      	Rl->bf = EH;
      	R_Rotate(&(*T)->rchild);	//对T的右子树作右旋平衡处理
      	L_Rotate(T);			//对T作左旋平衡处理
  }
}

//插入操作 
Status InsertAVL(BiTree *T,int e,Status *taller){
	if(!*T){
    //插入新结点，树“长高”，置taller为TRUE
    	*T = (BiTree)malloc(sizeof(BiTree));
    	(*T)->data = e;
    	(*T)->lchild = (*T)->rchild = NULL;
    	(*T)->bf = EH;
    	*taller = 1;
  	}else{
    	if(e == (*T)->data){//树中已存在和e有相同关键字的结点则不再插入
      		*taller = 0;
      		return ERROR;
    	}
    	if(e < (*T)->data){//应继续在T的左子树中进行搜索
      		if(!InsertAVL(&(*T)->lchild,e,taller))
        		return ERROR;
      		if(taller){
        		switch((*T)->bf){
          		  case LH:	//原本左子树比右子树高，需要作左平衡处理
            		LeftBalance(T);
            		*taller = 0;
            		break;
          		  case EH:	//原本左右子树等高，现因左子树增高而树增高
            		(*T)->bf = LH;
            		*taller = 1;
            		break;
          		  case RH:
            		(*T)->bf = EH;
            		*taller = 0;
            		break;
        		}		
      		}
    	}
    	else{
      		if(!InsertAVL(&(*T)->rchild,e,taller))
        		return ERROR;
      		if(*taller){
        		switch((*T)->bf){
          		  case LH:
            		(*T)->bf = EH;
            		*taller = 0;
            		break;
          		  case EH:
            		(*T)->bf = RH;
            		*taller = 1;
            		break;
          		  case RH:
            		RightBalance(T);
            		*taller = 0;
            		break;
        		}
      		}
    	}
  	}
  	return SUCCESS;
}

void TestAVLTree(BiTree *T,Status *taller){
	int data;
	printf("请输入你要插入的数据：");
	scanf("%d",&data);
	
	InsertAVL(T,data,taller);
}











