
#include <stdio.h>
#include <stack.h>
#include <stdlib.h>

int top=0;
double stack[MAXSTACK];

void stack_clear() 
{
  top = 0;
}

double stack_pop(){
	// Add implementation here`
	if(stack != NULL && top != 0) {
		double num = stack[top-1];
		top--;
		return num;
	}
	else { printf("Stack underflow\n"); exit(0); }
}

void stack_push(double val)
{
	if(top <= MAXSTACK){
		stack[top] = val;
		top++;
	}
	// Add implementation here
}

void stack_print()
{	printf("Stack:\n");
	if(top == 0){
		printf("Stack is empty");
	}
	for(int i = 0; i < top; i++){
		printf("%d: %f\n", i, stack[i]);
	}
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
  return top == 0;
}


