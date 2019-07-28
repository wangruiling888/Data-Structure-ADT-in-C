# include <stdio.h>
# include <stdlib.h>
# include "heap.h"

# define heap_num  1000

struct max_heap{
	int array[heap_num];	
	int height;
};

Heap create_heap(int value){
	// a pointer
	Heap hp;
	hp = malloc(sizeof(struct max_heap));
	if (hp == NULL){
		fprintf(stderr, "No memory allocated\n");
		exit(1);
	}
	hp -> array[0] = 0;
	hp -> array[1] = value;
	hp -> height = 1;
	printf("the heap has been created\n");
	printf("the root number is: %d\n", hp -> array[1]);
	return hp;
}

void fixup(Heap hp){
	int child = hp -> array[hp -> height];
	int index_child = hp->height;
	int index_par = hp->height/2;
	while (index_par > 0){
		if (child > hp -> array[index_par]){
			int swap = hp -> array[index_par];
			//printf("swap %d with %d\n",child, swap);
			hp -> array[index_par] = child;
			//printf("now the %d is %d\n",index_par,hp -> array[index_par] );
			hp -> array[index_child] = swap;
			//printf("now the %d is %d\n",index_child,hp -> array[hp -> height] );
			index_par = index_par/2;
			index_child = index_child/2;
			
		}
		else{
			// unnecessary to continue 
			break;
		}
	}
	return ;
}

void insert_heap(int value, Heap hp){
	if (hp == NULL){
		fprintf(stderr, "heap not initialized\n");
		exit(1);
	}
	hp -> height ++;
	hp -> array[hp ->height] = value;
	fixup(hp);
	printf("%d has been inserted\n", value);
	return ;
}

void fixdown(int index, Heap hp){
	int index_child = index *2;
	while (index_child < hp -> height){
		int max = 0;
		int max_index = 0;
		if (index_child + 1 <= hp->height){
			if (hp->array[index_child] > hp->array[index_child +1] ){
				max =hp->array[index_child];
				max_index = index_child;
			}
			else{
				max =hp->array[index_child +1];
				max_index = index_child +1;
			}
		}
		else{
			max = hp->array[index_child];
			max_index = index_child;
		}
		if(hp->array[index] < max){
			int wrap = hp->array[index];
			hp -> array[index] = max;
			hp -> array[max_index] = wrap;
			index_child = index_child *2;
		}
		else{
			break;
		}
		
	}
}

void delete_heap(int value, Heap hp){
	int index = 0;
	for (int i = 1; i <= hp->height; i++){
		if (hp -> array[i] == value){
			index = i;
			break;
		}	
	}
	hp -> array [index] = hp -> array[hp ->height];
	hp -> height --;
	fixdown(index, hp);
	printf("%d has been deleted\n", value);
	return ;
}

int get_root(Heap hp){
	return hp -> array[1];
}

void show_heap(Heap hp){
	for (int i = 1; i <= hp -> height; i++){
		printf("heap no %d is: %d\n",i, hp -> array[i]);
	}
}