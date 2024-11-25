#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

double numbers[STACK_SIZE] = {0.0f};
int top_num = 0;
double *p = &numbers[0];

void stack_overflow(){
	printf("The expression is too long!");
	exit(0);
}
void stack_underflow(){
	printf("Unmatched expression!");
	exit(0);
}

bool is_empty()
{
	return top_num == 0;
}

bool is_full()
{
	return top_num == STACK_SIZE;
}
// 压入
void push(double i)
{
	void stack_overflow();
	if (is_full())
		stack_overflow();
	else	
		numbers[top_num++] = i;
}
// 弹出
double pop()
{
	void stack_underflow();
	if (is_empty())
		stack_underflow();
	else
		return numbers[--top_num];
}



bool tonum(char *ch){
	switch(*ch){
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
		*ch =(double)*ch - 48.0f;
		return true;
	case '+':case '-':case '*':case '/':case '=':
		return true;
	default:return false;
	}
}
int main(){
	printf("Enter RPN expression:");
	char operand;
	scanf(" %c",&operand);
	while(tonum(&operand)){
		switch(operand){
		case 0:case 1:case 2:case 3:case 4:
		case 5:case 6:case 7:case 8:case 9:
			push(operand);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			push(pop() - pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			push(pop() / pop());
			break;
		case '=':
			printf("Ans:%f\n",pop());
			printf("Enter a RPN expression:");
			break;
			
		}
		scanf(" %c",&operand);

	}
	return 0;	
}
