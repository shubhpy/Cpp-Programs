#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
#define LL long long int

int main(){
    LL N,c;
    cin >> N;
    vector<LL> v[N];
    int posi,posj;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        cin >> c;
        v[i].push_back(c);
        if (v[i][j]==0){
            posi = i;
            posj = j;
        }
        }
    }

    if (N==1){
        cout << 1;
    }else{
        LL ultisum ;
        LL prevsum = 0;
        LL sum = 0;
        bool magic  = true;

        for(int i=0;i<N;i++){
            if (i!=posi){
                for(int j=0;j<N;j++){
                    sum+=v[i][j];
                }
                if (prevsum==0){
                    prevsum = sum;
                }
                else if (prevsum!=sum){
                    magic = false;
                    break;
                }
            }
            sum = 0;
        }
        sum = 0;

        if (magic){
            for(int i=0;i<N;i++){
                if (i!=posj){
                    for(int j=0;j<N;j++){
                        sum+=v[j][i];
                    }
                    if (prevsum!=sum){
                        magic = false;
                        break;
                    }
                }
                sum = 0;
            }
            LL sum1=  0;
            LL sum2 = 0;
            LL sum3 = 0;

            if (magic){
                for(int i = 0;i<N;i++){
                    sum2+=v[posi][i];
                }
                for(int i = 0;i<N;i++){
                    sum3+=v[i][posj];
                }

                if (sum2==sum3){
                        if (prevsum>sum2){
                            int temp  = prevsum-sum2;
                            v[posi][posj] = -1000;
                            LL sumd1 = 0;
                            for(int i=0;i<N;i++){
                                sumd1+=v[i][i];
                            }

                            LL sumd2 = 0;
                            int j = 0;
                            for(int i=N-1;i>=0;i--){
                                sumd2+=v[i][j];
                                j++;
                            }

                            if (sumd1!=sumd2){
                                if (temp == abs(sumd1-sumd2) - 1000){
                                    cout << temp ;
                                }
                                else{
                                    cout << -1;
                                }
                            }
                            else if (sumd1 == sumd2 && prevsum == sumd1){
                                cout << temp;
                            }
                            else if(sumd1==sumd2){
                                if (temp == abs(prevsum-sumd2) - 1000){
                                    cout << temp ;
                                }
                                else{
                                    cout << -1;
                                }
                            }
                        }
                        else{
                            cout << -1;
                        }
                }
                else{
                    cout << -1;
                }

            }
            else{
                cout << -1;
                }
            }
            else{
                cout << -1;
            }
    }

    return 0;
    }




