// C program for array implementation of queue
#include <iostream>
#include <limits.h>

using namespace std;

// A structure to represent a queue
struct Queue
{
    int read, write, size;
    unsigned capacity;
    int* array;
};

// function to create a queue of given capacity. It initializes size of
// queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->read = queue->size = 0;
    queue->write = capacity - 1;  // To make Circular Array This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

// Function to add an item to the queue.  It changes write and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->write = (queue->write + 1)%queue->capacity; //Circular Array
    queue->array[queue->write] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.  It changes read and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->read];
    queue->read = (queue->read + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get read of queue
int read(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->read];
}

// Function to get write of queue
int write(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->write];
}

// Driver program to test above functions./
int main()
{
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << " dequeued from queue\n";

    cout << "read item is " << read(queue) << "\n";
    cout << "write item is " << write(queue) << "\n";

    return 0;
}
