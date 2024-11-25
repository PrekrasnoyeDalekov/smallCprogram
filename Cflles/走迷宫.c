#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_STACK_SIZE 1000
#define TEST_MATRIX  {\
{0,0,1,0,0,0,1,0}, \
{0,0,1,0,0,0,1,0}, \
{0,0,0,0,1,0,0,1}, \
{1,1,1,1,0,0,1,0}, \
{0,0,0,1,0,0,0,0}, \
{0,1,0,0,0,1,0,1}, \
{0,1,1,1,1,0,0,1}, \
{1,1,0,0,1,1,0,1}, \
{1,1,0,0,0,0,0,0}, \
}
#define COUNT_I 9
#define COUNT_J 8
#define START_I 0
#define START_J 0
#define END_I 8
#define END_J 7


typedef struct {
	int x;
	int y;
}location;
typedef struct {
	location data[MAX_STACK_SIZE];
	int top;
}STACK;


void set_color(short x){
	if(x>=0&&x<=15){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}
STACK* init_stack(){
	STACK *s = (STACK*)malloc(sizeof(STACK));
	s->top = -1;
	return s;
}

void stack_overflow(){
	printf("Stack overflowed!");
	exit(0);
}
void stack_underflow(){
	printf("Stack underflowed!");
	exit(0);
}

bool is_stack_empty(STACK *s){
	return s->top==-1;
}

bool is_stack_full(STACK *s){
	return s->top == MAX_STACK_SIZE-1;
}

void push(STACK *s,location *l){
	if(is_stack_full(s)) stack_overflow();
	else{
		s->data[++(s->top)] = *l;
	}
}

location pop(STACK *s){
	if(is_stack_empty(s)) stack_underflow();
	else{
		return s->data[(s->top)--];
	}
}

bool visit_maze(int maze[][COUNT_J],location history_path[][COUNT_J]){
	// history_path 在(i,j)存储上一步的位置
	STACK *stack = init_stack();
	location temp = {START_I,START_J};
	int current_i=temp.x,current_j=temp.y;
	if(maze[START_I][START_J]==0) push(stack, &temp);
	else return false;
	while(!is_stack_empty(stack)){
		current_i = temp.x;
		current_j = temp.y;
		maze[current_i][current_j] = 2;  // 走过的位置标记为2
		if(current_i==END_I && current_j==END_J) break;

		// 向下走
		if(current_i+1<=COUNT_I && maze[current_i+1][current_j]==0){
			maze[current_i+1][current_j] = 2;
			history_path[current_i+1][current_j].x = current_i;
			history_path[current_i+1][current_j].y = current_j;
			temp.x=current_i+1;
			temp.y=current_j;// 不变
			push(stack,&temp);

		}
		// 向右走
		else if(current_j+1<=COUNT_J && maze[current_i][current_j+1]==0){
			maze[current_i][current_j+1] = 2;
			history_path[current_i][current_j+1].x = current_i;
			history_path[current_i][current_j+1].y = current_j;
			temp.x=current_i;// 不变
			temp.y=current_j+1;
			push(stack,&temp);
			
		}
		// 向上走
		else if(current_i-1>=0 && maze[current_i-1][current_j]==0){
			maze[current_i-1][current_j] = 2;
			history_path[current_i-1][current_j].x = current_i;
			history_path[current_i-1][current_j].y = current_j;
			temp.x=current_i-1;
			temp.y=current_j;// 不变
			push(stack,&temp);
		}
		// 向左走
		else if(current_j-1>=0 && maze[current_i][current_j-1]==0){
			maze[current_i][current_j-1] = 2;
			history_path[current_i][current_j-1].x = current_i;
			history_path[current_i][current_j-1].y = current_j;
			temp.x=current_i;// 不变
			temp.y=current_j-1;
			push(stack,&temp);

		}

		else temp = pop(stack);		
	}
	// 循环结束后，判断是否到达终点
	if(current_i==END_I && current_j== END_J){
		maze[current_i][current_j] = 3; // 用3表示回溯过程
		while(history_path[temp.x][temp.y].x!=-1){// -1表示初始位置
			temp = history_path[temp.x][temp.y];
			maze[temp.x][temp.y] = 3;
		}
		return true;
	}
	else return false;
}

void print_maze(int maze[COUNT_I][COUNT_J]){
	for(int i=0;i<=COUNT_I;++i) printf("-");
	printf("\n");
	for(int i=0;i<COUNT_I;++i){
		printf("|");
		for(int j=0;j<COUNT_J;++j){
			switch(maze[i][j]){
			case 1:printf("#");break;  // 迷宫墙壁
			case 0:case 2:printf(" ");break;  // 迷宫通路
			case 3:set_color(4);printf("%%");set_color(15);break; // 迷宫解法
			}
		}
		printf("|\n");
	}
	for(int i=0;i<=COUNT_I;++i) printf("-");
	printf("\n");

}


int main(){
	// 初始化迷宫
	location history_path[COUNT_J][COUNT_J]={0};
	history_path[START_I][START_J].x=-1;
	int maze[COUNT_I][COUNT_J]=TEST_MATRIX;
	set_color(2);
	printf("MAZE:\n");
	set_color(15);
	print_maze(maze);
	if(visit_maze(maze,history_path)){
		set_color(2);
		printf("SOLUTION:\n");
		set_color(15);
		print_maze(maze);
	}
	else {
		set_color(4);
		printf("No solution!");
		set_color(15);
	}
	return 0;
}
