#include <stdio.h>
#include <math.h>
int cube(int n){
	int cube[3];
	cube[0]=n%10;
	cube[2]=n/100;
	cube[1]=(n/10)%10;
	return pow(cube[0],3)+pow(cube[1],3)+pow(cube[2],3);
}

int main(){
	int n=100;
	printf("水仙花数有:\n");
	for(;n<1000;n++){
		if (n==cube(n))printf("%d\n",n);
	}
	return 0;	
	
	 
}
