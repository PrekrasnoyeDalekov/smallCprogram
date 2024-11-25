#include "LINK.h"


event_list *init_list(){
	event_list *l=(event_list *)malloc(sizeof(event_list));
	l->next=NULL;
	return l;
}

void insert_event(event_list* l,event ev){
	for(;l->next!=NULL&&l->next->e.occur_time<ev.occur_time;l=l->next);
	event_list *new_node = (event_list*)malloc(sizeof(event_list));
	new_node->e = ev;
	if(l->next==NULL){
		new_node->next = NULL;
		l->next = new_node;
	}
	else{
		new_node->next=l->next;
		l->next = new_node;
	}
}
bool is_event_empty(event_list *l){
	return l->next == NULL;
}

event pop(event_list *l){
	event_list *temp = l->next;
	l->next=temp->next;
	event e=temp->e;
	free(temp);
	return e;	
}

