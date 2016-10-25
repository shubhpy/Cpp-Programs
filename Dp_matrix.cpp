#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void SieveOfEratosthenes(vector<bool> &prime,int n)
{
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}


int main() {
    freopen("dp4.txt","r",stdin);
    int n,m;
    cin >> n >> m;

    int v[n][m];

    int x;
    vector<bool> prime(100005,true);
    SieveOfEratosthenes(prime,100005);
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
          cin >> x;

          if (prime[x]){
            v[i][j] = 1;
          }
          else{
            v[i][j] = 0;
          }
        }
    }

    int dp[n+1][m+1];

    for(int i = 0;i<m;i++){
            dp[n][i] = 0;
    }

    for(int i = 0;i<n;i++){
            dp[i][m] = 0;
    }

    dp[0][0] =1;
    for(int i = 1;i<n;i++){
        if (v[i][0]==0)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }

    for(int i = 1;i<m;i++){
        if (v[0][i]==0)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i-1];
    }

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if (v[i][j]==0)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1];
        }
    }


    cout << dp[n-1][m-1] << "\n";

    if (!dp[n-1][m-1])
    {
        int i = 0;
        int j = 0;
        cout << i+1 << " " << j+1 << "\n";
        int done  = 0;
        int failed = 0;
        while(!done){
            //cout <<  i << " " << j << "\n";
            if (dp[i+1][j+1]){
                i++;
                j++;
                cout << i+1 << " " << j+1 << "\n";
            }
            else if (dp[i+1][j]){
                i++;
                cout << i+1 << " " << j+1 << "\n";
            }
            else if(dp[i][j+1]){
                j++;
                cout << i+1 << " " << j+1 << "\n";
            }
            else{
                break;
            }

            if (i+1==n && j+1==m)
                done  = 1;
        }

    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007
#define MAX 100005



int prime[100007];
void sieve()
{
    for(int i=2;i*i<=100005;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=100005;j+=i)
                prime[j] = 1;
        }
    }
}

int a[1005][1005];
ll dp[1005][1005];
int mark[1005][1005];

int q=0,n,m;

pair<int,int>ans[100005];

void dfs(int i,int j,int k)
{
    if(a[i][j]==0||i>n||j>m||mark[i][j]||q)
        return;

    mark[i][j]=1;
    ans[k]=mp(i,j);

    if(i==n&&j==m)
    {
        q=k;
        return;
    }

    dfs(i+1,j+1,k+1);
    dfs(i+1,j,k+1);
    dfs(i,j+1,k+1);

}


int main()
{

    sd(n);
    sd(m);

    sieve();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];

            if(prime[a[i][j]]==0)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }


    dp[1][1]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
                continue;

            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%MOD;

            if(a[i][j]==0)
                dp[i][j]=0;
        }

    }

    cout<<dp[n][m]<<"\n";

    dfs(1,1,1);

    for(int i=1;i<=q;i++)
        cout<<ans[i].F<<" "<<ans[i].S<<"\n";






    return 0;


}


