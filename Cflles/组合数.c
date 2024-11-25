#include <stdio.h>
int fac(int i){
	if(i==0){
		return 1;
	}
	return i*fac(i-1);

}
int main(){
	int n,i;
	
	printf("ÇëÊäÈëĞĞÊı:");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		int j;
		for(j=0;j<=i;j++){
			printf("%d  ",fac(i)/(fac(j)*fac(i-j)));
			
		}
		printf("\n");
	}
}
