int Solution::singleNumber(const vector<int> &A) {

    unsigned int ans = 0;
    int count;
    int k = 31;
    for(int i = 1 << 31;i>0;i=i/2){
        count = 0;
        for(int j = 0;j<A.size();j++){
            if (A[j]&i)
                count++;
        }
        cout << count << "\n";
        ans = ans + (count%3)*pow(2,k);
        k--;
    }

    // return ans;
}
