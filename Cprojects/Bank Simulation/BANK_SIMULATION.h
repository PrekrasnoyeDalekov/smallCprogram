#ifndef BANK_SIMULATION_H
#define BANK_SIMULATION_H



#include "LINK.h"
#include "QUEUE.h"
#include "INFO_DISPLAY.h"
#include <time.h>
#include <stdlib.h>

#ifndef Bank_Windows
#define Bank_Windows 4
#endif

#define CLOSE_TIME 500
#define Max_Intertime 8
#define Max_Duration 20

extern event_list *el;
extern Queue_list  q[Bank_Windows+1];
extern int total_time,custom_num;


float bank_simulation();
void begin_new_day();
void custom_arrival(event);
void custom_departure(event);
int random_int();

#endif
