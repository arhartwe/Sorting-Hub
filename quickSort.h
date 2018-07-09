# ifndef QUICKSORT_H_
# define QUICKSORT_H_
# include <stdint.h>

extern int quickMoves;
extern int quickCompares;

void quickSort(uint32_t a[], int left, int right);

int partition(uint32_t a[], int left, int right);

# endif
