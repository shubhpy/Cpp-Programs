#include <iostream>
#include <vector>

using namespace std;

void solve(int &g1,int &c1,int &v1,int &g2,int &c2,int &v2,int g,int c){

    if ((g==0 && c==1) || (g==1 && c==0)){
        if ((g1==0  && c1==0) || (g1==c && c1==g)){
            g1=g;c1=c;
        }
        else{
            g1=0;c1=0,v1++;
        }

        if ((g2==0  && c2==0) || (g2==c && c2==g)){
            g2=g;c2=c;
        }
        else{
            g2=0;c2=0,v2++;
        }
    }
    else{
        if (g1==0 && c1==0){
            g1 = 1;c1=0;
        }
        else{
            int t = g1;
            g1 = c1;
            c1 = t;
        }

        if (g2==0 && c2==0){
            g2 = 0;c2=1;
        }
        else{
            int t = g2;
            g2 = c2;
            c2 = t;
        }

    }

}


int main() {
    int n;
    cin >> n;
    int d;
    int g1=0,c1=0,v1=0;
    int g2=0,c2=0,v2=0;
    for(int i=0;i<n;i++){
        cin >> d;
        if (d==0){
            g1=0;c1=0;v1++;
            g2=0;c2=0;v2++;
        }
        else if (d==1){
            solve(g1,c1,v1,g2,c2,v2,0,1);
        }
        else if (d==2){
           solve(g1,c1,v1,g2,c2,v2,1,0);
        }
        else if (d==3){
            solve(g1,c1,v1,g2,c2,v2,1,1);
        }

        //cout << g1 << " " << c1 << " " << g2 << " " << c2 << " " << min(v1,v2) << "\n";

        if (v2>v1){
            v2 = v1;
            g2=g1;
            c2=c1;
        }
        else if (v1>v2){
            v1=v2;
            g1=g2;
            c1=c2;
        }

        //cout << g1 << " " << c1 << " " << g2 << " " << c2 << " " << min(v1,v2) << "\n";
    }

    cout << min(v1,v2);
    return 0;
}
