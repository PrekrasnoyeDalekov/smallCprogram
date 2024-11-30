#include <stdio.h>
int main(){
	int dollars;
	scanf("%d",&dollars);
	printf("\t$20:\t%d\n\t$10:\t%d\n\t$5:\t%d\n\t$1:\t%d\n",dollars/20,(dollars%20)/10,(dollars%10)/5,dollars%5);
	return 0;
	
}
