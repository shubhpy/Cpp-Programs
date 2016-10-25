/* struct Node
{
  int data;
  struct Node *left,  *right;
  struct Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(struct Node *p)
{
   // Your Code Here
   if (p==NULL){
       return;
   }
   vector<struct Node *> cur;
   cur.push_back(p);

   while(cur.size()!=0){
       vector<struct Node *> temp;
       for(int i=0;i<cur.size();i++){
           if (cur[i]->left!=NULL)temp.push_back(cur[i]->left);
           if (cur[i]->right!=NULL)temp.push_back(cur[i]->right);
       }
       for(int i=0;i<temp.size();i++){
           if (i<temp.size()-1) temp[i]->nextRight = temp[i+1];
       }
       cur = temp;
   }
}
