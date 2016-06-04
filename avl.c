#include <stddef.h>
#include <stdbool.h>
#include "queue.h"

struct node {
	int data;
	struct node* left;
	struct node* right;
	int unorder; // this is used for balancing
	struct node* parent;
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

void levelOrderTraversal(struct queue * queue) {
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
	levelOrderTraversal(queue);
	//printf("\nLOT\n%d", ((struct node *)(queue->begin->data))->data);

}

void print(struct node *root) {
	if (root != NULL) {
		print(root->left);
		printf("%d ", root->data);
		print(root->right);
	}
}
/*
void cloneNode(struct node *dstNode, struct node *srcNode) {
	dstNode->
}*/

void leftRotation(struct node **root, struct node *node) {
	struct node *rightChild = node->right;
	struct node *parent = node->parent;
	rightChild->left = node;
	node->parent = rightChild;
	node->right = NULL;

	if (parent == NULL) {
		rightChild->parent = NULL;
		*root = rightChild;
	} else {
		rightChild->parent = parent;
		if (node == parent->right) {
			parent->right = rightChild;
		} else if (node == parent->left) {
			parent->left = rightChild;
		} else {
			printf("Problem in rotation");
		}
	}
}

void rightRotation(struct node **root, struct node *node) {
	struct node *leftChild = node->left;
	struct node *parent = node->parent;
	leftChild->right = node;
	node->parent = leftChild;
	node->left = NULL;

	if (parent == NULL) {
		leftChild->parent = NULL;
		*root = leftChild;
	} else {
		leftChild->parent = parent;
		if (node == parent->right) {
			parent->right = leftChild;
		} else if (node == parent->left) {
			parent->left = leftChild;
		} else {
			printf("Problem in rotation");
		}
	}
}

bool
unorderCheck(struct queue *queue, struct node **root) {
	struct node *node = NULL;
	bool isBalanced = true;
	while (queue->begin != NULL && queue->end != NULL) {
		node = (struct node *) dequeue(queue);
		if (node->unorder < -1 || node->unorder > 1) {
			*root = node;
			isBalanced = false;
		}

		if (node->left != NULL) {
			enqueue(queue, node->left);
		}

		if (node->right != NULL) {
			enqueue(queue, node->right);
		}
	}

	return isBalanced;
}

void setUnorder(struct node *root) {
	if (root != NULL) {
		int leftHeight = 0;
		int rightHeight = 0;
		if (root->left != NULL) {
			leftHeight = getHeight(root->left) + 1;
		}

		if (root->right != NULL) {
			rightHeight = getHeight(root->right) + 1;
		}

		root->unorder = rightHeight - leftHeight;

		if (leftHeight > 0) {
			setUnorder(root->left);
		} 
		
		if (rightHeight > 0) {
			setUnorder(root->right);	
		}
	}
}

void
__balanceTree(struct node **root, struct node *unBalancedNode) {
	if (unBalancedNode->unorder > 0) { // Right side is heavier so either '\' or '>'
		if (unBalancedNode->right->right != NULL) {
			leftRotation(root, unBalancedNode);
		} else {
			rightRotation(root, unBalancedNode->right);
			leftRotation(root, unBalancedNode);
		}
	} else { // Left side is heavier, so either '/' or '<'
		if (unBalancedNode->left->left != NULL) {
			rightRotation(root, unBalancedNode);
		} else {
			leftRotation(root, unBalancedNode->left);
			rightRotation(root, unBalancedNode);
		}
	}
}

void _balanceTree (struct node **root) {
	bool isBalanced = false;
	while (!isBalanced) {
		struct queue *queue = createQueue();
		enqueue(queue, *root);

		struct node *unBalancedNode = NULL;
		isBalanced = unorderCheck(queue, &unBalancedNode);
		if (!isBalanced) {
			printf("Balancing at node %d\n", unBalancedNode->data);
			__balanceTree(root, unBalancedNode);
			setUnorder(*root);
		}
	}
}

void _insert (struct node **root, int data, struct node *parent) {
	if (*root == NULL) {
		struct node *temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		temp->unorder = 0;
		temp->parent = parent;
		*root = temp;

	} else {
		if (data < (*root)->data) {
			(*root)->unorder--;
			_insert(&((*root)->left), data, *root);
		} else {
			(*root)->unorder++;
			_insert(&((*root)->right), data, *root);
		}
	}

}

void insert (struct node **root, int data) {
	printf("Inserting %d...\n", data);
	_insert(root, data, NULL);
	_balanceTree(root);
}


void main() {
	printf("BST\n");
	struct node *root = NULL;/*
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 7);
	insert(&root, 4);
	insert(&root, 1);
	insert(&root, 9);
	insert(&root, 2);
	insert(&root, 12);
	insert(&root, 3);*/

	insert(&root, 10);
	insert(&root, 5);
	insert(&root, 2);
	insert(&root, 4);
	insert(&root, 3);
	//print(root);
	printLevelOrder(root);

	//printf("Height %d", getHeight(root));
}