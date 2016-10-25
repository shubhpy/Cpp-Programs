#include<iostream>
#include<cstring>

using namespace std;
int sum = 0;
int prob = 0;
int total = 0;
void solve(string b,int i,int sumb){

    if (i==b.length()){
        if (sumb==sum){
            prob++;
        }
    total++;
    return ;
    }

    if (b[i]=='+'){
        sumb++;
        solve(b,i+1,sumb);
    }
    else if (b[i]=='-'){
        sumb--;
        solve(b,i+1,sumb);
    }
    else{
        solve(b,i+1,sumb+1);
        solve(b,i+1,sumb-1);
    }
}

int main(){

    //freopen("dreamoon.txt","r",stdin);
    string a,b;
    cin >> a >> b;

    for(int i = 0;i<a.length();i++){
        if (a[i]=='-')
            sum--;
        else
            sum++;
    }

    int sumb = 0;
    solve(b,0,sumb);

    printf("%.12f",((float)prob)/total) ;



return 0;
}

