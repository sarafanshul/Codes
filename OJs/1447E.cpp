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

const long long MAXN = 5e6 +7;

const int K = 30;
int adj[MAXN][2] ,n ,m = 1 ,ans = 1;

void dfs(int v ,int x){
	if(adj[v][0] == 0 && adj[v][1] == 0){
		ans = max(ans ,x);
		return;
	}

	if(adj[v][0] != 0 && adj[v][1] != 0)x++;

	for(int c = 0 ; c < 2 ;c++){
		if(adj[v][c] != 0) dfs(adj[v][c] ,x);
	}
}

void check(){
	cin >> n;
	int x ,v = 0;
	for(int i = 0 ; i < n ;i++){
		cin >> x;
		v = 0;
		for(int k = K- 1 ; k >= 0 ; k--){
			int c = (x >> k)&1;
			if(adj[v][c] == 0) adj[v][c] = m++;
			v = adj[v][c];
		}
	}
	dfs(0 ,1);
	cout << n - ans;
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
