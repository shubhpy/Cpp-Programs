#include<iostream>
#include<vector>
#include <limits.h>
#include<stack>

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

void print_Reverse_LevelOrderBFS(struct node* root){
    if (root==NULL){
        return;
    }

    struct Queue* q = createQueue(100);
    stack<int> st;
    enqueue(q,root);
    while(!isEmpty(q)){
        struct node * NODE = dequeue(q);
        st.push(NODE->data);
        if (NODE->right !=NULL){
            enqueue(q,NODE->right);
        }
        if (NODE->left !=NULL){
            enqueue(q,NODE->left);
        }
    }

    while(!st.empty()){
        int ans = st.top();
        st.pop();
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
  struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	print_Reverse_LevelOrderBFS(root);
    return 0;
}
