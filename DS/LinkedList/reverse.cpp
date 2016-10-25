#include<iostream>

using namespace std;

typedef struct node* Node;
struct node{
    int data;
    Node next;
};


void push(Node *head,int new_data){
    Node new_node = (Node)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void append(Node *head,int new_data){
    Node new_node = (Node)malloc(sizeof(struct node));
    new_node->data = new_data;

    Node last = *head;

    while(last->next!=NULL){
        last=last->next;
        }
    last->next = new_node;
    new_node->next = NULL;
}

void printList(Node n){
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << " \n";
}

void reverseList(Node *head){
    Node prev = NULL;
    Node current = *head;
    Node Next;

    while(current!=NULL){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        }
    *head = prev;

}

Node reverseListInOrder(Node head,int key){
    Node prev = NULL;
    Node current = head;
    Node Next;
    int no =1;
    int k=0;

    while(current!=NULL && key>k){
            k++;
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
    if(Next!=NULL){
        head->next = reverseListInOrder(Next,key);
        }

    return prev;
        }

int main(){
    Node head = NULL;

    push(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
    append(&head,9);

    printList(head);

    head  = reverseListInOrder(head,3);

    printList(head);

    return 0;
}


