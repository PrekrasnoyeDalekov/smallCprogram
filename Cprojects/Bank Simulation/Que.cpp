#include "QUEUE.h"

void init_queue(Queue_list &l){
	l = (Queue_list) malloc(sizeof(Queue_node));
	l->next=NULL;
}

void new_custom(Queue_list l,client c){
	for(;l->next!=NULL;l=l->next);
	Queue *new_c = (Queue_list)malloc(sizeof(Queue));
	new_c->c=c;
	new_c->next = NULL;
	l->next = new_c;
	
}

int shortest_Queue(Queue_list q[]){
	int result=1;
	int shortest_len = Queue_len(q[1]);
	for(int i=2;i<=Bank_Windows;++i){
		if(Queue_len(q[i])<shortest_len){
			shortest_len = Queue_len(q[i]);
			result = i;
		}
	}
	return result;
}

int Queue_len(Queue_list line){
	int len = 0;
	for(;line->next!=NULL;line=line->next,len++);
	return len;
}

client del_Que_head(Queue_list &line){
	Queue *temp = (Queue*)malloc(sizeof(Queue)); // 这是一件很奇怪的事情，如果只是声明类型而不分配空间，下面的free(temp)操作就会出错！
	temp = line->next;
	line->next = temp->next;
	client head = temp->c;
	free(temp);
	return head;
}

bool is_Que_empty(Queue_list line){
	return line->next == NULL;
}
