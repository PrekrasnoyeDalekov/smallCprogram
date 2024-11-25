#include <stdio.h>
#define MAX_LEN 100

void censor(char *p);
int main(){
	char str[MAX_LEN] = {'\0'};
	printf("Enter a string(not longer than 100):");
	gets(str);
	censor(str);
	for(char *p = str;*p!= 0;p++){
		printf("%c",*p);
	}
	return 0;
}

void censor(char *p){
	for(;*(p+2)!=0;p++){
		if(*p=='f'&&*(p+1)=='o'&&*(p+2)=='o'){
			*p='x';*(p+1)='x';*(p+2)='x';
			p+=2;
		}
	}
}

