#include<stdio.h>
#include<stdlib.h>

#define N 500

typedef struct treeNode {
	int data;
	struct treeNode *left,*right;
}TNode;

typedef struct queue {
	int front,rear,size;
	unsigned capacity;
	TNode **array;
}Queue;

Queue *createQueue(unsigned capacity) {
	Queue *queue = (Queue *) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (TNode **) malloc(sizeof(TNode *) * queue->capacity);
	return queue;
}

int isFull(Queue *queue) {
	return queue->size == queue->capacity;
}

int isEmpty(Queue *queue) {
	return queue->size == 0;
}

void enqueue(Queue *queue, TNode *tNode) {
	if(isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = tNode;
	queue->size++;
//	printf("TNode enqueued to the queue.\n");
}

TNode *dequeue(Queue *queue) {
	if(isEmpty(queue)) {
	//	printf("Queue is empty.\n");
		return NULL;
	}
	TNode *item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}


TNode *createTreeNode(int data) {
	TNode *node = (TNode *) malloc(sizeof(TNode));
	if(node == NULL)
		return NULL;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void printLevelOrder(TNode *root) {
	Queue *queue = createQueue(N);
	TNode *node = root;

	while(node) {
		printf("%d ",node->data);
		if(node->left)
			enqueue(queue,node->left);
		if(node->right)
			enqueue(queue,node->right);
		node = dequeue(queue);
	}
	printf("\n");
}

int main() {
	TNode *root = createTreeNode(1);
	root->left = createTreeNode(2);
	root->right = createTreeNode(3);
	root->left->left = createTreeNode(4);
	root->left->right = createTreeNode(5);

	printLevelOrder(root);

	return 0;
}
