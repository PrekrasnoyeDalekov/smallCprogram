#include <stdio.h>
int main(){
	int n;
	double series;
	printf("n:");
	scanf("%d",&n);
	for (int i = 0;i < n;++i){
		series += 1/factor(i);
	}
	printf("%lf",series);
	return 0;	
}

