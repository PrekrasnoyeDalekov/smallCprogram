#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);
void split_time(long total_sec, int *hr, int *min, int *sec){
	*hr = total_sec / 3600;
	*sec = total_sec % 60;
	*min = (total_sec - 3600 * *hr)/60;
}

int main(){
	printf("Enter seconds:");
	long total_sec;
	int hr,min,sec;
	scanf("%ld",&total_sec);
	split_time(total_sec, &hr, &min, &sec);
	printf("%2d-%2d-%2d",hr,min,sec);
	return 0;
	
}
