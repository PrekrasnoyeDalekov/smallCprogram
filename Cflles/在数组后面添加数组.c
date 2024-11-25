#include <stdio.h>

void append(int m,char a[m],int n,char b[n],char c[m+n]){
	for(int i=0;i<m;i++){
		*(c+i) = a[i];
	}
	for(int i=0;i<n;i++){
		*(c+m+i) = b[i];
	}
	
}
int main(){
	char c[5];
	void append(int m,char a[m],int n,char b[n],char c[m+n]);
	append(3,(char []){'1','w','\n'},2,(char []){'3',' '},c);
	for(int i = 0;i < 5;i++){
		printf("%c",c[i]);
	}
}
