#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 407;
#define int ll

int n ,m ,adj[MAXN][MAXN] = {0} ,d[MAXN] = {0};

void check(){
	int u ,v;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	int t = 1;
	if(adj[1][n]) t = 0; // satation between 1 - n ;else inverse

	queue<int> q;
	q.push(1);
	d[1] = 1;
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int i = 1 ;i <= n ; i++){
			if(adj[v][i] == t && d[i] == 0){
				q.push(i);
				d[i] = d[v] + 1;
			}
		}
	}
	cout << d[n] - 1;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
