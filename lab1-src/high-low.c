#include <stdio.h>
//

main(int argc, char **argv) {
	int low;
	int high;
	int mid;
	char c;
	printf("Welcome to the High Low game...\n");
	printf("Think of a number between 1 and 100 and press <enter>\n");
	do{
	low = 1;
	high = 100;
	mid = (low + high) / 2;
	do{
		printf("Is it higher than %d? (y/n)\n",mid);
		scanf("%c", &c);
		if(c != 'y' || c != 'n'){
		printf("Please enter y or n\n");
		if(c == 'y'){
		low = mid + 1;
		}
		if(c == 'n') {
		high = mid - 1;
		}
		mid = (low + high)/2;
		if(high < low){
		mid++; 
		}

		while(getchar()!='\n');
		}
		while(high >= low);
		printf(">>>>>> The number is %d\n",mid);
		printf("Do you want to continue playing (y/n)?\n");
		scanf("%c", &c);
		if(c == 'n'){
		printf("Thanks for playing!!!\n");
		}
		while(getchar()!='\n');
		}while(c == 'y')
			return 0;
	}
		
}

