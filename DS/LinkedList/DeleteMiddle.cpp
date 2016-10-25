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

struct node* deleteMiddle(struct node *head){
    struct node * slow = head;
    struct node * fast = head;
    struct node * p = NULL;

    if (fast->next==NULL){
        return NULL;
        }

    while(fast->next!=NULL){
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (fast==NULL){
            break;
            }
        }

    p->next = slow->next;
    return head;

    }

int main()
{

  int T,n,num;
  cin >> T;
  for (int i=0;i<T;i++){
    cin >> n;
    struct node* head = NULL;
    for(int j=0;j<n;j++){
        cin >> num;
        InsertNth(&head, j,num);
        }
    printList(deleteMiddle(head));
    free(head);
    }

  return 0;
}


