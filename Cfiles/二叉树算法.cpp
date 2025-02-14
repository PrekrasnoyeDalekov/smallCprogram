#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 127

typedef char data_type;
typedef struct biTnode{
	data_type data;
	struct biTnode *lchild,*rchild;
}*BiTree,biTnode;

struct biTnode *createNode(){
	biTnode *newNode = (biTnode*)malloc(sizeof(struct biTnode));
	newNode->lchild = newNode->rchild = NULL;
	return newNode;
}


// 补空法创建后序遍历二叉树
// 二叉树创建最方便的是补空法+先序遍历DLR:ABC##DE#G##F###可以唯一创建一棵二叉树A(B,(D(E(,G),F)))
// 二叉树的后序遍历LRD，如果从后往前看，会发现是DRL的

void CreateBiTree_LRD(BiTree &T,const data_type *str,char *count){
	data_type c=str[(int)*count];
	*count -= 1;
	if(c=='#') T=(struct biTnode*)NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(biTnode))))exit(EXIT_FAILURE);
		T->data = c;
		CreateBiTree_LRD(T->rchild,str,count);
		CreateBiTree_LRD(T->lchild,str,count);
		
	}
}
void readline(data_type str[MAX_LEN]){
	char count = 0;
	do{
		data_type c;
		c = getchar();
		if(c=='\n')break;
		str[(int)++count] = c;
		
	}while(count<MAX_LEN);
	str[0] = count;
}

char locate_data(const data_type str[],char start,char end,data_type data){
	for(int location = start;location<=end;location++){
		if(str[location]==data)return location;
	}
	return -1;
}

// 由先序遍历和中序遍历创建一棵二叉树,前提是data不重复
void CreateBiTreebyPreInOrder(const data_type pre_str[], const data_type in_str[],char* pre_count,char in_start,char in_end,BiTree &T){
	// 先序遍历的第一个元素一定是当前子树的根,去中序遍历中找到对应的位置
	int medium = locate_data(in_str,in_start, in_end,pre_str[(int)*pre_count]);
	if(medium==-1)T = NULL;
	// 从in_str[in_count]到in_str[medium-1]是左子树,从in_str[medium+1]到in_str[in_str[0]]是右子树
	else{
		T->data = pre_str[(int)*pre_count];
		T->lchild = createNode();
		T->rchild = createNode();
		(*pre_count)++;
		CreateBiTreebyPreInOrder(pre_str,in_str,pre_count,in_start,medium-1,T->lchild);
		CreateBiTreebyPreInOrder(pre_str,in_str,pre_count,medium+1,in_end,T->rchild);
	}
	
}


// 由后序遍历和中序遍历创建一颗二叉树,前提是data不重复
void CreateBiTreebyPostInOrder(const data_type post_str[], const data_type in_str[],char* post_count,char in_start,char in_end,BiTree &T){
	// 先序遍历的第一个元素一定是当前子树的根,去中序遍历中找到对应的位置
	int medium = locate_data(in_str,in_start, in_end,post_str[(int)*post_count]);
	if(medium==-1)T = NULL;
	// 从in_str[in_count]到in_str[medium-1]是左子树,从in_str[medium+1]到in_str[in_str[0]]是右子树
	else{
		T->data = post_str[(int)*post_count];
		T->lchild = createNode();
		T->rchild = createNode();
		(*post_count)--;
		CreateBiTreebyPreInOrder(post_str,in_str,post_count,in_start,medium-1,T->lchild);
		CreateBiTreebyPreInOrder(post_str,in_str,post_count,medium+1,in_end,T->rchild);
	}
	
}


// 二叉树的先序遍历DLR并打印
void PreOderTraverse(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOderTraverse(T->lchild);
		PreOderTraverse(T->rchild);
	}
}

// 二叉树的中序遍历LDR并打印
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

// 二叉树的后序遍历LRD并打印
void PostOrderTraverse(BiTree T){
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
		
	}
}
// 非递归算法
/*			定义栈				*/ 
typedef struct {
	biTnode *node_list;
	int top;
}STACK;

STACK* init_stack(){
	STACK *s = (STACK*)malloc(sizeof(STACK));
	s->node_list = (biTnode*)malloc(sizeof(biTnode)*MAX_LEN);
	s->top = -1;
	return s;
}

void overflow(){
	printf("Overflowed!");
}
void underflow(){
	printf("Underflowed!");
}

bool is_stack_empty(STACK *s){
	return s->top==-1;
}

bool is_stack_full(STACK *s){
	return s->top == MAX_LEN-1;
}

void push(STACK *s,biTnode *l){
	if(is_stack_full(s)) overflow();
	else{
		s->node_list[++(s->top)] = *l;
	}
}

biTnode *pop(STACK *s){
	if(is_stack_empty(s)){
		underflow();
		return (biTnode*)NULL;
	}
	else{
		return &(s->node_list[(s->top)--]);
	}
}
biTnode *getTop(STACK *s){
	return is_stack_empty(s)? (biTnode*)NULL:&(s->node_list[s->top]);
}
/*							*/
void PreOderTraverse_NonRecur(BiTree T,STACK *s){
	if(T){
		biTnode *p=T;
		while(p!=NULL || !is_stack_empty(s)){
			if(p){
				printf("%c",p->data);
				push(s,p);
				p = p->lchild;
				
			}
			else{
				p = pop(s);
				p = p->rchild;
			}
		}
		
	}
	else return ;
}

// 判断是否为正则二叉树,利用后序遍历实现
bool is_re_tree(BiTree T){
	if((T->lchild==NULL&&T->rchild==NULL) || (T->lchild&&T->rchild&&is_re_tree(T->lchild)&&is_re_tree(T->rchild)))return true;
	else return false;
}
int main(void){
//	data_type pre_str[MAX_LEN]={0};
//	data_type in_str[MAX_LEN]={0};
//	BiTree T = createNode();
//	readline(pre_str);
//	readline(in_str);
//	char pre_count=1;
//	CreateBiTreebyPreInOrder(pre_str,in_str,&pre_count,1,in_str[0],T);
	data_type str[MAX_LEN]={0};
	BiTree T = (BiTree)malloc(sizeof(biTnode));
	readline(str);
	CreateBiTree_LRD(T,str,(char*)str);
//	STACK *s = init_stack();
//	PreOderTraverse_NonRecur(T,s);
	InOrderTraverse(T);
	
}
