#include "BANK_SIMULATION.h"
#include <stdio.h>


event_list *el = (event_list*)malloc(sizeof(event_list));
Queue_list q[Bank_Windows+1];
int total_time = 0,custom_num = 0;


int main(){
	int loops;
	hello();
	printf("Simulation Times:");
	scanf("%d",&loops);
	set_color(4);
	printf("Average waiting time:\n");
	for(int i=0;i<loops;++i){
		float result = bank_simulation();
		printf("%f\n",result);
	}
	set_color(15);
	return 0;
}
