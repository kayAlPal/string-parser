#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* createArray(int * numElem);
int tokenMaker(char str[], char* tokenArray[]);
void analyizeArray(int* intArray, int* numElem); 
void getChars(char str[], const int maxChars);
int* arrayAlloc(int* numElem);
void arrayFill(char* tokenArray[], int* intArray, int* numElem); 
void shellSort(int * intArray, int * numElem); 
void getMode(int * intArray, int * numElem); 
void iterateArray(int* intArray, int* numElem, double average); 
int printArray(int* intArray, int* numElem); 


int main( void )
{
	int* numElem;
	int i;  
	int* theArray; 
	theArray = createArray(numElem);
	analyizeArray(theArray, numElem); 
	return 0;
}

int* createArray(int * numElem)
{
	int * intArray;  
	const int maxChars = 81; 
	char* tokenArray[maxChars];
	char str[maxChars];   
	getChars(str, maxChars); 
	*numElem = tokenMaker(str, tokenArray);
	intArray  = arrayAlloc(numElem);
	arrayFill(tokenArray, intArray, numElem);    
	shellSort(intArray, numElem); 
	return intArray; 
}

void analyizeArray(int* intArray, int* numElem)
{
	int average; 
	average = printArray(intArray, numElem); 
	getMode(intArray, numElem); 
	iterateArray(intArray, numElem, average); 
}

void getChars(char str[], const int maxChars)
{ 
	char c; 
	int k = 0;
	int l;
	int e;  
	do {
		l = 0; 
		printf("Please input the integers for analysis:\n"); 
		while (((c = getchar()) != '\n') && (l != maxChars))
		{
			if ((c == 32) || (c == 45) || ((c > 47) && (c < 58)))
			{ 
				str[k] = c; 
				k++; 
				l++;
			}
			else
			{
				printf("Please enter only integers or white space. %c is not an integer.\n", c); 
			} 
		}
		 
		printf("Enter 1 to continue followed by a space and more numbers or enter zero to exit:\n"); 
		scanf("%i", &e); 
	} while (e != 0); 
	return; 			
}

int tokenMaker(char str[], char* tokenArray[])
{

	int count = 0; 
	if ((tokenArray[0] = strtok(str, " \t")))
	{
		count++; 
	}
	while ((tokenArray[count] = strtok(NULL, " \t")))
	{
		count++; 
	}
	return count;
}

int* arrayAlloc(int* numElem)
{
	int* pointer_dm = (int*)malloc(*numElem * (sizeof(int)));
	return pointer_dm;  
}		

void arrayFill(char* tokenArray[], int* intArray, int* numElem)
{
	int i; 
	

	for (i = 0; i < *numElem; i++)
	{
		intArray[i] = atoi(tokenArray[i]);  

  	}
	
	return; 
}

void shellSort(int * intArray, int * numElem)
{
	int gap;
	int i;
	int temp;   
	int index;
 
	for (gap = (*numElem / 2); gap > 0; gap = gap == 2 ? 1 : ((int) gap/ 2.2))
	{
		for (i = gap; i < *numElem; i++)
		{
			temp = intArray[i]; 
			index = i; 
			
			for ( ; index >= gap && (temp < intArray[index-gap]); index -= gap)
			{
				intArray[index] = intArray[index - gap]; 
			}
			intArray[index] = temp; 
		}
	}

	return; 
}

void getMode(int * intArray, int * numElem)
{
	int i; 
	int tempMode = intArray[0]; 
 	int mode;
	int frequency = 1;
	int tempFreq = 1; 
	
	for(i = 1; i < *numElem; i++)
	{
		if (tempMode == intArray[i]) 
		{

			++tempFreq;
			
			if(tempFreq > frequency)
			{
				frequency = tempFreq;
				mode = tempMode;  
			}	
		}
		else
		{
			tempMode = intArray[i];
			tempFreq = 1;  
		 }

	}
	printf("The mode is %i and the frequency is %i\n\n", mode, frequency);
	return;  
}
	
void iterateArray(int* intArray, int* numElem, double average)
{
	int i;
	int aboveAv = 0; int belAv = 0; int atAv = 0; int pos = 0; int neg = 0; int zero = 0;   
	for (i = 0; i < *numElem; i++)
	{
		if (intArray[i] > 0)
		{
			pos++; 
		}
		else if (intArray[i] < 0)
		{
			neg++; 
		}
		else 
		{
			zero++; 
		}
		if (intArray[i] > average)
		{
			aboveAv++; 
		}
		else if (intArray[i] < average)
		{
			belAv++; 
		}
		else
		{
			atAv++; 
		}
	}
	printf("The average value is %.2lf\n\n", average); 
	
	if (aboveAv != 1)	
	{
		printf("%3i values are above average.\n", aboveAv); 
	
	}
	else
	{		
		printf("%3i value is above average.\n", aboveAv); 
	}
	if (belAv != 1)
	{
		printf("%3i values are below average.\n", belAv); 
	}	
	else
	{
		printf("%3i value is below average.\n", belAv); 
	}
	if (atAv != 1)
	{
		printf("%3i values are equal to the average.\n\n", atAv); 
	}
	else
	{
		printf("%3i value is equal to the average.\n\n", atAv); 
	}

	if (pos != 1)
	{
		printf("%3i values are postive.\n", pos);
	} 
	else
	{
		printf("%3i value is postive.\n", pos);
	}
	if (neg != 1)
	{
		printf("%3i values are negative.\n", neg);
	} 
	else
	{
		printf("%3i value is negative.\n", neg);
	}
	if (zero != 1)
	{
		printf("%3i values are zero.\n", zero); 
	}
	else
	{
		printf("%3i value is zero.\n", zero); 
	}
}


int printArray(int* intArray, int* numElem)
{
	int i;
	double average;  
	int count = 0; int sum = 0;  
	for (i = 0; i < *numElem; i++)
	{
		printf("[%3i] %12i\t", i, intArray[i]); 
		count++; 
		if (count == 5)
		{
			printf("\n"); 
			count = 0; 
		}
		sum += intArray[i];
	}
	average = (double) sum / *numElem; 
	printf("\n\n"); 
	printf("The median value is %i\n\n", intArray[*numElem/2]);  
	return average; 
}
