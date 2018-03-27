
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
	double a = 0.0 , b = 0.0, c = 0.0;
	FILE *fd = fopen(fileName, "r");

	char * word;
	while (word = nextword(fd)){
		//printf("wihiauwhduhduiwh %s\n",word);
		if(strcmp(word,"+")==0){
			//printf("What are you doing here\n");
			a = stack_pop();
			b = stack_pop();
			//printf("A = %f\n",a);
			//printf("B = %f\n",b);
			c = a + b;
			stack_push(c * 1.0);
			//printf("Sum: %f\n",c);
		}
		else if(strcmp(word, "-")==0){
			a = stack_pop();
			b = stack_pop();
			c = (b - a);
			stack_push(c);
		}
		else if(strcmp(word,"x")==0) {
			stack_push(x);
		}
		else if(strcmp(word,"*")==0){
			a = stack_pop();
			b = stack_pop();
			c = (b * a);
			stack_push(c);
		}
		else if(strcmp(word,"/")==0){
			a = stack_pop();
			b = stack_pop();
			c = (b / a);
			stack_push(c);
		}
		else if(strcmp(word,"sin")==0){
			a = stack_pop();
			c = (sin(a));
			stack_push(c);
		}
		else if(strcmp(word,"cos")==0){
			a = stack_pop();
			c = (cos(a));
			stack_push(c);
		}
		else if (strcmp(word,"pow")==0){
			a = stack_pop();
			b = stack_pop();
			c = pow(b, a);
			stack_push(c);
		}
		else if(strcmp(word,"log")==0){
			a = stack_pop();
			c = (log(a));
			stack_push(c);
		}
		else if(strcmp(word,"exp")==0){
			a = stack_pop();
			c = (exp(a));
			stack_push(c);
		}
		else{
			stack_push(atof(word));
			//stack_print();
			//printf("Number: %f\n",atof(word));
		}
	}
	//stack_print();
	if(stack_top() > 1){printf("Elements remain in the stack\n");exit(0);}
  	if(stack_top() == 1) {
		a = stack_pop();
		return a;
	}
}
