// A C++ program to demonstrate linked list based implementation of queue
#include <iostream>

using namespace std;

// A linked list (LL) node to store a queue entry
struct QNode
{
    int key;
    struct QNode *next;
};

// The queue, read stores the read node of LL and write stores ths
// last node of LL
struct Queue
{
    struct QNode *read, *write;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->read = q->write = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(struct Queue *q, int k)
{
    // Create a new LL node
    struct QNode *temp = newNode(k);

    // If queue is empty, then new node is read and write both
    if (q->write == NULL)
    {
       q->read = q->write = temp;
       return;
    }

    // Add the new node at the end of queue and change write

    q->write->next = temp;
    q->write = temp;
}

// Function to remove a key from given queue q
struct QNode *deQueue(struct Queue *q)
{
    // If queue is empty, return NULL.
    if (q->read == NULL)
       return NULL;

    // Store previous read and move read one node ahead
    struct QNode *temp = q->read;
    q->read = q->read->next;

    // If read becomes NULL, then change write also as NULL
    if (q->read == NULL)
       q->write = NULL;
    return temp;
}

// Driver Program to test anove functions
int main()
{
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct QNode *n = deQueue(q);
    if (n != NULL)
      cout << "Dequeued item is " << n->key;
    return 0;
}
