# include <stdint.h>
# include "quickSort.h"
# include <stdio.h>

// PSEUDOCODE FROM geeksforgeeks.com
# ifdef _INSTRUMENTED
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ; moveCount += 3;}
# else
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ;}
# endif

int quickMoves;
int quickCompares;

int partition(uint32_t a[], int start, int end)
{
	uint32_t pivot = a[end]; //pivot, or last element of array 
	int farLeft = (start - 1); //wall being compared to
	quickCompares++;
        for(int i = start; i <= (end - 1); i++) //compare up to pivot
        {
		quickCompares++;
                if(a[i] <= pivot) //if current element is less than or equal to pivot, swap wall and current element
                {
			farLeft++;
                        SWAP(a[farLeft], a[i]);
			quickMoves+=3;
                }
        }
        SWAP(a[farLeft + 1], a[end]); //Place pivot. 
	quickMoves+=3; 
        return (farLeft + 1); //move wall
}

void quickSort(uint32_t a[], int start, int end)
{
	quickCompares++;
	if(start < end)
	{	
		quickCompares++;	
		int pivot = partition(a,start,end);
		quickSort(a,start,pivot - 1);	
		quickSort(a,pivot + 1, end);
	}
	return;
}


