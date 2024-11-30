#include <stdio.h>

int main(){
	int days,startday;
	printf("Enter number of the days in month:");
	scanf("%d",&days);
	printf("\nEnter starting day of the week (0=Sun, 6=Sat):");
	scanf("%d",&startday);
	for (int i = 1;i <= days + startday;i++){
		
		if(i <= startday) printf("  ");
		else printf("%2d",i-startday);
		printf(" ");
		if (i % 7 == 0) printf("\n");
	}
	return 0;
}
