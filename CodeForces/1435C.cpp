#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tt=1;
	//cin >> tt;
	while(tt--)
	{
		int a[6];
		for(int i=0;i<6;i++)
		cin  >> a[i];
		sort(a,a+6);
		int n;
		cin >> n;
		int b[n];
		for(int i=0;i<n;i++)
		cin >> b[i];
		sort(b,b+n);
		pair<int,pair<int,int> > dp[n][6][6];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<6;j++)
			{
				for(int k=0;k<6;k++)
				{
					dp[i][j][k].first=INF;
					dp[i][j][k].second.first=0;
					dp[i][j][k].second.second=INF;
				}
			}
		}
		int c[n][6];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<6;j++)
			{
				c[i][j]=b[i]-a[j];
			}
		}
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<=i;j++)
			{
				dp[0][j][i].first=0;
				dp[0][j][i].second.first=c[0][i];
				dp[0][j][i].second.second=c[0][i];
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<6;j++)
			{
				for(int k=0;k<=j;k++)
				{
					for(int l=0;l<=k;l++)
					{
						int z1=min(dp[i-1][l][k].second.first,c[i][j]);
						int z2=max(dp[i-1][l][k].second.second,c[i][j]);
						int z3=z2-z1;
						if(z3<dp[i][k][j].first)
						{
							dp[i][k][j].second.first=z1;
							dp[i][k][j].second.second=z2;
							dp[i][k][j].first=z3;
						}
					}
				}
			}
		}
		int mn=INF;
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				mn=min(mn,dp[n-1][i][j].first);
			}
		}
		cout << mn << endl;
	}
	return 0;
}
