// https://cses.fi/problemset/task/1651
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

// https://github.com/ei1333
template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {
  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;

  LazySegmentTree(int n, const F f, const G g, const H h,
				  const Monoid &M1, const OperatorMonoid OM0)
	  : f(f), g(g), h(h), M1(M1), OM0(OM0) {
	sz = 1;
	height = 0;
	while(sz < n) sz <<= 1, height++;
	data.assign(2 * sz, M1);
	lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
	data[k + sz] = x;
  }

  void build() {
	for(int k = sz - 1; k > 0; k--) {
	  data[k] = f(data[2 * k + 0], data[2 * k + 1]);
	}
  }

  inline void propagate(int k) {
	if(lazy[k] != OM0) {
	  lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
	  lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
	  data[k] = apply(k);
	  lazy[k] = OM0;
	}
  }

  inline Monoid apply(int k) {
	return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
	while(k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));
  }

  inline void thrust(int k) {
	for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
	if(a >= b) return;
	thrust(a += sz);
	thrust(b += sz - 1);
	for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
	  if(l & 1) lazy[l] = h(lazy[l], x), ++l;
	  if(r & 1) --r, lazy[r] = h(lazy[r], x);
	}
	recalc(a);
	recalc(b);
  }

  Monoid query(int a, int b) {
	if(a >= b) return M1;
	thrust(a += sz);
	thrust(b += sz - 1);
	Monoid L = M1, R = M1;
	for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
	  if(l & 1) L = f(L, apply(l++));
	  if(r & 1) R = f(apply(--r), R);
	}
	return f(L, R);
  }

  Monoid operator[](const int &k) {
	return query(k, k + 1);
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
	while(a < sz) {
	  propagate(a);
	  Monoid nxt = type ? f(apply(2 * a + type), M) : f(M, apply(2 * a + type));
	  if(check(nxt)) a = 2 * a + type;
	  else M = nxt, a = 2 * a + 1 - type;
	}
	return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
	Monoid L = M1;
	if(a <= 0) {
	  if(check(f(L, apply(1)))) return find_subtree(1, check, L, false);
	  return -1;
	}
	thrust(a + sz);
	int b = sz;
	for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
	  if(a & 1) {
		Monoid nxt = f(L, apply(a));
		if(check(nxt)) return find_subtree(a, check, L, false);
		L = nxt;
		++a;
	  }
	}
	return -1;
  }
  
  template< typename C >
  int find_last(int b, const C &check) {
	Monoid R = M1;
	if(b >= sz) {
	  if(check(f(apply(1), R))) return find_subtree(1, check, R, true);
	  return -1;
	}
	thrust(b + sz - 1);
	int a = sz;
	for(b += sz; a < b; a >>= 1, b >>= 1) {
	  if(b & 1) {
		Monoid nxt = f(apply(--b), R);
		if(check(nxt)) return find_subtree(b, check, R, true);
		R = nxt;
	  }
	}
	return -1;
  }
};

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
LazySegmentTree< Monoid, OperatorMonoid, F, G, H > get_lazy_segment_tree
	(int N, const F &f, const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {
  return {N, f, g, h, M1, OM0};
}

void check(){
	ll n , q; 
	cin >> n >> q;
	auto f = [](const ll& a , const ll & b) -> ll { // propogates data[]
		return a + b ;
	};
	auto g = [](const ll& a , const ll & b) -> ll { // merges lazy[] and data[]
		return a + b ;
	};
	auto h = [](const ll& a , const ll & b) -> ll { // propogtes lazy[]
		return a + b ;
	};
	auto sg = get_lazy_segment_tree( n , f , g , h , 0LL , 0LL ) ;

	ll x ;
	for(ll i = 0 ; i < n ; i++){
		cin >> x; 
		sg.set(i , x);
	}

	while(q--){
		ll t;
		cin >> t;
		if(t == 1){
			ll a , b ;
			cin >> a >> b >> x;
			sg.update(--a , b , x);
		}else{
			ll k;
			cin >> k;
			cout << sg[--k] << '\n' ;
		}
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;  
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
