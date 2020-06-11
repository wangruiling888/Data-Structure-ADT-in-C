# include "maxHeap.h"

int main(){
	int a[] = {1,2,8,7,6};
	Heap* hp = newHeap();
	for (int i = 0; i < 5; i++){
		insert_heap(a[i], hp);
	}
	for (int i = 0; i < 5; i++){
		delete_heap(hp);
	}
	
}
