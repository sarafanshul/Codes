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

const long long MAXN = 507;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
ll adj[MAXN][MAXN] = {0} ,vis[MAXN][MAXN] = {0};
ll n ,m ,k ,cnt;

bool can(ll x ,ll y){
    if(x >= n || x < 0 || y < 0 || y >= m) return 0;
    if(vis[x][y] || adj[x][y] != 1) return 0;
    return 1;
}

void dfs(ll li ,ll lj ,ll tl){
    // cout << MP(tl ,MP(li ,lj));
	vis[li][lj] = 1;

	ll x ,y;
//	if(tl == cnt-k)return 1;
	for(int i = 0 ;i < 4; i++){
	    x = li + dx[i]; y = lj + dy[i];
        if(can(x ,y)){dfs(x ,y ,tl+1);}
	}
	if(k){
		--k;
		vis[li][lj] = 2;
	}
}

void check(){
	ll li ,lj;
	cin >> n >> m >> k;
	string s;
	for(int i = 0 ;i < n ;i++){
		cin >> s;
		for(int j = 0 ;j < m;j++){
			if(s[j] == '.') adj[i][j] = 1 ,cnt++ ,li = i ,lj = j;
		}
	}
// 	cout << MP(li ,lj);
	dfs(li ,lj ,1LL);
// 	cout << cnt - k;
	for(int i = 0; i < n ;i++){
		for(int j = 0; j < m ;j++){
			if(vis[i][j] == 2) cout <<"X";
			else cout << (adj[i][j] == 1 ? '.':'#');
		}cout <<"\n";
	}
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
