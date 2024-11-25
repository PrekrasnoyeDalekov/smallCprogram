#include<stdio.h>
#define N 200
int main(){
	int i;
	int arr[N-2];
	for(i=2;i<N;i++){
		arr[i-2]=i;
	}
	for(i=3;i*i<N;i++){
		int j;
		if(arr[i-2]!=0){

		for(j=2;i*j<N;j++){
			arr[i*j-2] = 0;

		}
		}
	}
	printf("%5d",2);
	int n=1;
	for(i=0;i<N-2;i++){
		
		if(arr[i]!=0&&(i%2)!=0){
		printf("%5d",arr[i]);
		n++;
		if(n%5==0)printf("\n");
		}
		
	}
	printf("\nprime counts:%d",n);
	return 0;
}
