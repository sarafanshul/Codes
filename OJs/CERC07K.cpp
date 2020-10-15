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
const ll INF = (ll)1e18+7;
const ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
ll adj[107][107][16];
bool vis[107][107][16];
string grid[107];
ll n ,m;
 
inline bool ok(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
 
inline bool can(const char c ,const ll K){
	return ((c == 'B' && (K & 1)) || 
			(c == 'Y' && (K & 2)) || 
			(c == 'R' && (K & 4)) || 
			(c == 'G' && (K & 8)) || 
			(c == '.') || (c == 'b') || 
			(c == 'y') || (c == 'r') || 
			(c == 'g') || (c == 'X') || 
			(c == '*'));
}
 
void check(){
	memset(adj ,0LL ,sizeof(adj));
	memset(vis ,false ,sizeof(vis));
    queue<pair<pair<ll ,ll> ,ll>> q;
    
	for(int i = 0 ;i < n ;i++) cin >> grid[i];
	
	for(ll i = 0 ;i < n ;i++){
		for(ll j = 0 ;j < m ;j++){
			if(grid[i][j] == '*') q.push( MP(MP(i ,j) ,0LL) );
		}
	}
 
	ll ans = INF ,keys ,newKeys ,x ,y ,xx ,yy ;
 
	while(!q.empty()){
		x = q.front().F.F ,y = q.front().F.S , keys = newKeys = q.front().S;
		q.pop();
// 		cout << MP(x ,y)<<" ";
		if(grid[x][y] == 'X'){ans = adj[x][y][keys];break;}
 
		if(grid[x][y] == 'b') newKeys |= 1;
		if(grid[x][y] == 'y') newKeys |= 2;
		if(grid[x][y] == 'r') newKeys |= 4;
		if(grid[x][y] == 'g') newKeys |= 8;
 
		for(ll i = 0; i < 4 ;i++){
			xx = x+ dx[i] ,yy = y+dy[i];
			if(ok(xx ,yy) && !vis[xx][yy][newKeys]){
				if(can(grid[xx][yy] ,newKeys)){
					adj[xx][yy][newKeys] = adj[x][y][keys]+1;
					vis[xx][yy][newKeys] = 1;
					q.push(MP(MP(xx ,yy) ,newKeys));}
			}
		}
	}
	if (ans == INF) cout << "The poor student is trapped!\n";
	else cout << "Escape possible in " << ans << " steps.\n";
}
 
int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	
	while(cin >> n >> m){
		if(n == 0) break;
		check();
	}
	return 0;
}
