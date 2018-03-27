#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void converter(int basefrom, int baseto, char *  num){
	int baseten = 0;
	int i = 0;
	
	//checks if either the baeto or basefrom are below 2 or above 25
	if(baseto < 2 || baseto > 25 || basefrom > 25 || basefrom < 2){
		return;
	}

	//this will find the base10 of the number IF basefrom != 10
	printf("Number read in base %d: %s\n", basefrom, num);
		int j = strlen(num);
		for(i = 0; i < strlen(num); i++){
			int a = num[i];
			if(a >= 65 && a <= 90){
				baseten += (a- 55) * pow(basefrom, --j);
			}
			else{
				baseten += (a - 48) * pow(basefrom, --j);
			}
		}
	//this will convert form base10 to the baseto
	
	printf("Converted to base 10: %d\n", baseten);
	i = 0;
	int c[50];
	int len = 0;
	while (baseten != 0) {
		c[i] = baseten % baseto;
		i++;
		baseten = baseten/baseto;
		len++;
	}
	printf("Converted to base %d: ", baseto);
	for (i = len - 1; i >= 0; i--) {
		if (c[i] >= 10) printf("%c",(char)(c[i]+55));
		else printf("%d",c[i]);
	}
	printf("\n");
}

int main(int argc, char **argv){
	if(argc < 4){
		printf("Usage:  convert <basefrom> <baseto> <number>\n");
		exit(1);
	}
	int basefrom = atoi(argv[1]);
	int baseto = atoi(argv[2]);
	char * num = argv[3];

	converter(basefrom, baseto, num);
}
