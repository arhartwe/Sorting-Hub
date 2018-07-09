# include <stdint.h>
# include "minSort.h"

# ifdef _INSTRUMENTED
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ; moveCount += 3;}
# else 
# define SWAP(x,y) { uint32_t t = x; x = y; y = t; ;}
# endif

int minMoves = 0;
int minCompares = 0;

//minIndex: find the index of the least element

uint32_t minIndex(uint32_t a[], uint32_t first, uint32_t last)
{
	uint32_t smallest = first; //Assume the first is the least
	for(uint32_t i = first; i < last; i += 1)
	{
		smallest = a[i] < a[smallest] ? i : smallest;
		minCompares++;
	}
	return smallest;
}

//minSort: sort by repeatedly finding the least element

void minSort(uint32_t a[], uint32_t length)
{
	for(uint32_t i = 0; i < length - 1; i += 1)
	{
		uint32_t smallest = minIndex(a, i, length);
		if(smallest != i)
		{
			SWAP(a[smallest], a[i]);
			minMoves+=3;
		}
	}
	return;
}
