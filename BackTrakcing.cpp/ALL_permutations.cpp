void swap(vector<int> &A,int x, int y)
{
    int temp;
    temp = A[x];
    A[x]= A[y];
    A[y] = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permuteSolve(vector<int> &A, int l, int r,vector<vector<int> > &ans)
{
   int i;
   if (l == r){
        ans.push_back(A);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(A,l, i);
          permuteSolve(A, l+1, r,ans);
          swap(A,l, i); //backtrack
       }
   }
}


vector<vector<int> > Solution::permute(vector<int> &A) {

    vector<vector<int> > ans;
    int n = A.size();

    permuteSolve(A,0,n-1,ans);

    return ans;


    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

