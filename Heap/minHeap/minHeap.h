# include <stdio.h>
# include <stdlib.h>
# define heap_num  1000

typedef struct Heap Heap;
Heap* newHeap();              // create new empty Heap
void fixdown(Heap*);          // helper function for top-down construction
void fixup(Heap*);            // helper funxtion for bottom-up construction
void insert_heap(int, Heap*); // insert number into heap
int delete_heap(Heap*);       // pop top number from the heap
int heapIsEmpty(Heap*);       // heap is empty or not
