#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	long double result=(pow(1+sqrt(5),n)-pow(1-sqrt(5),n))/(pow(2,n)*sqrt(5));
	printf("%.0Lf",result);
	return 0;
	
}
