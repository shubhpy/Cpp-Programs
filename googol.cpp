#include<iostream>
#include<vector>

using namespace std;

char get_ans(vector<char>& vect,long long int K){
    while(vect.size()<K){
        int si = vect.size();
        vect.push_back('0');
        for(long long int j=si-1;j>-1;j--){
            if (vect[j]=='0'){
                vect.push_back('1');
            }
            else{
                vect.push_back('0');
            }
        }
    }
    return vect[K-1];
    }

int main()
{
    long long int T,K,i;
    cin>>T;
    vector<char> vect;
    vector<int> Test;
    vect.push_back('0');
    for (long long int i=0;i<T;i++){
        cin>>K;
        Test.push_back(K);
        //cout << "Case #" << i+1 << ": " <<get_ans(vect,K) << "\n";
        /*for(int k=0;k<vect.size();k++){
            cout << vect[k] << " ";
        }
        cout <<"\n" <<vect.size();
        */
    }
    for (int i=0;i<T;i++){
        cout << "Case #" << i+1 << ": " <<get_ans(vect,Test[i]) << "\n";
    }
    }
