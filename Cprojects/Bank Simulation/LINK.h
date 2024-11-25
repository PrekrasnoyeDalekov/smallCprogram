#ifndef LINK_H
#define LINK_H


#include <stdlib.h>
#include <stdio.h>

typedef int event_type;
typedef struct event{
	int occur_time;
	event_type type;
}event;

typedef struct event_list{
	event e;
	event_list *next;
}event_list;


event_list *init_list();
void insert_event(event_list *,event);
event pop(event_list *);
bool is_event_empty(event_list *);


#endif
