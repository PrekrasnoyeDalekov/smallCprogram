#include "BANK_SIMULATION.h"



void begin_new_day(){
	el = init_list();
	event ev_0;
	ev_0.occur_time = 0;
	ev_0.type = 0;
	insert_event(el,ev_0);
	for(int i=1;i<=Bank_Windows;++i){
		init_queue(q[i]);
	}
}

int random_int(int start,int end){
	// get an int ranging [start,end], using currnet time seed.
	if (start==0) return rand();
	else{
	srand(time(NULL) - random_int(start-1,end)); // time()函数只精确到秒，随机效果很差。所以我递归了一次
	return rand() % (end-start+1) + start;
	}
}
void custom_arrival(event current_event){
	++custom_num;
	int durtime = random_int(1,Max_Duration);
	int intertime = random_int(1,Max_Intertime);
	int t=current_event.occur_time+intertime;
	if(t<CLOSE_TIME){
//		event temp={t,0};
//		insert_event(el,temp);
		insert_event(el,(event){t,0}); // [警告] ISO C++ forbids compound-literals [-Wpedantic]
	}// Once a custom arriving, process next custom arrival event.
	int shortest_window = shortest_Queue(q);
//	client temp = {current_event.occur_time,durtime};
//	new_custom(q[shortest_window],temp);
	new_custom(q[shortest_window],(client){current_event.occur_time,durtime}); // [警告] ISO C++ forbids compound-literals [-Wpedantic]
	// Current custom in queue.
	if(Queue_len(q[shortest_window])==1){
//		event temp = {current_event.occur_time+durtime,shortest_window};
//		insert_event(el,temp);
		insert_event(el,(event){current_event.occur_time+durtime,shortest_window});// [警告] ISO C++ forbids compound-literals [-Wpedantic]
	}
	// 如果恰好是队头，立即生成离开事件。
	
}

void custom_departure(event current_event){
	int window = current_event.type;
	client departure_custom = del_Que_head(q[window]);
	total_time += current_event.occur_time - departure_custom.arrivalTime;
	if(!is_Que_empty(q[window])){
//		event temp = {current_event.occur_time+q[window]->next->c.duration,window};
//		insert_event(el,temp);
		insert_event(el,(event){current_event.occur_time+q[window]->next->c.duration,window});  //[警告] ISO C++ forbids compound-literals [-Wpedantic]
	}// Once becoming the first one, process its departure event.
}

float bank_simulation(){
	begin_new_day();
	while(!is_event_empty(el)){
		event current_event = pop(el);
		if(current_event.type==0)custom_arrival(current_event);
		else custom_departure(current_event);
	}
	float average_time = float(total_time) / custom_num;
	return average_time;
}
