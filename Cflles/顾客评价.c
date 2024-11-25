#include <stdio.h>
#include <stdlib.h>
int count(int k,int *a){
	int s=0,*p=a;
	for(;*p!=-1;){
		if(*(p++)==k)s++;
	}
	return s;
}
int main(){
	printf("请输入评价（以-1结束）：\n");
	int n;
	int l=1;
	int *arr=(int *)malloc(0);
	do{
		arr = (int *)realloc(arr,sizeof(int)*l);
		scanf("%d",&n);
		arr[l-1] = n;
	}while(n!=-1&&l++);
	l--;
	printf("%d\n",l);
	
	int c5,c4,c3,c2,c1;
	c5=count(5,arr);
	c4=count(4,arr);
	c3=count(3,arr);
	c2=count(2,arr);
	c1=count(1,arr);
	printf("Grade(*)\tCount(n)\tPercent(%%)\t");
	printf("\n5     \t%9d\t%11.0f\t",c5,(c5==0)? 0:100.0*c5/l);
	printf("\n4     \t%9d\t%11.0f\t",c4,(c4==0)? 0:100.0*c4/l);
	printf("\n3     \t%9d\t%11.0f\t",c3,(c3==0)? 0:100.0*c3/l);
	printf("\n2     \t%9d\t%11.0f\t",c2,(c2==0)? 0:100.0*c2/l);
	printf("\n1     \t%9d\t%11.0f\t",c1,(c1==0)? 0:100.0*c1/l);
	
}
