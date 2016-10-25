
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>

using namespace std;

int main(){
    int n,c;
    cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
        }

    sort(vect.begin(),vect.end());
    reverse(vect.begin(),vect.end());

    int count=0;
    int temp = 0;
    bool building = true;
    for (int i=0;i<n;i++){
        if (vect[i]!=-1){

            if (accumulate(vect.begin(),vect.end(),0)==-1*n){
                i=n;
                break;
            }

            if (building){
                if (vect[i]!=0){
                    temp = vect[i];
                    vect[i] = -1;
                    count++;
                    building = false;
                }
                else{
                    count++;
                    vect[i] = -1;
                    building = true;
                    temp = 0;
                }
            }
            else{
                if (temp==0){
                    building = true;
                }
                else if (vect[i]!=0){
                     if (vect[i] <=temp){
                        temp --;
                        vect[i] = -1;
                     }
                }
                else{
                    vect[i] = -1;
                    building = true;
                }
            }
    }
  }

  cout << count;

}
