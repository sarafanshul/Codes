#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using ld = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
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
const long long MAXN = 2e5 +7;

template<typename Monoid>
struct DisjointSetUnion {
	struct rnk {
		Monoid val = 1;
		Monoid get() const {
			return val;
		}
		void add(const rnk &r) {
			val += r.val;
		}
	};
	vector<Monoid> p;
	vector<rnk> r;
	Monoid comp = 0, edge = 0;
	DisjointSetUnion() {}
	bool empty() const {
		return p.empty();
	}
	DisjointSetUnion(Monoid n) {
		p = vector<Monoid>(n);
		r = vector<rnk>(n);
		for (Monoid i = 0; i < n; ++i)
			p[i] = i;
		comp = n;
	}
	Monoid getp(Monoid v) { // returns head element in a set
		return v == p[v] ? v : p[v] = getp(p[v]);
	}
	bool check(Monoid a, Monoid b) { // a and b are in one component
		return getp(a) == getp(b);
	}
	bool unite(Monoid a, Monoid b) { // a and b are in diff components
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
template<typename T = long long >
T fastExpo(T a, T n, T MOD) {
	T ans = 1;
	while(n >= 1) {
		if(n % 2 == 0) { a = (1LL * a * a) % MOD; n /= 2; }
		else { ans = (1LL * ans * a) % MOD; n--; }
	}
	return ans;
}

ll mod = 1e9 + 7 ;

void check(){
	ll n , m , k ;
	cin >> n >> m >> k  ;
	auto dsu = DisjointSetUnion<ll>( n + 1 ) ;

	for(ll a = 0 ; a + k <= n ; a++ ){
		for( ll l = a , r = a + k - 1 ; l <= r ; l++ , r-- )
			dsu.unite( l , r ) ;
	}
	ll pw = dsu.comp - 1 ;
	cout << fastExpo(m ,pw , mod ) << '\n' ;

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
