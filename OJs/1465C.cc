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

const long long MAXN = 1e5 +7;

struct dsu {
	struct rnk {
		int val = 1;
		int get() const {
			return val;
		}
		void add(const rnk &r) {
			val += r.val;
		}
	};
	vector<int> p;
	vector<rnk> r;
	int comp = 0, edge = 0;
	dsu() {}
	bool empty() const {
		return p.empty();
	}
	dsu(int n) {
		p = vector<int>(n);
		r = vector<rnk>(n);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		comp = n;
	}
	int getp(int v) { // returns head element in a set
		return v == p[v] ? v : p[v] = getp(p[v]);
	}
	bool check(int a, int b) { // a and b are in one component
		return getp(a) == getp(b);
	}
	bool unite(int a, int b) { // a and b are in diff components
		a = getp(a);
		b = getp(b);
		if (a == b) return false;
		++edge;
		--comp;
		if (r[a].get() > r[b].get()) swap(a, b);
		p[a] = b;
		r[b].add(r[a]);
		return true;
	}
};


void check(){
	ll n , m;
	cin >> n >> m;
	dsu D(n) ;

	ll ans = 0 , x , y;
	for(ll i = 0 ; i < m ; i++){
		cin >> x >> y; 
		x-- , y-- ;
		if(x == y)continue ;
		ans ++ ;
		ans += ( ! D.unite(x , y) ) ;
	}
	cout << ans <<'\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
