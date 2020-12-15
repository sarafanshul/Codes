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
const size_t MAXN = 1e5 +7;

vector<vector<int>> g(MAXN ,vector<int>(0)), gr(MAXN ,vector<int>(0));
vector<bool> used(MAXN ,0);
vector<int> order, component;
int n ,m ,sccCount = 0;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

// for reverse graph
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

long long lcm(ll a, ll b){
    return (a / __gcd(a, b)) * b;
}

ll get(vector<ll> &ret){
    ll l = 1;
    for(ll i = 0; i < ret.size() ;i++) l = lcm(l ,ret[i]);
    return (l&1 ? l : l/2);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> n;
// 	cin >> m;
	component.reserve(MAXN);
	order.reserve(2*MAXN-1);
	for (int i = 0; i< n ;i++) {
		cin >> a;a--;
		g[i].push_back (a);
		gr[a].push_back (i);
	}

	// topological sort 
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	
	used.assign(n, false);
	ll ans = 0;
	vector<ll> ret;
	// since it is sorted ,If an element appears after v hence cycle(SCC)
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i]; // for stack based ds
		if (!used[v]) {
			dfs2 (v);
			if(component.size() == 1 && (g[component[0]][0] != component[0])){cout <<-1;return 0;}
			ret.PB((ll)component.size());
			// ... printing next component ...
// 			for(size_t i = 0 ; i < component.size(); i++){
// 				cout << component[i]+1 << " ";
// 			}cout << "CC\n";
			component.clear();
			sccCount++;
		}
// 		cout << sccCount <<"\n";
	}
	ans = get(ret);
	cout << ans;
	return 0;
}
