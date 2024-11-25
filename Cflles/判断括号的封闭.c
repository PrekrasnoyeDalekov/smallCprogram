#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

int contents[STACK_SIZE], top = 0;


bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}
// 压入
void push(char i)
{
	void stack_overflow();
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}
// 弹出
char pop(void)
{
	void stack_underflow();
	if (is_empty())
		stack_underflow();
	else
		return contents [--top];
}

void stack_overflow(){
	printf("stack overflow!");
	exit(0);
}
void stack_underflow(){
	printf("stack underflow!");
	exit(0);
}

int main(){
	printf("Enter parenteses/braces:");
	char parentese;
	parentese = getchar();
	while(parentese != '\n'){
		switch(parentese){
		case '{': case '[': case '(':
			push(parentese);break;
		case '}':
			if(pop() != '{'){printf("Parenteses/braces are not nested properly.");return 0;}
		case ']':
			if(pop() != '['){printf("Parenteses/braces are not nested properly.");return 0;}
		case ')':
			if(pop() != '('){printf("Parenteses/braces are not nested properly.");return 0;}
		}
		parentese = getchar();
	}
	printf("Parenteses/braces are nested properly.");
	return 0;
}
