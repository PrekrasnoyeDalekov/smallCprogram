#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

int task,min_mile,max_mile,week;

int main(){
	scanf("%d %d %d %d",&week,&task,&max_mile,&min_mile);
	long result[week+1][max_mile*week+1];
	memset(result,0,sizeof(result));
	for(int i=min_mile;i<=max_mile;i++)result[1][i]=1;
	for(int time=2;time<week;time++){
		for(int mile=min_mile*time;mile<=max_mile*time;mile++){
			for(int i=mile-max_mile;i<=mile-min_mile;result[time][mile]+=result[time-1][i++]);
			
		}
	}
	for(int i=task-max_mile;i<=max_mile*(week-1);i++){
		if(task-min_mile>i)result[week][task]+=result[week-1][i]*(max_mile-task+i+1);
		else result[week][task]+=result[week-1][i]*(max_mile-min_mile+1);
		
	}
	printf("%ld",result[week][task] % MOD);
	return 0;
}

