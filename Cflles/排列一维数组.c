#include <stdio.h>


void sort(int a[], int n, int reverse){// reverse=0: 升序;reverse=1: 降序
	if(reverse == 0){for(int i=0;i<n-1;i++){
		// 每一次把前n-i中最大的数推到最后
		for(int j=0;j<n-1-i;j++){
			if(a[j] > a[j+1]){
				int temp = 0;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}}
	else if(reverse == 1){
		for(int i=0;i<n-1;i++){
			// 每一次把前n-i中最小的数推到最后
			for(int j=0;j<n-1-i;j++){
				if(a[j] < a[j+1]){
					int temp = 0;
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
	}
		
}

int main(){
	int lenofarray1, reverse=-1;
	void sort(int [],int ,int );  //声明函数，在这个程序中可略去
	printf("Entr the length of the 1D array:");
	scanf("%d",&lenofarray1);
	printf("reverse=0→升序\nreverse=1→降序:\n");
	scanf("%d",&reverse);
	int b[lenofarray1];
	for(int k= 0;k< lenofarray1;k++){
		printf("\nEnter the element of the array:");
		scanf("%d",&b[k]);
	}
	sort(b,lenofarray1,reverse);
	for(int i=0;i<lenofarray1;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
