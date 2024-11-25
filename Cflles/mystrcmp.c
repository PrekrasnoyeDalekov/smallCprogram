#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 10
void input(char *c){
	char ch;
	int len=0;
	ch = getchar();
	if((ch=='\n')){
		fprintf(stderr,"请重新输入!\n");
		input(c);
	}
	else{
		do{
		if(len%MAX_LEN==0 && len){
			c=realloc(c,sizeof(c)+sizeof(char)*MAX_LEN);

		}
		c[len++]=ch;
		ch = getchar();
	}while(ch!='\n');
	}
	c[len]='\0';
	
}
int strcompare(char *c1,char *c2){
//		for(int i=0;i<strlen(c1)&&i<strlen(c2);i++){
//			if(c1[i]>c2[i])goto case1;
//			else if(c1[i]<c2[i])goto case_1;
//		}
//		if(strlen(c1)>strlen(c2)) goto case1;
//		else if(strlen(c1)<strlen(c2)) goto case_1 ;
//		else goto case0;
//	
//	case1:return 1;
//	case0:return 0;
//	case_1:return -1;
	{
		int i;
		for (i = 0; c1[i] == c2[i]; i++)
			if (c1[i] == '\0'||c2[i]=='\0')
				return 0;
		return c1[i] - c2[i] ;
	}
}
int main(){
	char *char1=(char *)malloc(MAX_LEN*sizeof(char)),*char2=(char *)malloc(MAX_LEN*sizeof(char));
	printf("请输入第一个字符串：\n");
	input(char1);
	printf("请输入第二个字符串：\n");
	input(char2);
	printf("字符串的比较结果为：\n");
//	switch(strcompare(char1,char2)){
//	case 1: printf("串1大于串2");break;
//	case 0: printf("串1等于串2");break;
//	case -1: printf("串1小于串2");break;
//		
//	}
	int result = strcompare(char1,char2);
	if(result<0)printf("串1小于串2");
	else if(result>0)printf("串1大于串2");
	else printf("串1等于串2");
	return 0;
	
}
