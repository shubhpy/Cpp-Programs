#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void swap_two(struct node **head,int key1,int key2){
    if(key1 == key2) return;

    struct node* p1 = *head;
    struct node* q1 = NULL;
    while(p1!=NULL && p1->data!=key1){
        q1=p1;
        p1 = p1->next;
    }

    struct node* p2 = *head;
    struct node* q2 = NULL;

    while(p2!=NULL && p2->data!=key2){
        q2=p2;
        p2 = p2->next;
    }

    if (p1 == NULL || p2 == NULL)
       return;

    if (q1 != NULL)
       q1->next = p2;
   else // Else make y as new head
       *head = p2;

   // If y is not head of linked list
   if (q2 != NULL)
       q2->next = p1;
   else  // Else make x as new head
       *head = p1;

   // Swap next pointers
   struct node *temp = p2->next;
   p2->next = p1->next;
   p1->next = temp;

}

void push(struct node **head,int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(struct node *n){
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << " \n";
}

int main(){
    struct node* head = NULL;

    push(&head,14);
    push(&head,20);
    push(&head,13);
    push(&head,12);
    push(&head,15);

    printList(head);

    swap_two(&head,12,14);

    printList(head);

    return 0;
}

