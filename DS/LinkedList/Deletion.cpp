#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void delete_key_position(struct node **head,int key_position){
    struct node* p = *head;
    struct node* q;
    int k=0;

    while(p!=NULL && k<key_position){
        k++;
        q=p;
        p = p->next;
        }
    q->next = p->next;

    free(p);
}

void delete_greater_value_in_right(struct node **head){
    struct node* q = *head;
    struct node* prev;

    while(q->next!=NULL){
        if (q->data < q->next->data){
            if (q==*head){
                *head = q->next;
                q=q->next;
            }
            else{
                prev->next = q->next;
                q = *head;
            }

        }
        else{
            prev = q;
            q = q->next;
        }
    }

    //return h;
        }

void delete_greater_than_x(struct node **head,int x){
    struct node* q = *head;
    struct node* prev;


    while(q->next!=NULL){
        if (q->data > x){
            *head = q->next;
            q = q->next;
        }
        else{
            prev=q;
            if (q->next->data > x){
                if (q->next->next!=NULL){
                    prev->next = q->next->next;
                }
                else{
                    prev->next = NULL;
                }
            }
            else{
                q = q->next;
        }
    }
    //free(q);
}
}

void delete_key_value(struct node **head,int key_value){
    struct node* p = *head;
    struct node* q;

    if (p->data == key_value){
        *head = p->next;
    }
    else{

        while(p!=NULL && p->data!=key_value){
            q=p;
            p = p->next;
            }
        q->next = p->next;
    }
    free(p);

}

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

int main(){
    struct node* head = NULL;

    push(&head,12);
    append(&head,15);
    append(&head,16);
    append(&head,17);
    append(&head,19);
    append(&head,20);
    append(&head,21);
    append(&head,22);


    printList(head);
//this is value not position
    //delete_key_value(&head,2);
    //printList(head);
//this position not value starting from 0
    //delete_key_position(&head,3);


    //delete_greater_than_x(&head,3);
    //printList(head);

    delete_greater_value_in_right(&head);
    printList(head);

    return 0;
}
