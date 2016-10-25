int Solution::lis(const vector<int> &A) {

    int n = A.size();
    vector<int> len(n+1);
    int L = 0;

    len[1] =  A[0];
    L  = 1;
    int broke = 0;
    for(int i = 1;i<n;i++){
        broke  = 0;
        for(int j  = L;j>=1;j--){
            if (len[j]<A[i]){
                L  = max(L,j+1);
                len[j+1] = A[i];
                broke  = 1;
                break;
            }
        }
        if (broke==0){
            len[1] = A[i];
        }
    }

    // cout << L << "\n";
    return L;



    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
