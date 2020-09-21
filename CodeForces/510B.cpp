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

const size_t MAXN = 1e2 +7;

ll adj[MAXN][MAXN];
ll n ,m;
bool is_cyc , vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

template<typename T = ll > 
void dfs(T v ,T u ,T pv ,T pu ,T c){
	if(v < 0 || v >= n || u < 0 || u >= m) return ;
	if(adj[v][u] != c) return ;
	if(vis[v][u]){is_cyc = 1;return;}
	vis[v][u]= 1;
	ll nv ,nu;
	for(ll f = 0 ;f < 4 ;f++){
		nv = v + dx[f];
		nu = u + dy[f];
		if(nv == pv && nu == pu) continue;
		dfs(nv ,nu ,v ,u ,c);
	}
}

void check(){
	memset(adj ,-1 ,sizeof(adj));
	memset(vis ,0 ,sizeof(vis));
	cin >> n >> m;
	string s;
	for(int i = 0; i < n ;i++){
		cin >> s;
		for(int j = 0; j < m ; j++){
			adj[i][j] = s[j] - '0';
		}
	}
	for(ll i = 0; i < n ;i++){
		for(ll j = 0; j < m ; j++){
			if(!vis[i][j]) dfs(i ,j ,-1LL ,-1LL ,adj[i][j]);
			}
		}
	cout<< (is_cyc ? "Yes" : "No");
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
