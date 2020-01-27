/* File: Exercise3.c
 * Authors: Anton Leinonen, Jonne Kaajalahti
 * Description: Exercise 3
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *numberFile;
    numberFile = fopen("Numbers.txt", "r");    // avataan tiedosto

    if (numberFile == NULL){        // tarkistetaan tiedoston olemassaolo
        printf("Error Reading File\n");
        exit (0);
    }

    int numberArray[50];
    int finalArray[100];
    int i, i2;

    for (i = 0; i < 100; i++){        // nollataan taulukko
        finalArray[i] = 0;
    }

    for (i = 0; i < 100; i++){        // 100 = lukujen mÃ¤Ã¤rÃ¤

        for(i2 = 50; i2 > 0; i2--){    // 50 = numeroiden mÃ¤Ã¤rÃ¤ luvuissa
            fscanf(numberFile, "%1d", &numberArray[i2-1]);
            finalArray[i2-1] = numberArray[i2-1] + finalArray[i2-1];
        }
    }

    for (i = 0; i < 100; i++){        // laskee sarakkeiden arvot yhteen
        finalArray[i+1] = finalArray[i+1] + ((finalArray[i]-finalArray[i]%10)/10);
        finalArray[i] = finalArray[i]-(finalArray[i]-finalArray[i]%10);
    }

    printf("The sum is: ");            // tulostaa yhteenlasketun arvon

    for (i = 52; i > 0; i--){

        printf("%d", finalArray[i-1]);
        
    }
    printf("\n");
}