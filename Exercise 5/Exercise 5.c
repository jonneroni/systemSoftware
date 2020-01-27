/* File: Exercise5.c
 * Author: Anton Leinonen, Jonne Kaajalahti
 * Description: Exercise5
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct language
{
	char languageName[100];
	char isoCode[100];
	char languageFamily[100];
	double speakerAmount;
};

void printLanguages(struct language *ptr, int languageAmount){
	
	printf("\n***LIST OF LANGUAGES***\n\n");
	int i;
	for(i = 0; i < languageAmount ; ++i){

		printf("Name:\t\t%s\n", (ptr+i)->languageName);
		printf("Code:\t\t%s\n", (ptr+i)->isoCode);
		printf("Family:\t\t%s\n", (ptr+i)->languageFamily);
		printf("Speakers:\t%.2lf\n\n", (ptr+i)->speakerAmount);
	}
}

void addLanguages(int languageAmount){

	struct language *ptr;
	int i;
	char input[100];
	double testDouble;
	int status = 0;

	
   
	// Allocates the memory for languageAmount structures with pointer ptr pointing to the base address.
	ptr = (struct language*) malloc (languageAmount * sizeof(struct language));

	for(i = 0; i < languageAmount; ++i){
		do{
			printf("Enter name of the language: ");	
			fgets(input, sizeof input, stdin);
			sscanf(input,"%s", (ptr+i)->languageName);		
			if (strlen ((ptr+i)->languageName) > 30){
				printf("Please enter less than 30 characters\n");
			}

		}while (input[0] == '\n' || input[0] == ' ' || strlen ((ptr+i)->languageName) > 30);
		
		do{
			printf("Enter the ISO 639-1 code: ");
			fgets(input, sizeof input, stdin);
			sscanf(input,"%s", (ptr+i)->isoCode);
			if (strlen ((ptr+i)->isoCode) > 30){
				printf("Please enter less than 30 characters\n");
			}
		}while (strlen ((ptr+i)->isoCode) > 30);

		do{
			printf("Enter the language family: ");
			fgets(input, sizeof input, stdin);
			sscanf(input,"%s", (ptr+i)->languageFamily);
			if (strlen ((ptr+i)->languageFamily) > 30){
				printf("Please enter less than 30 characters\n");
			}
		}while (strlen ((ptr+i)->languageFamily) > 30);

		do{
			printf("Enter the number of people speaking the language in millions: ");
			fgets(input, sizeof input, stdin);
			if (sscanf(input, "%lf", &testDouble) == 1){
				if (testDouble < 999999999.0){
					sscanf(input, "%lf", &(ptr+i)->speakerAmount);
					status = 1;
				}
				else{
					printf("Please input a value lower than 999999999\n");				
				}
			}
			else{
				printf("Please enter a valid number\n");
			}
     
		}while (status == 0);
		
	}
	printLanguages(ptr, languageAmount);
	free(ptr);

}


int main(){

	char inputValue[100] = "";
	int languageAmount;
	int i;
	int status = 0;

	do{
		printf("How many languages you want to add? ");
		fgets(inputValue, sizeof inputValue ,stdin);
		int length = strlen(inputValue);
		for (i = 0; i < length-1; i++){
			
			if (!isdigit(inputValue[i])){
				printf("Please enter only integers\n");
				status = 0;
				break;
			}
			else{
				status = 1;			
			}
		}

	}while(status == 0);
	
	languageAmount = atoi(inputValue);
	addLanguages(languageAmount);
	
	
	return 0;
}