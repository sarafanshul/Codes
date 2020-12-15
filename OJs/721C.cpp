#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
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

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

const long long MAXN = 5007;

ll n ,m ,T;
int dp[MAXN][MAXN] ,par[MAXN][MAXN];
bool vis[MAXN];
vector<pair<ll ,ll>> adj[MAXN];
vector<ll> ans;

void dfs(ll v){
	vis[v] = 1;
	if(v == n){
		dp[n][1] = 0;
		return ;
	}
	for(auto &pi : adj[v]){
		if(!vis[pi.F])dfs(pi.F);
	}

	for(auto &pi : adj[v]){
		for(ll j = 1 ;j <= n ; j++){
			if( dp[v][j] > dp[pi.F][j - 1] + pi.S){
				dp[v][j] = dp[pi.F][j - 1] + pi.S;
				par[v][j] = pi.F;
			}
		}
	}
}

void check(){
	cin >> n >> m >> T;
	ll u ,v ,w;
	memset(dp ,0x3f ,sizeof(dp));

	for(int i = 0 ; i < m ; i++){
		cin >> u >> v >> w;
		adj[u].PB(MP(v ,w));
	}
	dfs(1);

	ll lg = 0 ,node = 1;
	for(int i = n ;i > 0 ;i--){
		if(dp[1][i] <= T){
			lg = i;
			break;
		}
	}
	while(node != n){
		ans.PB(node);
		node = par[node][lg];
		lg--;
	}
	ans.PB(n);
	cout << ans.size() <<'\n';
	for(ll&u :ans) cout << u <<' ';
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
