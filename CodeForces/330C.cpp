#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fr first
#define sc second
const int inf=INT_MAX;
const int nmax=1e5+5;
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int n,i,j,sum1,sum2,a1[101],a2[101];
char c;
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
   cin>>n;
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
	{
	  cin>>c;
	  if(c=='.')
	  {
	  	if(!a1[i])a1[i]=j,sum1++;
	  	if(!a2[j])a2[j]=i,sum2++;
	  }	
	}
   if(sum1==n)for(i=1;i<=n;i++)cout<<i<<" "<<a1[i]<<endl;
   else if(sum2==n)for(i=1;i<=n;i++)cout<<a2[i]<<" "<<i<<endl;
   else cout<<-1<<endl;
   return 0;
}
