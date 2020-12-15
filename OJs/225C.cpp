#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const long long MAXN = 1e3 +7;
ll a[MAXN][MAXN] ,cnt[MAXN][2] ,dp[MAXN][MAXN][2];
char c[MAXN][MAXN] ,t;

void check(){
	ll m ,n ,x ,y;
	cin >> m >> n >> x >> y;
	for(int i = 0; i< m;i++){
		for(int j = 0; j < n ;j++){
			cin >> t;
			if(t == '#') cnt[j][1]++;
			else cnt[j][0]++;
		}
	}
	memset(dp ,107 ,sizeof(dp));
	for(int i=0;i<n;i++){
        if(!i) for(int k=0;k<2;k++) {dp[i][1][k]=cnt[i][k];}
        for(int j=1;j<=i+1&&j<=y;j++){
            if(j==1){
                for(int k=x;k<=y;k++){
                    dp[i][j][0]=min(dp[i][j][0],dp[i-1][k][1]+cnt[i][0]);
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][0]+cnt[i][1]);
                }
            }else {
                dp[i][j][0]=dp[i-1][j-1][0]+cnt[i][0];
                dp[i][j][1]=dp[i-1][j-1][1]+cnt[i][1];
            }
        }
    }	
	ll ans = LONG_LONG_MAX;
	for(int i = x; i<= y ;i++){
		ans=min(ans,dp[n-1][i][0]);
        ans=min(ans,dp[n-1][i][1]);
	}
	cout <<ans;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
