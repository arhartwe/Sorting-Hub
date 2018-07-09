# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <getopt.h>
# include <stdbool.h>
# include "minSort.h"
# include "bubbleSort.h"
# include "insertionSort.h"
# include "quickSort.h"
# include "mergeSort.h"
# define MASK 0x00ffffff

//GLOBAL VARIABLES FOR COUNTS
int minMoves;
int minCompares;
int bubbleMoves;
int bubbleCompares;
int insertionMoves;
int insertionCompares;
int quickMoves;
int quickCompares;
int mergeMoves;
int mergeCompares;

int main(int argc, char **argv)
{
	int character;
	bool set = false;
	int arraySize = 100;
        int randomSeed;
        int defaultSeed = 8062022;
        uint32_t *minArray;
	uint32_t *bubbleArray;
	uint32_t *insertArray;
	uint32_t *quickArray;
	uint32_t *mergeArray;
	int numberOfPrinted;
	bool printm = false;	
	bool printb = false;
	bool printi = false;
	bool printq = false;
	bool printM = false;
	uint32_t cases = 9;
	uint32_t options[cases];
	
	//Sets array to 0s to be used as options
	for(uint32_t i = 0; i < cases; i++)
	{
		options[i] = 0;
	}
	while((character = getopt(argc, argv, "AmbiqMp:r:n:")) != -1) //while there is command line input, set certain elements of options array to 1
	{
		
		switch(character)
		{
			case 'r':
			{
				options[0] = 1;
				randomSeed = atoi(optarg);
				break;
			}
			case 'n':
                        {
				options[1] = 1;
				arraySize = atoi(optarg);
				set = true;
                        	break;
                        }
			case 'm':
                        {
				options[2] = 1;
                	        break;
                        }
			case 'b':
			{
				options[3] = 1;
				break;
			}
			case 'i':
			{
				options[4] = 1;
				break;
			}
			case 'q':
			{
				options[5] = 1;
				break;
			}
			case 'M':
			{
				options[6] = 1;
				break;
			}
			case 'A':
			{
				options[2] = 1;
				options[3] = 1;
				options[4] = 1;
				options[5] = 1;
				options[6] = 1;
				break;
			}
			case 'p':
			{
				options[8] = 1;
				numberOfPrinted = atoi(optarg);
				break;
			}
			{
			default:
				break;	
			}
		}
	}
	for(uint32_t i = 0; i < cases; i++) //Loops to check all cases
	{
		if(options[i] == 1 && i == 0)
		{
                        srand(randomSeed);
		}
		else if(options[i] == 0 && i == 0)
		{
			srand(defaultSeed);
		}
   		else if(options[i] == 1 && i == 1)
		{
			set = true;
			minArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			bubbleArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			insertArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			quickArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			mergeArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			for(int i = 0; i < arraySize; i++) //sets all arrays to have same elements
			{
				mergeArray[i] = quickArray[i] = insertArray[i] = bubbleArray[i] = minArray[i] = (rand() & MASK);
			}
		}
	
		else if(options[i] == 0  &&  i == 1)
		{
			minArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			bubbleArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			insertArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			quickArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			mergeArray = (uint32_t*)calloc(arraySize, sizeof(uint32_t));
			for(int i = 0; i < arraySize; i++)
			{
			   	mergeArray[i] = quickArray[i] = insertArray[i] = bubbleArray[i] = minArray[i] = (rand() & MASK);
				
			}
		}
		else if(options[i] == 1 && i == 2 && set == false) //logic decides what to sort and whether or not to print
		{
			printm = true;
			minSort(minArray, arraySize);
		}
		else if(options[i] == 1 && i == 2 && set == true)
		{
			printm = true;
			minSort(minArray, arraySize);
		}
		else if(options[i] == 1 && i == 3 && set == false)
                {
			printb = true;
                        bubbleSort(bubbleArray, arraySize);
                }
                else if(options[i] == 1 && i == 3 && set == true)
                {
			printb = true;
                        bubbleSort(bubbleArray, arraySize);
              	}
		else if(options[i] == 1 && i == 4 && set == false)
                {
                        printi = true;
                        insertionSort(insertArray, arraySize);
                }
                else if(options[i] == 1 && i == 4 && set == true)
                {
                        printi = true;
                        insertionSort(insertArray, arraySize);
                }
		else if(options[i] == 1 && i == 5 && set == false)
                {
                        printq = true;
                        quickSort(quickArray, 0, arraySize);
              	}
                else if(options[i] == 1 && i == 5 && set == true)
                {
                        printq = true;
                        quickSort(quickArray, 0, arraySize);
                }
		else if(options[i] == 1 && i == 6 && set == false)
                {
                        printM = true;
                        mergeSort(mergeArray, arraySize);
                }
                else if(options[i] == 1 && i == 6 && set == true)
                {
                        printM = true;
                        mergeSort(mergeArray, arraySize);
                }
		 else if(options[i] == 1 && i == 7) //Printing Logic
                {
                        if(arraySize < numberOfPrinted)
                        {
                                numberOfPrinted = arraySize;
                        }
                        if(printm)
                        {
                                printf("Min Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,minMoves,minCompares);
                                for(int i = 0; i < numberOfPrinted; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                printf("%10d",minArray[i]);
                                }
                                printf("\n");
                        }
                        if(printb)
                        {
                                printf("Bubble Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,bubbleMoves,bubbleCompares);
                                for(int i = 0; i < numberOfPrinted; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                printf("%10d",bubbleArray[i]);

                                }
                                printf("\n");

                        }
			if(printi)
                        {
                                printf("Insertion Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,insertionMoves,insertionCompares);
                                for(int i = 0; i < numberOfPrinted; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                printf("%10d",insertArray[i]);

                                }
                                printf("\n");

                        }
			if(printq)
                        {
                                printf("Quick Sort\n");
                                printf("%d elements\n%d moves\n%d compares\n", arraySize,quickMoves,quickCompares);
                                for(int i = 0; i < numberOfPrinted; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                printf("%10d",quickArray[i+1]);

                                }
                                printf("\n");

                        }
			if(printM)
                        {
                                printf("Merge Sort\n");
                                printf("%d elements\n%d moves\n%d compares\n", arraySize,mergeMoves,mergeCompares);
                                for(int i = 0; i < numberOfPrinted; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                printf("%10d",mergeArray[i]);

                                }
                                printf("\n");

                        }
                }
                else if(options[i] == 0 && i == 7)
                {
                        if(printm)
                        {
                                printf("Min Sort\n");
                                printf("%d elements\n%d moves\n%d compares\n", arraySize,minMoves,minCompares);
                                for(int i = 0; i < arraySize; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                        printf("%10d",minArray[i]);
                                }
                                printf("\n");
 			}
                        if(printb)
                        {
                                printf("Bubble Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,bubbleMoves,bubbleCompares);
                                for(int i = 0; i < arraySize; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                        printf("%10d",bubbleArray[i]);
                                }
                                printf("\n");
                        }
			if(printi)
                        {
                                printf("Insertion Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,insertionMoves,insertionCompares);
                                for(int i = 0; i < arraySize; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                        printf("%10d",insertArray[i]);
                                }
                                printf("\n");
                        }
			if(printq)
                        {
                                printf("Quick Sort\n");
                                printf("%d elements\n%d moves\n%d compares\n", arraySize,quickMoves,quickCompares);
                                for(int i = 0; i < arraySize; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                   	printf("%10d",quickArray[i+1]);	
                                }
                                printf("\n");
                        }
			if(printM)
                        {
                                printf("Merge Sort\n");
                                printf("%d elements\n%d moves\n%d compares", arraySize,mergeMoves,mergeCompares);
                                for(int i = 0; i < arraySize; i++)
                                {
                                        if(i % 7 == 0)
                                        {
                                                printf("\n");
                                        }
                                        printf("%10d",mergeArray[i]);
                                }
                                printf("\n");
                        }
                } 	
	}
	//free all allocated memory
	free(minArray);
	free(bubbleArray);
	free(insertArray);
	free(quickArray);
	free(mergeArray);
	minArray = NULL;
	bubbleArray = NULL;
	insertArray = NULL;
	quickArray = NULL;
	mergeArray = NULL;	
	return 0;
}


