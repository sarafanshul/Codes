// #pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
// #pragma GCC target("avx,avx2,fma") 
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
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
 
const long long MAXN = 207;
 
ll n ,m;
ll grid[MAXN][MAXN] ,dist[MAXN][MAXN] = {0};
const ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
bool vis[MAXN][MAXN];
 
inline bool can(ll x ,ll y){return x >= 0 && y >= 0 && x < n && y < m;}
 
void bfs(){
	memset(vis ,0 ,MAXN*MAXN);
	queue<pair<ll ,ll>> q;
    for(ll x = 0 ; x  < n; x++){
        for(ll y = 0 ;y < m ;y++){
            if(grid[x][y]) q.push(MP(x ,y)) ,vis[x][y] = 1;
        }
    }
	ll i ,j;
	while(!q.empty()){
		i = q.front().F; j = q.front().S; q.pop();
		ll xx ,yy;
		for(int a = 0 ;a < 4 ;a++){
		    xx = i+dx[a] ,yy = j+dy[a];
			if(can(xx ,yy) && !vis[xx][yy]){
				q.push(MP(xx ,yy));
			    dist[xx][yy] = min(dist[xx][yy] ,dist[i][j]+1);
			    vis[xx][yy] = 1;
			}
		}
	}
}
 
void check(){
	memset(dist ,10000LL ,sizeof(dist));
	cin >> n >> m;
	vector<string> aaa(n);
	for(int i = 0 ;i < n ;i++) cin >> aaa[i];
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ;j  < m ;j++){
			grid[i][j] = aaa[i][j] - '0';
			if(grid[i][j]) dist[i][j] = 0;
		}
	}
	bfs();
	for(int i = 0 ;i < n ;i++){
		for(int j = 0; j < m ;j++){
			cout << dist[i][j] <<" ";
		}cout << "\n";
	}
}
 
int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
