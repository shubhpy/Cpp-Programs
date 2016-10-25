#include<stdio.h>
double dp[100005][2];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,T,n,x,k,A,B,C,i,bk,bx,bit,j;
	double a,b,c,ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d %d %d %d %d",&n,&x,&k,&A,&B,&C);
		a=(double)A/100;
		b=(double)B/100;
		c=(double)C/100;
//		printf("%lf %lf %lf\n",a,b,c);
		ans=0.0;
		for(bit=0;bit<33;bit++)
		{
			dp[0][0]=0.0;
			dp[0][1]=1.0;
			bk=(k&(1ll<<bit))>0?1:0;
			bx=(x&(1ll<<bit))>0?1:0;
			for(i=1;i<=n;i++)
			{
				dp[i][0]=0.0;
				dp[i][1]=0.0;
				
				dp[i][0]+=a*dp[i-1][bk&0];
				dp[i][0]+=b*dp[i-1][bk|0];
				dp[i][0]+=c*dp[i-1][bk^0];
				dp[i][1]+=a*dp[i-1][bk&1];
				dp[i][1]+=b*dp[i-1][bk|1];
				dp[i][1]+=c*dp[i-1][bk^1];
			}
			ans+=dp[n][bx]*(double)(1<<bit);
		}
		printf("Case #%d: %.10lf\n",t,ans);
	}
	return 0;
}
