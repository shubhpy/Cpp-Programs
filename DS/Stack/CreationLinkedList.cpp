// C++ program for linked list implementation of stack
#include <iostream>
#include <limits.h>

using namespace std;

// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    //returns 0 (Not Empty) or 1
    return !root;
}

void push(struct StackNode** root, int item)
{
    struct StackNode* stackNode = newNode(item);
    stackNode->next = *root;
    *root = stackNode;
    cout << item << " pushed to stack\n";
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    struct StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";
     cout << pop(&root) << " popped from stack\n";
    //  cout << pop(&root) << " popped from stack\n";

    cout << "Top item is  " << peek(root)<< " \n";


    cout << isEmpty(root) << "\n";

    return 0;
}
