#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
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

const long long MAXN = 1e5 +7;

vector<ll> adj[MAXN];
bool now[MAXN] = {0} ,to[MAXN] = {0};
ll n;
vector<ll> ans;

void dfs(ll v ,ll par , ll level ,ll odd ,ll eve){
    
    if(odd){ if(level%2){ now[v] ^= 1; } }
    if(eve){ if(level%2 == 0){ now[v] ^= 1; } }
    
    if(now[v] != to[v]){
        if(level%2) odd ^= 1;
        else eve ^= 1;
        
        now[v] ^= 1;
        ans.PB(v);
    }
    
    for(ll &u : adj[v]){
        if( u != par) dfs(u ,v ,level+1 ,odd ,eve);
    }
}

void check(){
	cin >> n;
	ll u ,v;
	for(ll i = 0 ;i +1 < n ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(ll i = 1; i <= n ;i++) cin >> now[i];
	for(ll i = 1 ;i <= n; i++) cin >> to[i];

	dfs(1 ,-1 ,1 ,0 ,0);
	cout << ans.size() <<"\n";
	for(ll &u : ans)cout << u <<"\n";
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
