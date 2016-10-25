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

struct node* insert(struct node* root,int data){
    if (root==NULL){
        return newNode(data);
    }

    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
    }

int size_of_tree(struct node* root){
    if (root==NULL){
        return 0;
    }
    return 1+size_of_tree(root->left)+size_of_tree(root->right);
    }

int maxDepth(struct node* root){
    if (root==NULL){
        return 0;
    }
    else{
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    }

int minValue(struct node* root){
    if (root==NULL){
        return 0;
        }
    else if (root->left==NULL){
            return root->data;
        }
    else{
        return minValue(root->left);
        }
}

void print_Inorder(struct node* root){
    if (root==NULL){
            return;
    }
    print_Inorder(root->left);
    cout << root->data << " ";
    print_Inorder(root->right);
}

void print_Postorder(struct node* root){
    if (root==NULL){
            return;
    }
    print_Postorder(root->left);
    print_Postorder(root->right);
    cout << root->data << " ";
}

void print_Preorder(struct node* root){
    if (root==NULL){
            return;
    }
    cout << root->data << " ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}

bool binarysearch(struct node*root,int item){
    if (root==NULL){
            return false;
    }
    else if(root->data==item){
        return true;
    }
    else if(root->data >= item){
        return binarysearch(root->left,item);
    }
    else{
        return binarysearch(root->right,item);
    }
}

int hasPathSum(struct node* root,int sum){
    if (root==NULL){
        return(sum==0);
    }
    return (hasPathSum(root->left,sum- root->data) || hasPathSum(root->right,sum - root->data));
}

void printPathRecur(struct node* root,vector<int>& pathVector,int pathlen){
    if (root==NULL){
        return;
    }
    pathVector[pathlen]=root->data;
    pathlen++;

    if (root->left==NULL && root->right==NULL){
        for(int i=0;i<pathlen;i++){
            cout << pathVector[i] << " ";
        }
        cout << "\n";
    }

    printPathRecur(root->left,pathVector,pathlen);
    printPathRecur(root->right,pathVector,pathlen);

}

void print_Paths(struct node* root){
    vector<int> pathVector(1000);

    printPathRecur(root,pathVector,0);

    cout << "\n";
}

void mirror(struct node* root){
    if (root==NULL){
        return ;
    }

    struct node* temp ;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

}

void printLevelOrderBFS(struct node* root){
    if (root==NULL){
        return;
    }

    struct Queue* q = createQueue(100);
    enqueue(q,root);

    while(!isEmpty(q)){
        struct node * NODE = dequeue(q);
        cout << NODE->data << " ";
        if (NODE->left !=NULL){
            enqueue(q,NODE->left);
        }
        if (NODE->right !=NULL){
            enqueue(q,NODE->right);
        }
    }
}

int diameter(struct node* root){
    if (!root){
        return 0;
    }
    return 1+diameter(root->left)+diameter(root->right);
    }

int main()
{
  /*create root*/
  struct node *root = newNode(10);
  root = insert(root,6);
  root = insert(root,11);
  root = insert(root,5);
root = insert(root,8);
  root = insert(root,7);
  root = insert(root,9);
  root = insert(root,12);
root = insert(root,16);
  root = insert(root,14);
  root = insert(root,13);
  root = insert(root,15);
root = insert(root,17);

/*  //root = insert(root,5);

  //cout << root->data<< "\n";
  //cout << root->left->data<< "\n";
  //cout << root->right->data<< "\n";

  cout << size_of_tree(root)<< "\n";

  cout << maxDepth(root)<< "\n";

  cout << minValue(root) << "\n";
  print_Inorder(root);
  cout << "\n";

  print_Postorder(root);
  cout << "\n";

  print_Preorder(root);
  cout << "\n";

  //cout << binarysearch(root,7) << "\n";

  cout << hasPathSum(root,7) << "\n\n\n";

  print_Paths(root);



  print_Paths(root);

*/
    //mirror(root);
  //cout <<"\n\n\n\n";

  printLevelOrderBFS(root);


  cout <<"\n"<< diameter(root);

  return 0;
}
