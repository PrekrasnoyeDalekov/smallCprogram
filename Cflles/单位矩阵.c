#include <stdio.h>

void eyes(int n,int *p){
	*p = 1;
	for(int i = 0;i<n-1;++i,*(p+i*(n+1)) = 1){
		for(int j=1;j<n+1;j++){
			*(p+i*(n+1)+j) = 0;
		}
		
	}
}


int main(){
	int n;
	printf("Enter the size of the matrix:");
	int matrix[n][n];
	int *p = &matrix[0][0];
	scanf("%d",&n);
	void eyes(int n,int *);
	eyes(n,p);
	for(int i=0;i<n*n;++i){
		if(i% n == 0)printf("\n");
		printf("%d ",*(p+i));

	}
	return 0;
}
