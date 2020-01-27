/* File: Exercise1b.c
 * Authors: Jonne Kaajalahti
 * Description: Practicing loops
 */

#include <stdio.h>

void oddNumbers(int lower, int upper);
void divisibleNumbers();
void sumOfMultiples();


int main() {

	printf("Print out odd numbers between 40 and 0:\n");

	oddNumbers(0, 40);

	printf("\n\nPrint out numbers divisible by both 2 and 3 between 0 and 100:\n");

	divisibleNumbers();

	printf("\n\nPrint out the sum of multiples of 4 and 7 between 0 and 999:\n");

	sumOfMultiples();

	return 0;

}
// prints out all odd numbers from a given range
void oddNumbers(int lower, int upper) {

    for(int i = upper; i > lower; i--)
	{
	    if (i %2 != 0)
		{
	    	    printf("%d\n",i);	
		}
	}
}

// prints all numbers between 0 & 100 that are divisible by 2 and 3
void divisibleNumbers() {

    for(int i = 0; i <= 100; i++)
	{
	    if (i %2 == 0 || i %3 == 0)
		{
	    	    printf("%d, ",i);	
		}
	}
}

// prints the sum of multiples of 4 and 7 between 0 and 999
void sumOfMultiples() {
	int sum = 0;
    for (int i = 0; i <= 999; i++)
	{
	  if (i %4 == 0 || i %7 == 0)
		{
	    	    sum = sum + i;	
		}
	}
	printf("%d\n", sum);
}