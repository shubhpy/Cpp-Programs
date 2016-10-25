#include<stdio.h>
//#include<iostream>

#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))
#define PrintDigit(c, d) for(i=0; i < c ; i++)putchar(unit[d]);
#define forn(a,n) for(i=a; i < n ; i++);

using namespace std;

int setbits(unsigned n)
{
    unsigned i;
    int count = 0;
    for (i = 1 << 31; i > 0; i = i / 2)
        if (n & i){
            printf("1");
            count++;
        }
        else{
            printf("0");
        }

    return count;
}

int main(){
    //freopen("in4.txt","r",stdin);
	//freopen("out6.txt","w",stdout);
    int i,j,k,x,y,z,l,m,n;
    int N;
    scanf("%d",&N);
    //int v[N];
    for(int i=0;i<N;i++){
        //cin >> v[i];
        x = setbits(i);
        printf(" %d  %d \n",i,x);

        }
 return 0;
}


