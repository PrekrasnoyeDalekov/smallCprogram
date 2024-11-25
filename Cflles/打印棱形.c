#include <stdio.h>
#include <stdlib.h>

int main(){	
	for(int i=0;i<7;i++){
		printf("%*c",abs(3-i)+1,' ');
		for(int j=0;j<7-abs(6-2*i);j++)printf("%c",'*');
		printf("\n");
	}
	
}
