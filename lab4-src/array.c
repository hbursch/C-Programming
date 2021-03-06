
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
double * p = array;
double * pend = p+n;
double maxElm = *p;

while(p < pend){
	if(*p > maxElm){
		maxElm = *p;
	}
	p++;
}
return maxElm;
}

// Return minimum element of array
double minArray(int n, double * array) {
double * p = array;
double * pend = p+n;

double minElm = *p;
while(p < pend){
	if(*p < minElm){
		minElm = *p;
	}
	p++;
}
return minElm;
}

// Find the position in the array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
  	
  return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
	
}

// Print array
void printArray(int n, double * array) {
	double * p = array;
	for(int i = 0; i < n; i++){
		printf("%f", *p);
		p++;
	}
}

