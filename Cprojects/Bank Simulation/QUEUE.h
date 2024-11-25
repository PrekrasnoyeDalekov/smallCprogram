#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

#ifndef Bank_Windows
#define Bank_Windows 4
#endif
typedef struct {
	int arrivalTime;
	int duration;
}client;

typedef struct Queue_node{
	client c;
	struct Queue_node *next;
}Queue,*Queue_list;

void init_queue(Queue_list &);
void new_custom(Queue_list,client);
int shortest_Queue(Queue_list []);
int Queue_len(Queue_list);
client del_Que_head(Queue_list &);
bool is_Que_empty(Queue_list);
#endif
