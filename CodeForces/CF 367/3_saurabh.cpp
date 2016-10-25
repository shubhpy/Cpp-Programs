#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;
#define INT_MAX 1000000000000000LL
int main()
{
    int n;
    cin>>n;
    int c[n];
    vector <pair<string,string> > a(n);
    for(int i=0 ; i<n ; i++)
        cin>>c[i];
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i].first;
        int l=a[i].first.length();
        string s;
        for(int j=l-1 ; j>=0 ; j--)
        {
            s=s+(char)(a[i].first[j]);
        }
        a[i].second=s;
    }
    long long int dp[n][2];
    dp[0][0]=0;
    dp[0][1]=c[0];

    bool flag=true;

    for(int i=1 ; i<n ; i++)
    {
        if(dp[i-1][0]>=INT_MAX && dp[i-1][1]>=INT_MAX)
        {
            flag=false;
            break;
        }

        if(a[i].first<a[i-1].first && a[i].first<a[i-1].second)
            dp[i][0]=INT_MAX;
        else if(a[i].first>=a[i-1].first && a[i].first>=a[i-1].second)
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        else if(a[i].first>=a[i-1].first)
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=dp[i-1][1];

        if(a[i].second<a[i-1].first && a[i].second<a[i-1].second)
            dp[i][1]=INT_MAX;
        else if(a[i].second>=a[i-1].first && a[i].second>=a[i-1].second)
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+c[i];
        else if(a[i].second>=a[i-1].first)
            dp[i][1]=dp[i-1][0]+c[i];
        else
            dp[i][1]=dp[i-1][1]+c[i];
    }

    for(int i=0;i<n;i++){
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }


    if(!flag || dp[n-1][0]>=INT_MAX && dp[n-1][1]>=INT_MAX)
        cout<<-1;
    else
        cout<<min(dp[n-1][0],dp[n-1][1]);
    return 0;
}
