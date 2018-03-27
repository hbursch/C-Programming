
#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
	int count = 0;
	while(*s != '\0'){
		count++;
		s++;
	}
	return count;
}

char * mystrcpy(char * dest, char * src) {
	char * start = dest;
	while(*src){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return start;
}

char * mystrcat(char * dest, char * src) {
	while(*src){
		src++;
	}
	while(*dest){
		*src = *dest;
		dest++;
		src++;
	}
	*src = '\0';
	return src;
}

int mystrcmp(char * s1, char * s2) {
	int i =0;
	while((*s1 != '\0') || (*s2 != '\0')){
		if(*s1 > *s2){
			return 1;
		}
		if(*s1 < *s2){
			return -1;
		}
		s1++;
		s2++;
	}
	return 0;
}

char * mystrstr(char * hay, char * needle) {
	if(!*needle) return hay;
	char *p1 = (char*)hay;
	while(*p1){
		char *p1Start = p1, *p2 = (char*)needle;
		while(*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2) return p1Start;
		p1 = p1Start +1;
	}

	return NULL;
}

char * mystrdup(char * s) {
	int len = mystrlen(s) + 1;
	char * copy;
	if(!(copy = malloc(sizeof(int)))){
		return(NULL);
	}
	return(copy);
}

char * mymemcpy(char * dest, char * src, int n){
	for(int i=0; i < n; i++){
		dest[i] = src[i];
	}
	return dest; 
}

