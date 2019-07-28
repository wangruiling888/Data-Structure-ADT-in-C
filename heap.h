// heap: based on array
typedef struct max_heap *Heap;

//create the heap with the root value
Heap create_heap(int);

//fixup heap
void fixup(Heap);

//insert the value to the heap
void insert_heap(int,Heap);

//fixdown heap
void fixdown(int, Heap);

//delete specific value from heap
void delete_heap(int, Heap);

//get maximum(root) from heap
int get_root(Heap);

// print heap as array
void show_heap(Heap);



