/* 
*File:		Exercise2.c
*Authors:	Jonne Kaajalahti, Anton Leinonen
*Description:	Exercise2 practicing basic C
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Random number is: %d\n",randomNumber());
    int collatzLen = collatz();
    primeCheck(collatzLen);  
}

int randomNumber() {
    srand(time(NULL));
    int randomnumber = rand() % 10001;
    return randomnumber;
}

int collatz(){
    int ran = randomNumber();
    int collatzNumber = ran;
    int collatzLength = 1;
    printf ("The Collatz sequence for %d is: %d - ", ran, ran);
    while (ran != 1){
        
        if (ran % 2 == 0){
            ran = ran/2;
            collatzLength++;
            if(ran == 1){
                printf ("%d\n", ran);
            }
            else{
                printf ("%d - ", ran);
            }
        }
        else if(ran % 2 != 0){
            ran = ran*3+1;
            collatzLength++;
            printf ("%d - ", ran);
        }
    }
    
    printf ("Collatz sequence length for %d is: %d\n", collatzNumber, collatzLength);
    return collatzLength;
}

int primeCheck(int checkedNumber){
    int mark = 0;
    for (int i = 2; i < checkedNumber; i++){
        if (checkedNumber % i == 0){
            mark = 1;
            break;
        }
    }

    if (mark == 0){
        printf("Number %d is prime \n", checkedNumber);
    }
    else if (mark == 1){
        printf("Number %d is not prime \n", checkedNumber);
    }
    return 0;
}