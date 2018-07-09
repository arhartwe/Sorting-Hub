# include <stdint.h>
# include "insertionSort.h"
# include <stdbool.h>

int insertionMoves;
int insertionCompares;

void insertionSort(uint32_t a[], uint32_t length)	
{
	uint32_t tmp;
	int j;
	for(uint32_t i = 0; i < length; i++)
	{
		tmp = a[i];
		j = i - 1;	
		while(j >= 0 && a[j] > tmp) //is the element before greater than the current?
		{
			a[j+1] = a[j]; //if yes, shift element forward
			j = j - 1;
			insertionMoves++;
			insertionCompares++;
		}
		a[j+1] = tmp; //insert element
		insertionMoves++;
	}
	return;
}
