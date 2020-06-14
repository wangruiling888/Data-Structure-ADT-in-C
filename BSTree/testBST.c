// test case for BST
# include "BST.h"

int main(){
	TreeNode root = newNode(2);
	int a[7] = {1,5,6,4,3};
	for (int i = 0; i < 5; i ++){
			InsertNode(root, a[i]);
	}
	DeleteNode(root, 2);
	SearchNode(root,5);
	ShowPostOrder(root);
	DestroyTree(root);
	ShowPostOrder(root);
	return 0;
}
