#include<iostream>
#include<vector>

using namespace std;

int main(){
        int n,k,w;
        cin >> n >> k;
        int a = -1;
        int x =0;
        int p;
        int b = n;
        vector<int > v[n];
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
            cin >> w;
            v[i].push_back(w);
                }
        }
        while(k>x){
            p=x;
            if (b==1){
                x = x+1;
            }
            else{
                x = 2*(b + b-2) + x;
            }
            b = b-2;
            a++;
        }

        k = k-p;

        int count = 0;
        int i = a;
        int j;
        for(j=a;j<n-a;j++)
            {
                count++;
                if (count==k){
                    cout << v[i][j];
                }
            }

        j = n-a-1;
        for(i=a;i<n-a;i++)
            {
                count++;
                if (count==k){
                    cout << v[i][j];
                }
            }

        i = n-1-a;
        for(j=n-a-1;j>=a;j--)
            {
                count++;
                if (count==k){
                    cout << v[i][j];
                }
            }
        j = a;
        for(i=n-1-a;i>=a;i--)
            {
                count++;
                if (count==k){
                    cout << v[i][j];
                }
            }
            return 0;
        }
