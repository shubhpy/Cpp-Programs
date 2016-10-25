#include<iostream>

using namespace std;
/*

This structure contains a value ‘val’ and a pointer to a structure of same type.
The value ‘val’ can be any value (depending upon the data that the linked list is holding)
while the pointer ‘next’ contains the address of next block of this linked list.
So linked list traversal is made possible through these ‘next’ pointers that contain address of the next node.
*/

struct node{
    int data;
    struct node *next;

};

// This function prints contents of linked list starting from
// the given node
void printList(struct node *n)
{
  while (n != NULL)
  {
     cout << n->data << " ";
     n = n->next;
  }
  cout << "\n";
}

void InsertNth(struct node** headRef,int position,int newdata){

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = newdata;

    struct node* temp = *headRef;

    if (position==0){
        p->next = *headRef;
        *headRef = p;
        return;
        }

    int count = 1;
    while (count!=position){
            count++;
            temp = temp->next;
            }
    p->next = temp->next;
    temp->next = p;
    }

int main()
{
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  //cout << head->data << " " << head->next << "\n";

  // allocate 3 nodes in the heap
  head  = (struct node*)malloc(sizeof(struct node));

  struct node* last = head;
  last->next = head;

  /*
  The pointer ‘head’ now contains address of a newly created node.
  If the linked list is empty and first node is created then it is also known as head node.
  */
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));

  head->data = 1; //assign data in first node
  head->next = second; // Link first node with second

  second->data = 2; //assign data to second node
  second->next = third;

  third->data = 3; //assign data to third node
  third->next = NULL;

  printList(head);
  InsertNth(&head, 0, 13);
  printList(head);
  InsertNth(&head, 1, 42);
  printList(head);
  InsertNth(&head, 1, 5);

    printList(head);

  free(head);
  free(second);
  free(third);

  return 0;
}

