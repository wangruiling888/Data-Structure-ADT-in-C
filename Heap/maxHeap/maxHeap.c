# include "maxHeap.h"

// use array to store element in heap
struct Heap{
	int array[heap_num];	
	int height; // number of element in heap
}; 
// create a new null heap
Heap* newHeap(){
	Heap *hp;
	// 1 create memory
	hp = malloc(sizeof(struct Heap));
	if (hp == NULL) return NULL;
	// 2 initilize number of element to 0
	hp -> height = 0;
	return hp;
}
// used for delete heap
void fixdown(Heap *hp){
	int index = 0;
	int index_child = 1;
	while (index_child <= hp -> height){
		int max = 0;
		int max_index = 0;
		// get index of max(left_node ,right_node)
		if (index_child + 1 <=  hp->height){
			max = hp->array[index_child] > hp->array[index_child +1] ? hp->array[index_child]:hp->array[index_child +1];
			max_index = hp->array[index_child] > hp->array[index_child +1]?index_child:(index_child +1);
		}
		else{// only child node
			max = hp->array[index_child];
			max_index = index_child;
		}
		// compare and swap
		if(hp->array[index] < max ){ 
			int wrap = hp->array[index];
			hp -> array[index] = max;
			hp -> array[max_index] = wrap;
			index = max_index;
			index_child = max_index *2 + 1;
		}
		else{
			break;
		}	
	}
}
// used for insert heap
void fixup(Heap *hp){
	// get index of new element in array
	int index_child = hp->height;
	// parent index and val
	int index_par = (hp->height - 1)/2;
	// compare & swap
	while (index_par >= 0){
		// get val of new element
		int child = hp -> array[index_child];
		// compare it with its parent
		if (child  > hp -> array[index_par] ){
			// swap it with its parent
			int swap = hp -> array[index_par];
			hp -> array[index_par] = child;
			hp -> array[index_child] = swap;
			// go to next iteration, index of new element = parent index
			index_child = index_par;
			// get new parent node of new element
			index_par = (index_par - 1) /2;
		}
		else break;
	}
	return ;
}

void insert_heap(int n, Heap *hp){
	// 0
	hp -> array[hp -> height]  = n ;
	// 向上构建
	fixup(hp);
	// create height by 1
	hp -> height ++;
	printf("insert %d to heap\n", n);
	return;
}
int delete_heap(Heap *hp){
	int pop = hp -> array [0];
	hp -> array [0] = hp -> array[hp ->height-1];
	hp -> height --;
	fixdown(hp);
	printf("pop %d\n", pop);
	return pop;
}


int heapIsEmpty(Heap *hp){
	if (hp -> height > 0) return 1;
	return 0;
}
int getHeight(Heap* hp){
    return hp -> height;
}


