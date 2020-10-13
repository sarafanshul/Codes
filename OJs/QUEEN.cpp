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
 
const long long MAXN = 1e3 +7;
const ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const ll INF = (ll)1e18;
ll grid[MAXN][MAXN];
ll moves[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll n ,m ;
inline bool can(ll x, ll y) {return x >= 0 && y >= 0 && x < n && y < m;}
 
void check(){
    ll x1 ,x2 ,y1 ,y2;
	cin >> n >> m;
	string s;
	memset(grid ,1LL ,MAXN*MAXN);
	for(ll i = 0 ; i < n ;i++){
	    cin >> s;
		for(ll j = 0 ; j < m; j++){
			if(s[j] == 'S') grid[i][j] = 2 ,y1 = i ,x1 = j;
			else if(s[j] == 'F') grid[i][j] = 2 ,y2 = i ,x2 = j;
			else if(s[j] == '.')grid[i][j] = 0;
			else grid[i][j] = 1;
		}
	}
	queue<pair< pair<ll ,ll> ,pair<ll ,ll> >> q;
	q.push(MP(MP(y1 ,x1) ,MP(-1 ,0)));
	ll x = -1 ,y = -1 ,dr = -1 ,mv = -1 ,ans = INF;
	memset(vis ,false,MAXN*MAXN);
	memset(moves ,1000000LL,MAXN*MAXN);
    ll t = 0;
	while(!q.empty()){
		if(ans == 1) break;
		y = q.front().F.F;
		x = q.front().F.S;
		dr = q.front().S.F;
		mv = q.front().S.S;
		// cout << q.front() << "<>"<< ans <<"\n" ;
        t++;
		q.pop();
		if(x == x2 && y == y2) {ans = min(ans ,mv);continue;}
		ll xx ,yy;
		for(ll i = 0 ;i < 8 ;i++){
			xx = x + dx[i] ,yy = y + dy[i];
			if(can(yy ,xx) && (grid[yy][xx] != 1)){
				if(vis[yy][xx])
					if(mv >= moves[yy][xx]) continue;
				if(dr == i) {
					q.push(MP(MP(yy ,xx) ,MP(dr ,mv)));
					moves[yy][xx] = mv;
				}
				else {
				    q.push(MP(MP(yy ,xx) ,MP(i ,mv+1))) ;
				    moves[yy][xx] = mv+1;
				    vis[yy][xx] = 1;
				}
			}
		}
	}
	// cout << t << "\n";
	cout << (ans == INF ? -1 : ans) <<"\n";
 
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