// Euler Tour + Segment Tree(Lazy)
// CF 620E;

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

const long long MAXN = 1e6 +7;
struct node{
	ll num, lazy;
}tree[MAXN<<2];
vector<vector<ll>> adj(MAXN ,vector<ll>(0));
bool vis[MAXN] = {0};
vector<ll> lef(MAXN) ,rig(MAXN) ,col(MAXN) ,val(MAXN);
ll n ,m ,_time = 0 ,ans = 0;

void dfs(int v){
	lef[v] = ++_time;
	val[_time] = col[v];
	vis[v] = 1;
	for(int u : adj[v]){
		if(!vis[u]) dfs(u);
	}
	rig[v] = _time;
}

void pushup(ll rt){
	tree[rt].num = tree[rt<<1].num | tree[rt<<1|1].num;
}

void pushdown(ll rt){
	if(tree[rt].lazy){
		tree[rt<<1].num = tree[rt<<1|1].num = 1ll<<tree[rt].lazy;
		tree[rt<<1].lazy = tree[rt<<1|1].lazy = tree[rt].lazy;
		tree[rt].lazy = 0;
	}
}

void build(ll rt ,ll l ,ll r){
	tree[rt].lazy = 0;
	if(l == r){
		tree[rt].num = 1LL<<val[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(rt<<1 ,l ,mid);
	build(rt<<1|1 ,mid+1 ,r);
	pushup(rt);
}

void update(ll rt ,ll L ,ll R ,ll l ,ll r ,ll co){
	if(l <= L && r >= R){
		tree[rt].lazy = co;
		tree[rt].num = 1ll<<co;
		return;
    }
	ll mid = (L + R) >> 1;
	pushdown(rt);
	if(l <= mid) update(rt<<1,L,mid,l,r,co);
	if(r > mid) update(rt<<1|1,mid+1,R,l,r,co);
	pushup(rt);
}

void solve(ll rt ,ll L ,ll R ,ll l ,ll r){
	if(l <= L && r >= R){
		ans |= tree[rt].num;
		return;
	}
	pushdown(rt);
	ll mid = (L + R) >> 1;
	if(l <= mid) solve(rt<<1,L,mid,l,r);
	if(r > mid) solve(rt<<1|1,mid+1,R,l,r);
}

void check(){
	ll v ,u;
	cin >> n >> m;
	for(int i = 1 ;i <= n; i++) cin >> col[i];
	for(int i = 1; i < n ;i++){
		cin >> v >> u;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	_time = 0;
	dfs(1);
	build(1 ,1 ,n);
	ll d ,x ,co ,sum = 0;
	for(int i = 1 ;i <= m ;i++){
		cin >> d >> x;
		if(d == 1){
			cin >> co;
			update(1 ,1 ,n ,lef[x] ,rig[x] ,co);
		}else {
			ans = 0;
			solve(1 ,1 ,n ,lef[x] ,rig[x]);
			sum = 0;
			while(ans){
				if(ans&1) sum++;
				ans >>= 1;
			}
			cout << sum <<"\n";
		}
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
