# include <stdint.h> 
# include "mergeSort.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

int mergeMoves;
int mergeCompares;

//CODE FROM mycodeschool

void merge(uint32_t a[], uint32_t *left,int leftSize, uint32_t *right, int rightSize)
{
	//indexes
        int i = 0;
        int j = 0;
        int k = 0;
	mergeCompares+=3;
        while(i < leftSize && j < rightSize) //compare value of left subarray and right subarray
        {
                if(left[i] < right[j]) //fill original array with smaller element
                {
                        a[k] = left[i];
                        i++;
			k++;
			mergeMoves++;
                }
                else
                {
                        a[k] = right[j];
                        j++;
			k++;
			mergeMoves++;
                }
                
        }
        while(i < leftSize) //while there are leftovers in left subarray, fill in the rest of the original array
        {
                a[k] = left[i];
                i++;
                k++;
		mergeMoves++;	
        }
	while(j < rightSize) //while there are leftovers in right subarray, fill in rest of original array
        {
                a[k] = right[j];
                k++;
                j++;
		mergeMoves++;
        }
}

void mergeSort(uint32_t a[], int length)
{
        if(length < 2)
        {  
		return;
	}
	else
	{
		int middle = length / 2;     
		uint32_t *left;
        	uint32_t *right;
		int i;
		left = (uint32_t*)malloc(middle*sizeof(int)); //creates sub arrays
		right = (uint32_t*)malloc((length-middle)*sizeof(int));
       		for(i = 0; i < middle; i++)
        	{
			mergeMoves++;
                	left[i] = a[i]; //fills left subarray with half of original array values
        	}
        	for(i = middle; i < length; i++)
        	{        
			mergeMoves++;
			right[i-middle] = a[i]; //fills right subarray with other half of original values
        	}
                mergeSort(left, middle); //continue subarray process recursively
		mergeSort(right, length - middle);
                merge(a,left,middle,right,length - middle);
		free(left);
		free(right);
        }
	return;
}
