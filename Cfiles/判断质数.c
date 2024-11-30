#include <stdio.h>

int main(void){
	int i,num;
	printf("What is the number?");
	scanf("%d",&num);
	for(i = 2;i * i <= num && num % i != 0;i++){
	}
	if (i * i >num) printf("%d is a prime number.",num);
	else printf("%d is not a prime number.",num);
	return 0;
}
