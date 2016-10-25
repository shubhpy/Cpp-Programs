// int compareFunction(const void* aa, const void* bb) {

//         int a = *((int *)aa);
//         int b = *((int *)bb);
//         int digita = 1 + (int)log10(a);
//         int digitb = 1 +(int)log10(b);

//         int value1 = a*pow(10,digitb) + b;
//         int value2 = b*pow(10,digita) + a;

//         if (value1 <= value2) {
//             // Return -1 if you want ascending. 1 if you want descending.
//             return 1;
//         } else if (value1 > value2) {
//             // Return 1 if you want ascending. -1 if you want descending.
//             return -1;
//         }
// }
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}

string Solution::largestNumber(const vector<int> &A) {

    string s = "";


    vector<string> V(A.size());

    for(int i=0;i<A.size();i++){
        V[i] = to_string(A[i]);
    }

    sort(V.begin(),V.end(),myCompare);

    // for(int i=0;i<V.size();i++){

    //     for(int j=i+1;j<V.size();j++ ){

    //         int a  = V[i];
    //         int b = V[j];

    //         int digita = 1 + (int)log10(a);
    //         int digitb = 1 +(int)log10(b);

    //         int aGb= a*pow(10,digitb) + b;
    //         int bGa= b*pow(10,digita) + a;

    //         if (bGa>aGb){
    //             int temp = V[j];
    //             V[j] = V[i];
    //             V[i] = temp;
    //         }

    //     }
    // }

    for(int i=0;i<A.size();i++){
        s+=V[i];
    }

    int count = 0;
    if (s[0]=='0'){
        count = 1;
        for(int i=1;i<s.length();i++){
            if (s[i]=='0'){
                count++;
            }
            else{
                break;
            }
        }
    }

    if (count==s.length()){
        return "0";
    }
    else{
        return s.substr(count,s.length()-count);
    }

    //return s;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
