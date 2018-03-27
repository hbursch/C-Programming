
#include <stdio.h>
#include <stdlib.h>

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

// It returns the next word from fd.
// If there are no more more words it returns NULL. 
char * nextword(FILE * fd) {
  	int c;
	int i = 0;
	for(i = 0; i < MAXWORD; i++){
		word[i] = 0;
	}
	i = 0;
	while ((c = fgetc(fd)) != EOF){
		if(c != ' '  && c != '\t' && c != '\n'){
			word[i] = c;
			i++;
		}
		else if(i > 0) {
		return word;
		}
	}
	if(i > 0) return word;
	else if (c == EOF){ return NULL;}
	else{ return NULL;}
	
	// While it is not EOF read char
		// While it is not EOF and it is a non-space char
		// store character in word.
		// if char is not in word return word so far.
		//
	// Return null if there are no more words
}
