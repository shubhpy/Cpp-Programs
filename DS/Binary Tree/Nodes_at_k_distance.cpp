#include<iostream>
#include<vector>
#include <limits.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct Queue{
    int read,write,size;
    unsigned capacity;
    struct node** array;
    };


struct Queue* createQueue(unsigned capacity){
    struct Queue * queue = (struct Queue*)malloc(sizeof(struct Queue*));
    queue->capacity =  capacity;
    queue->read = queue->size = 0;
    queue->write = capacity-1;
    queue->array = (struct node**)malloc(queue->capacity * sizeof(struct node*));
    return queue;
    };

int isFull(struct Queue* queue){
    return (queue->size==queue->capacity);
    }


int isEmpty(struct Queue* queue){
    return (queue->size==0);
    }

void enqueue(struct Queue * queue,struct node* item){
    if (isFull(queue)){
        return;
    }
    queue->write = (queue->write + 1)%queue->capacity;
    queue->array[queue->write] = item;
    queue->size = queue->size + 1;
    }

struct node* dequeue(struct Queue* queue){
    if (isEmpty(queue)){
        return NULL;
    }
    struct node* item = queue->array[queue->read];
    queue->read = (queue->read + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
    }

struct node* newNode(int data){
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void print_nodes_k_distance(struct node* root,int k){
    if (root==NULL){
        return ;
    }
    else if (k==0){
        cout << root->data << " ";
    }
    else{
        print_nodes_k_distance(root->left,k-1);
        print_nodes_k_distance(root->right,k-1);
    }
}

int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);

  print_nodes_k_distance(root, 2);


  return 0;
}
