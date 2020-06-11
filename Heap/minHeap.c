# include "minHeap.h"
struct Heap{
	int array[heap_num];	
	int height;
}; 

Heap* newHeap(){
	Heap *hp;
	hp = malloc(sizeof(struct Heap));
	if (hp == NULL) return NULL;
	hp -> height = 0;
	return hp;
}
void fixdown(Heap *hp){
	int index = 0;
	int index_child = 1;
	while (index_child <= hp -> height){
		int min = 0;
		int min_index = 0;
		if (index_child + 1 <=  hp->height){
			min = hp->array[index_child] < hp->array[index_child +1] ? hp->array[index_child]:hp->array[index_child +1];
			min_index = hp->array[index_child] < hp->array[index_child +1]?index_child:(index_child +1);
		}
		else{
			min = hp->array[index_child];
			min_index = index_child;
		}
		if(hp->array[index] > min ){ 
			int wrap = hp->array[index];
			hp -> array[index] = min;
			hp -> array[min_index] = wrap;
			index = min_index;
			index_child = min_index *2 + 1;
		}
		else{
			break;
		}	
	}
}
void fixup(Heap *hp){
	int index_child = hp->height;
	int index_par = (hp->height - 1)/2;
	while (index_par >= 0){
		int child = hp -> array[index_child];
		if (child  < hp -> array[index_par] ){
			int swap = hp -> array[index_par];
			hp -> array[index_par] = child;
			hp -> array[index_child] = swap;
			index_child = index_par;
			index_par = (index_par - 1) /2;
		}
		else break;
	}
	return ;
}
void insert_heap(int n, Heap *hp){
	hp -> array[hp -> height]  = n ;
	fixup(hp);
	hp -> height ++;
	printf("insert %d to heap\n", n);
	return ;
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

