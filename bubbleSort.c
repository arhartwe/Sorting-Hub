# include <stdint.h>
# include "bubbleSort.h"
# include <stdbool.h>

# ifdef _INSTRUMENTED
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ; moveCount += 3;}
# else
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ;}
# endif

int bubbleMoves;
int bubbleCompares;

void bubbleSort(uint32_t a[], uint32_t length)
{
	
	int n = length;
	bool swapped = true;
	do
	{ 
		swapped = false;	
		for(int i = 0; i <= n-1; i++)
		{
			
			if(a[i-1] > a[i]) //if next element is greater than current, swap and tell loop a swap occured
			{
				SWAP(a[i-1], a[i]);
				swapped = true;
				bubbleMoves +=3;
				bubbleCompares++; 
			}
		}
		
			
		
		n = n - 1;
	}
	while(swapped); //continue swapping until no swap occurs
	return;
}
		

