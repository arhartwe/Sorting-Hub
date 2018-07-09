# ifndef MINSORT_H_
# define MINSORT_H_
# include <stdint.h>

extern int minMoves;
extern int minCompares;

uint32_t minIndex(uint32_t a[], uint32_t first, uint32_t last);

void minSort(uint32_t a[], uint32_t length);
 
# endif
