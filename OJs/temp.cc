#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
using namespace __gnu_pbds;
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
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template< class T > using ordered_set =  tree<
	T, // Key type
	null_type, // Mapped-policy
	less<T>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> ; // A policy for updating node invariants	

const long long MAXN = 2e5 +7;
const ll mod = 1e9 + 7;

int n, m;
bool vis[500100];
vector<int> g[500100];
ll disc[500100], low[500100], power[500100], tim = 0;
vector<ll> ap;
ll isap[500100] = {0};

ll pwr(ll a, ll b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % mod;
	if (b % 2 == 1)
		return (pwr(a, b - 1) * a) % mod;
	ll q = pwr(a, b / 2);
	return (q * q) % mod;
}
 
void dfs(ll x, ll prev) {
	vis[x] = 1;
	disc[x] = low[x] = ++tim;
	int child = 0;
	for (auto ch : g[x]) {
		if (ch != prev) {
			if (!vis[ch]) {
				child++;
				dfs(ch, x);
				low[x] = min(low[x], low[ch]);
				if (prev == -1 && child > 1 && !isap[x]) {
					isap[x] = 1;
					ap.push_back(x);
				} else if (prev != -1 && low[ch] >= disc[x] && !isap[x]) {
					isap[x] = 1;
					ap.push_back(x);
				}
			} else
				low[x] = min(low[x], disc[ch]);
		}
	}
}

void check(){
	cin >> n >> m;
	ll i, j ;
	for (i = 1; i <= n; i++)
		cin >> power[i];
	for (i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i, -1);
	}
 
	ll arr[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	ll f[600] = {0};
	function< void(ll)> go = [ & ] ( ll xx ) {
		for (i = 0; i < xx; i++) {
		ll temp = 0;
		for (j = 0; j < 9; j++)
			if (power[ap[i]] % arr[j] == 0)
				temp |= (1 << j);
		f[temp]++;
		}
		for (i = 0; i < 512; i++) {
			f[i] = (pwr(2, f[i]) - 1 + mod) % mod;
		}
	} ;

	go( ap.size() ) ;

	for (i = 0; i < ap.size(); i++) {
		ll temp = 0;
		for (j = 0; j < 9; j++)
			if (power[ap[i]] % arr[j] == 0)
				temp |= (1 << j);
		f[temp]++;
	}

	for (i = 0; i < 512; i++) {
		f[i] = (pwr(2, f[i]) - 1 + mod) % mod;
	}

	ll dp[2][10000] = {0};
	ll c = 1, p = 0;
	for (i = 0; i < 512; i++) {
		ll temp = f[i];
		for (j = 0; j < 512; j++)
			dp[c][j] = dp[p][j];
		for (j = 0; j < 512; j++) {
			dp[c][j | i] = (dp[c][j | i] + ((dp[p][j] * temp) % mod)) % mod;
		}
		dp[c][i] = (dp[c][i] + temp) % mod;
		c = !c;
		p = !p;
	}
	cout << dp[p][511] << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
