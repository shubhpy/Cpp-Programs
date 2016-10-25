#include<iostream>

using namespace std;

struct node* mergeList (struct node* a,struct node* b);

struct node{
    int data;
    struct node *next;
};


void push(struct node **head,int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void append(struct node **head,int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    struct node* last = *head;

    while(last->next!=NULL){
        last=last->next;
        }
    last->next = new_node;
    new_node->next = NULL;
}

void printList(struct node *n){
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << " \n";
}

void partition(struct node* head,struct node **front,struct node **back){
    struct node* fast;
    struct node* slow;

    if (head==NULL || head->next==NULL){
        return;
        }
    else{
        slow  = head;
        fast = slow->next;

        while(fast!=NULL){
            fast = fast->next;
            if (fast!=NULL){
                fast = fast->next;
                slow = slow->next;
                }
            }
        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }
}

void mergesort(struct node** source){
    struct node* head = *source;
    struct node* a = NULL;
    struct node* b= NULL;

    if (head==NULL || head->next==NULL){
        return;
        }
    partition(head,&a,&b);

    mergesort(&a);
    mergesort(&b);

    *source = mergeList(a,b);
    }

struct node* mergeList (struct node* a,struct node* b){
    struct node* merge = NULL;

    if(a==NULL){
        return b;
        }
    else if(b==NULL){
        return a;
        }

    if (a->data <= b->data){
            merge = a;
            merge->next = mergeList(a->next,b);
        }
    else{
        merge = b;
        merge->next = mergeList(a,b->next);
    }

    return merge;
}


int main(){
    struct node* head = NULL;

    push(&head,2);
    append(&head,5);
    append(&head,3);
    append(&head,7);
    append(&head,4);
    push(&head,14);

    printList(head);

    mergesort(&head);

    printList(head);

    return 0;
}
