# include <stdio.h>
# include <stdlib.h>
# include "heap.h"

int main(){
	// create heap
	Heap hp = create_heap(58);
	// get root
	int root = get_root(hp);
	printf("root of hp is: %d\n", root);
	// insert value 38 
	insert_heap(38,hp);
	// show heap
	show_heap(hp);
	// insert value 65 
	insert_heap(65,hp);
	// show heap
	show_heap(hp);
	// insert value 78
	insert_heap(78,hp);
	// show heap
	show_heap(hp);
	// insert value 70
	insert_heap(70,hp);
	// show heap
	show_heap(hp);
	
	// delete 70 from heap
	delete_heap(70, hp);
	// show heap
	show_heap(hp);
	
	// delete 70 from heap
	delete_heap(78, hp);
	// show heap
	show_heap(hp);
	
	return 0;
}