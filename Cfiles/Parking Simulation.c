#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define QUEUE_SIZE 100
int n;
float charge,income = 0;
void set_color(short x){
	if(x>=0&&x<=15){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}




typedef struct {
	unsigned short no;
	time_t arrival;
	time_t departure;
}car;

/*								STACK 									*/
typedef struct {
	car *car_list;
	int top;
}STACK;

STACK* init_stack(){
	STACK *s = (STACK*)malloc(sizeof(STACK));
	s->car_list = (car*)malloc(sizeof(car)*n);
	s->top = -1;
	return s;
}

void overflow(){
	printf("Overflowed!");
}
void underflow(){
	printf("Underflowed!");
}

bool is_stack_empty(STACK *s){
	return s->top==-1;
}

bool is_stack_full(STACK *s){
	return s->top == n-1;
}

void push(STACK *s,car *l){
	if(is_stack_full(s)) overflow();
	else{
		s->car_list[++(s->top)] = *l;
	}
}

car *pop(STACK *s){
	if(is_stack_empty(s)){
		underflow();
		return (car*)NULL;
	}
	else{
		return &(s->car_list[(s->top)--]);
	}
}


void display_stack(STACK *s){
	if(is_stack_empty(s))printf("There is no car inside!\n");
	else{
		printf("Index\tCar No.\t	Arrival Time\n");
		for(int i=0;i<=s->top;++i){
		set_color(4);
		printf("%d\t%d\t%s",i,s->car_list[i].no,asctime(localtime(&(s->car_list[i].arrival))));
		}
		set_color(15);
	}
		
}

/*									QUEUE								*/
typedef struct{
	car *waiting_cars;
	int front,rear;
}QUEUE;// 循环队列,front指向第一个元素,rear指向队尾的下一个元素.

QUEUE *init_queue(){
	QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
	q->waiting_cars = (car*)malloc(sizeof(car)*QUEUE_SIZE);
	q->front = q->rear = 0;
	return q;

}

bool is_queue_empty(QUEUE *q){
	return q->front == q->rear;
}

bool is_queue_full(QUEUE *q){
	return (q->rear + 1) % QUEUE_SIZE == q->front;
}

void en_queue(QUEUE *q,car *new_car){
	if(is_queue_full(q)) overflow();
	else{
		q->waiting_cars[q->rear++] = *new_car; 
	}
}

void display_queue(QUEUE *q){
	if(is_queue_empty(q))printf("There is no car waiting!\n");
	else{
		printf("Car No.\t	Arrival Time\n");
		for(int i=q->front;i<q->rear;i=(i+1)%QUEUE_SIZE){
			set_color(4);
			printf("%d\t%s",q->waiting_cars[i].no,asctime(localtime(&(q->waiting_cars[i].arrival))));
		}
		set_color(15);
	}
	
}
car *de_queue(QUEUE *q){
	if(is_queue_empty(q)){
		return (car *)NULL;
	}
	else {
		return &(q->waiting_cars[q->front++]);
	}
}

void car_arrival(STACK *s,QUEUE *q){
	if(is_queue_full(q)){
		printf("There is no space left!\n");
		return ;
	}
	else{
		int car_no;
		printf("Input car number:");
		scanf("%d",&car_no);
		car *new_car = (car*)malloc(sizeof(car));
		new_car->no = car_no;
		new_car->arrival = time((NULL));
		if(!is_stack_full(s)) push(s,new_car);
		else en_queue(q,new_car);
	}
}

void car_departure(STACK *s,QUEUE *q){
	display_stack(s);
	if(!is_stack_empty(s))
	{printf("Input car index:");
		int car_index;
		scanf("%d",&car_index);
		if(car_index>s->top) {
			set_color(4);
			printf("Invalid Index!\n");
			set_color(15);}
		else{
			int ops = s->top - car_index;
			car *temp[ops];
			for(int i=0;i<ops;++i){
				temp[i] = pop(s);
			}
			car leaving_car = *pop(s);
			leaving_car.departure = time(NULL);
			float cost = charge * (leaving_car.departure-leaving_car.arrival);
			income += cost;
			for(int i=0;i<ops;++i){
				push(s,temp[i]);
				
			}
			printf("Car \"%d\" costs $%g,\narriving at %s,\nleaving at %s",leaving_car.no,cost,asctime(localtime(&(leaving_car.arrival))),asctime(localtime(&(leaving_car.departure))));
			car *in_car = de_queue(q);
			if(in_car)
			{
				in_car->arrival = time(NULL);
				push(s,in_car);
			}
			
		}
	}

}


void hello() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scr;
	GetConsoleScreenBufferInfo(out, &scr);
	int length = scr.srWindow.Right;        // 窗口长度
	const char *word1 = "Parking Simulation";
	int word_len = strlen(word1);
	int left_padding = (length - word_len) / 2;
	int right_padding = length - word_len - left_padding;	
	set_color(2);
	printf("%*s%s%*s\n", left_padding, "", word1, right_padding, "");  // 居中显示
	set_color(15);
	printf("Please Enter the Parking Capacity:");
	scanf("%d",&n);
	printf("Please Enter the Parking Price:");
	scanf("%f",&charge);
	set_color(4);
	printf("\nInformation:\n");
	printf("Parking Capacity: %d\n",n);
	printf("Parking Charge: $%g per second\n",charge);
	set_color(6);
	printf("\nCOMMAND:\n\t 0:Quit\n\t 1:Car Arrival\n\t 2:Car Departure\n\t 3:Display Cars Inside\n\t 4:Dispaly Waiting Cars\n");
	set_color(15);
}

int main(void){
	hello();
	STACK *s = init_stack(n);
	QUEUE *q = init_queue();
	enum command_code{QUIT,ARRIVAL,DEPARTURE,DISPLAY_INSIDE,DISPLAY_WAITING};
	int command;
	for(;;){
		printf("\nEnter command code:");
		scanf("%d",&command);
		switch (command) {
		case 0:printf("The current income is $%g.",income);return 0;
		case 1:car_arrival(s,q);break;
		case 2:car_departure(s,q);break;
		case 3:display_stack(s);break;
		case 4:display_queue(q);break;
		}
		
	}
		
	exit(EXIT_FAILURE);
}
