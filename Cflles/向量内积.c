#include <stdio.h>
double inner_product(const double *a, const double *b,int n);
double inner_product(const double *a, const double *b,int n){
	double product = 0;
	for(int i = 0;i< n;i++){
		product += (*(a+i)) * (*(b+i));
	}
	return product;
}

int main(){
printf("%f",inner_product((double []){1.1,3.0},(double []){2.0,1.2},2));
}

