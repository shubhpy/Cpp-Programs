#include<iostream>
#include<queue>

using namespace std;

struct Node{

    struct Node* left;
    struct Node* right;
    int freq;
    char c;
};

struct CompareNodes{

    bool operator()(struct Node* n1, struct Node* n2)
    {
       return n1->freq > n2->freq;
    }
};

void printCodes(struct Node *root,int *code,int top){
	if(root->left){
		code[top]=0;
		printCodes(root->left,code,top+1);
	}
	if(root->right){
		code[top]=1;
		printCodes(root->right,code,top+1);
	}
	if(root->left==NULL && root->right==NULL){
		cout<<root->c<<": ";
		for(int i=0;i<top;i++){
			cout<<code[i];
		}
		cout<<endl;
	}
}

int main(){


    char cc[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int f[] = {45, 13, 12, 16, 9, 5};
    priority_queue<struct Node*,vector<struct Node*>, CompareNodes> pq;
    for(int i=0;i<6;i++){
        //cin >> cc[i] >> f[i];
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
        temp->freq=f[i];
        temp->c=cc[i];
        temp->left=temp->right=NULL;
        pq.push(temp);
    }
/*
     for(int i=0;i<6;i++){
        struct Node* new_node = pq.top();
        cout << new_node->c << " " << new_node->freq <<" " << new_node->left <<" "<< new_node->right  << "\n";
        pq.pop();
    }
*/
    struct Node* x ;

    for(int i=0;i<6-1;i++){
        x = pq.top();
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
        temp->left = x;
        pq.pop();
        struct Node* y = pq.top();
        temp->right = y;
        pq.pop();
        temp->freq = x->freq + y->freq;
        temp->c = '0';
        pq.push(temp);
    }

    struct Node* new_node = pq.top();

    int code[50];
    printCodes(new_node,code,0);


    return 0;
}
