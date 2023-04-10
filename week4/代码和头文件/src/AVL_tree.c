#include "AVL_tree.h"

//��������
void R_Rotate(BiTree *p){
	BiTree L;
	L = (*p)->lchild;	
	(*p)->lchild = L->rchild;
	L->rchild = (*p);	
	*p = L;
}

//��������
void L_Rotate(BiTree *p){
	BiTree R;
  	R = (*p)->rchild;
  	(*p)->rchild = R->lchild;
 	 R->lchild = (*p);	
  	*p = R;	
}

//��ƽ����ת����
void LeftBalance(BiTree *T){
	BiTree L,Lr;
	L = (*T)->lchild;
	switch(L->bf){	//���T����������ƽ��ȣ�������Ӧ��ƽ�⴦��
	  case LH:	//�½�������T�����ӵ��������ϣ�Ҫ������������
	    (*T)->bf = L->bf = EH;
	    R_Rotate(T);
	    break;
	  case RH:	//�½�������T�����ӵ��������ϣ�Ҫ��˫������
	    Lr = L->rchild;	//Lrָ��T�����ӵ���������
	    switch(Lr->bf){	//�޸�T�������ӵ�ƽ������
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
	    L_Rotate(&(*T)->lchild);	//��T��������������ƽ�⴦��
	    R_Rotate(T);			//��T������ƽ�⴦��
	}
}

//��ƽ����ת���� 
void RightBalance(BiTree *T){
	BiTree R,Rl;
  	R = (*T)->rchild;
  	switch(R->bf){	//���T����������ƽ��ȣ�������Ӧ��ƽ�⴦��
      case RH:	//�½�������T���Һ��ӵ��������ϣ�Ҫ������������
      	(*T)->bf = R->bf = EH;
      	L_Rotate(T);
      	break;
      case LH:	//�½�������T���Һ��ӵ��������ϣ�Ҫ��˫������
      	Rl = R->lchild;	//Rlָ��T���Һ��ӵ���������
      	switch(Rl->bf){	//�޸�T�����Һ��ӵ�ƽ������
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
      	R_Rotate(&(*T)->rchild);	//��T��������������ƽ�⴦��
      	L_Rotate(T);			//��T������ƽ�⴦��
  }
}

//������� 
Status InsertAVL(BiTree *T,int e,Status *taller){
	if(!*T){
    //�����½�㣬�������ߡ�����tallerΪTRUE
    	*T = (BiTree)malloc(sizeof(BiTree));
    	(*T)->data = e;
    	(*T)->lchild = (*T)->rchild = NULL;
    	(*T)->bf = EH;
    	*taller = 1;
  	}else{
    	if(e == (*T)->data){//�����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ���
      		*taller = 0;
      		return ERROR;
    	}
    	if(e < (*T)->data){//Ӧ������T���������н�������
      		if(!InsertAVL(&(*T)->lchild,e,taller))
        		return ERROR;
      		if(taller){
        		switch((*T)->bf){
          		  case LH:	//ԭ�����������������ߣ���Ҫ����ƽ�⴦��
            		LeftBalance(T);
            		*taller = 0;
            		break;
          		  case EH:	//ԭ�����������ȸߣ��������������߶�������
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
	printf("��������Ҫ��������ݣ�");
	scanf("%d",&data);
	
	InsertAVL(T,data,taller);
}











