#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void pushFront(struct node** head,int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    //cout << head->data << "\n";
    //cout << *head <<"\n";
    //cout << &new_node <<"\n";
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
    //cout << new_node->next <<"\n";
    //cout << *head <<"\n";
}

void AddBefore(struct node *head,int node_data, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    struct node* p = head;

    while(p->next->data!=node_data){
        p = p->next;
        }
    new_node->next = p->next;
    p->next = new_node;
}

void appendLast(struct node *head,int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    struct node* last = head;

    while(last->next!=NULL){
        last=last->next;
        }
    last->next = new_node;
    new_node->next = NULL;
}

void printList(struct node *head){
    struct node* p = head;

    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << " \n";
}

int main(){
    struct node* head = NULL;

    //cout << &head <<"\n";
    pushFront(&head,2);
    //cout << &head <<"\n";

    appendLast(head,5);
    appendLast(head,3);
    appendLast(head,7);
    appendLast(head,4);
    printList(head);

    //AddBefore(&head,7,8);

    //printList(head);

    return 0;
}

