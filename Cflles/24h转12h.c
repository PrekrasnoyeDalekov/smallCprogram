#include <stdio.h>

int main(){
	int hour,minutes;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&hour,&minutes);
	if(hour > 12){
		printf("Equivalent 12-hour time:%.2d:%.2d PM",hour - 12,minutes);
	}else{
		printf("Equivalent 12-hour time:%.2d:%.2d AM",hour,minutes);
	}
	return 0;
}
