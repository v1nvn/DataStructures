#include <stddef.h>
#include "queue.h"

struct node {
	int data;
	struct node* left;
	struct node* right;
};


int getHeight2(struct node *root, int height) {
	int leftHeight = height;
	int rightHeight = height;

	if (root->left != NULL) {
		leftHeight = getHeight2(root->left, leftHeight + 1);
	}

	if (root->right != NULL) {
		rightHeight = getHeight2(root->right, rightHeight + 1);
	}  

	int foo = leftHeight > rightHeight ? leftHeight : rightHeight;
	return foo;
}

int getHeight(struct node *root) {
	int leftHeight = 0;
	int rightHeight = 0;

	if (root->left != NULL) {
		leftHeight = getHeight2(root->left, leftHeight + 1);
	}

	if (root->right != NULL) {
		rightHeight = getHeight2(root->right, rightHeight + 1);
	} 

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}

void printLOByQueue(struct queue * queue) {
	struct node *node = NULL;
	while (queue->begin != NULL && queue->end != NULL) {
		node = (struct node *) dequeue(queue);
		printf("%d ", node->data);
		if (node->left != NULL) {
			enqueue(queue, node->left);
		}

		if (node->right != NULL) {
			enqueue(queue, node->right);
		}
	}
	printf("LOT over");
}

void printLevelOrder(struct node *root) {
	struct queue *queue = createQueue();
	enqueue(queue, root->left);
	enqueue(queue, root->right);

	printf("LOT\n%d ", root->data);
	printLOByQueue(queue);
	//printf("\nLOT\n%d", ((struct node *)(queue->begin->data))->data);

}

void print(struct node *root) {
	if (root != NULL) {
		print(root->left);
		printf("%d ", root->data);
		print(root->right);
	}

}

void insert (struct node **root, int data) {
	if (*root == NULL) {
		struct node *temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	} else {
		if (data < (*root)->data) {
			insert(&((*root)->left), data);
		} else {
			insert(&((*root)->right), data);
		}
	}
}


void main() {
	printf("BST\n");
	struct node *root = NULL;
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 7);
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 9);
	insert(&root, 2);
	insert(&root, 12);
	insert(&root, 3);

	print(root);
	printLevelOrder(root);

	printf("Height %d", getHeight(root));
}