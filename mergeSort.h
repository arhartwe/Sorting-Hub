# ifndef MERGESORT_H_
# define MERGESORT_H_
# include <stdint.h>

extern int mergeMoves;
extern int mergeCompares;

void mergeSort(uint32_t a[], int length);

void merge(uint32_t a[], uint32_t *left,int leftSize, uint32_t *right, int rightSize);

# endif
