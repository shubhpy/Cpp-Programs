/*
Exam No 4 Maximum Xor with Prefix and Suffix
*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define INT_SIZE 64

struct TNode
{
    LL data;
    TNode *arr[2];
};

TNode *newNode()
{
    TNode *temp = new TNode;
    temp->data = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert_in_trie(TNode *root, LL no)
{
    TNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        bool val = no & (1<<i);
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
    temp->data = no;
}

LL find_min_xor(TNode *root, LL no)
{
    TNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        bool val = no & (1<<i);
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return no^(temp->data);
}

int solve(vector<LL> &v, int n)
{
    TNode *root = newNode();
    LL ans = INT_MIN;
    LL prefix[n];
    LL suffix[n];
    prefix[0]=v[0];
    ans = max(ans,prefix[0]);
    suffix[n-1]=v[n-1];

    for(int i = 1;i<n;i++){
        prefix[i] = prefix[i-1]^v[i];
        ans = max(ans,prefix[i]);
    }
    insert_in_trie(root,suffix[n-1]);
    ans = max(ans,find_min_xor(root,prefix[n-1-1]));
    for(int i = n-2;i>=1;i--){
        suffix[i] = suffix[i+1]^v[i];
        insert_in_trie(root,suffix[i]);
        ans = max(ans,suffix[i]);
        ans = max(ans,find_min_xor(root,prefix[i-1]));
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << solve(v, n);
    return 0;
}

//7acd0500-3dd1-461a-839e-adbd0536a028
