#include <stdio.h>

long long mode(long long a,long long b,long long p){
	long long result=1L;
	a = a % p;
	while(b>0){
		if(b % 2 == 1){
			result = (result * a) % p;	
		}
		b /= 2;
		a = (a *a) %p;
		
	}
	return result;
}

int main(){
	long long int a,b ,p;
	scanf("%Ld %Ld %Ld",&a,&b,&p);
	printf("%Ld",mode(a,b,p));
	return 0;
}
