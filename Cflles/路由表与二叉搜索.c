#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct biTnode{
	int iPort;
	struct biTnode *lchild,*rchild;
};


struct biTnode *createNode(){
	struct biTnode *newNode = (struct biTnode*)malloc(sizeof(struct biTnode));
	newNode->iPort = -1;
	newNode->lchild = newNode->rchild = NULL;
	return newNode;
}


void createRIB(FILE *fin,struct biTnode *root){
	char buff[30]={0};
	unsigned char byte1,byte2,byte3,byte4,mask;
	unsigned int iport;
	while(fgets(buff,30,fin)){
		if(sscanf(buff,"%hhu.%hhu.%hhu.%hhu/%hhu %u",&byte1,&byte2,&byte3,&byte4,&mask,&iport)==6){
			printf("%s",buff);
			struct biTnode *current_ptr = root;
			unsigned int ip=(byte1<<24) | (byte2<<16) | (byte3<<8) | byte4; // 变成4字节int 类型
			unsigned char iLorR=0;
			for(int i=0;i<mask;++i){
				iLorR = (ip>>(31-i)) & 0x1;
				if(!iLorR){
					if(!current_ptr->lchild)current_ptr->lchild = createNode();
					current_ptr = current_ptr->lchild;
				}
				else{
					if(!current_ptr->rchild)current_ptr->rchild = createNode();
					current_ptr = current_ptr->rchild;
				}
			}
			current_ptr->iPort = iport;
		}
		memset(buff,0,sizeof(buff));
	}
	fclose(fin);
	printf("RIB created successfully!\n");
	
}

int getNextHop(const char *buff,struct biTnode* root){
	unsigned char byte1,byte2,byte3,byte4;

	if(sscanf(buff," %hhu.%hhu.%hhu.%hhu",&byte1,&byte2,&byte3,&byte4)==4){
		int iport = -1;  // default port
		unsigned int ip=(byte1<<24) | (byte2<<16) | (byte3<<8) | byte4; // 变成4字节int 类型
		struct biTnode *current_ptr = root;
		unsigned char iLorR = 0;
		for(int i=0;i<32;i++){
			iLorR = (ip>>(31-i)) & 0x1;
			
			if(iLorR){  // iLorR = 1, visit right child
				if(!current_ptr->rchild) break;
				else{
					current_ptr = current_ptr->rchild;
					iport = (current_ptr->iPort==-1)?iport:current_ptr->iPort;
				}
			}
			
			else{  // iLorR=0, visit left child
				if(!current_ptr->lchild) break;
				else{
					current_ptr = current_ptr->lchild;
					iport = (current_ptr->iPort==-1)?iport:current_ptr->iPort;
				}
			}				
		}
		return (iport==-1)?root->iPort:iport;

	}
	else{
		printf("Invalid IP!\n");
		return -1;
	}
	
	
}


int main(){
	// read RIB and make biTree
	FILE *RIB = fopen("./路由表.txt","r");
	if(!RIB){
		printf("Fail to open RIB file!\n");
		exit(EXIT_FAILURE);
	}
	struct biTnode*root = createNode();
	createRIB(RIB,root);
	
	// read input IP and return output port
	
	
	/*
	MODE1: GET INPUTS FROM FILE
	FILE *fin = fopen();

	
	*/
	
	/*MODE2: GET INPUTS FROM STDIN*/ 
	char buff[30];
	for(printf("Please Enter IP:（Invalid IP to quit)\n");fgets(buff,sizeof(buff),stdin)&&getNextHop(buff,root)!=-1;printf("%d\n",getNextHop(buff,root)),memset(buff,0,sizeof(buff)));
	

	return 0;
}
