CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g -std=c99 
OBJECTS = sorting.o minSort.o bubbleSort.o insertionSort.o quickSort.o mergeSort.o

.PHONY: all
all: sorting

sorting: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(CFLAGS) -o sorting

sorting.o: sorting.c
	$(CC) $(CFLAGS) -c sorting.c

minSort.o: minSort.c
	$(CC) $(CFLAGS) -c minSort.c

bubbleSort.o: bubbleSort.c
	$(CC) $(CFLAGS) -c bubbleSort.c

insertionSort.o: insertionSort.c
	$(CC) $(CFLAGS) -c insertionSort.c

quickSort.o: quickSort.c
	$(CC) $(CFLAGS) -c quickSort.c

mergeSort.o: mergeSort.c
	$(CC) $(CFLAGS) -c mergeSort.c

.PHONY: clean
clean:
	rm -f $(OBJECTS) sorting 
