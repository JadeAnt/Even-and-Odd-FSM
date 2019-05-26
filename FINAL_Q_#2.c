#include <stdio.h>
#include <stdlib.h>

#define STATE_EE	0
#define STATE_EO	1
#define STATE_OE	2
#define STATE_OO	3

#define IN_EVEN	0
#define	IN_ODD	1

//#define OFF	0
#define ON_EVEN	0
#define ON_ODD	1

//global variable 
int isEven(int value){
	if( (value % 2) == 0)
		return 1;
	else
		return 0;
}

int transition_table[4][2] = {STATE_EE, STATE_EO, 
							   STATE_OE, STATE_OO,
							   STATE_EE, STATE_EO,
							   STATE_OE, STATE_OO};

int output_table[4][2] = { ON_EVEN, ON_EVEN,
						   ON_EVEN, ON_ODD,
						   ON_EVEN, ON_ODD,
						   ON_ODD, ON_ODD};

int main(int argc, char *argv[]){
	int current_state= STATE_EE;
	int the_sequence = ON_EVEN;
	int column, nr_a = 0, nr_b = 0, check = 1;
	char value;
	
	printf("Input Integer: ");
	scanf("%d", &value);
		
	if(isEven(value) == 1)
		column = IN_EVEN;
	else 
		column = IN_ODD;
	
	printf("hello");
	
	while(1){		
		
		
		the_sequence= output_table [current_state][column];
		current_state= transition_table [current_state][column];
		
		printf("current state %d\n", current_state);
		
		if(the_sequence == ON_EVEN){
			printf("2 of Last 3 values are even = 0\n");
		}
		else if(the_sequence == ON_ODD){
			printf("2 of Last 3 values are odd = 1\n");	
		}
		
		printf("\n");
			printf("Input Integer): \n");
			scanf("%d", &value);
			
			if(isEven(value) == 1)
				column = IN_EVEN;
			else 
				column = IN_ODD;	
		
		
	}
	
	return 0;
}
