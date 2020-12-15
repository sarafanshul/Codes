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

//https://github.com/ei1333
template< typename Monoid, typename F >
struct SegmentTree {
  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;
  
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
	sz = 1;
	while(sz < n) sz <<= 1;
	seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
	seg[k + sz] = x;
  }

  void build() {
	for(int k = sz - 1; k > 0; k--) {
	  seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
	}
  }

  void update(int k, const Monoid &x) {
	k += sz;
	seg[k] = x;
	while(k >>= 1) {
	  seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
	}
  }

  Monoid query(int a, int b) {
	Monoid L = M1, R = M1;
	for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
	  if(a & 1) L = f(L, seg[a++]);
	  if(b & 1) R = f(seg[--b], R);
	}
	return f(L, R);
  }

  Monoid operator[](const int &k) const {
	return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
	while(a < sz) {
	  Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
	  if(check(nxt)) a = 2 * a + type;
	  else M = nxt, a = 2 * a + 1 - type;
	}
	return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
	Monoid L = M1;
	if(a <= 0) {
	  if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
	  return -1;
	}
	int b = sz;
	for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
	  if(a & 1) {
		Monoid nxt = f(L, seg[a]);
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
	  if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
	  return -1;
	}
	int a = sz;
	for(b += sz; a < b; a >>= 1, b >>= 1) {
	  if(b & 1) {
		Monoid nxt = f(seg[--b], R);
		if(check(nxt)) return find_subtree(b, check, R, true);
		R = nxt;
	  }
	}
	return -1;
  }
};

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(int N, const F& f, const Monoid& M1) {
  return {N, f, M1};
}

void check(){
	int n ,q;
	cin >> n >> q ;
	n = 1<<n;
	auto sg = get_segment_tree(n ,[](const pair<ll ,bool> a ,const pair<ll ,bool> b){
			if(a.S) return MP(a.F ^ b.F ,!a.S);
			return MP(a.F | b.F ,!a.S);} , 
		MP(0LL ,0)) ;

	vector<ll> a(n + 1);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		sg.set(i ,MP(a[i] ,0));
	}
	
	sg.build() ;
	int p ; ll b;

	while(q--){
		cin >> p >> b;
		p--;
		sg.update(p ,MP(b ,0));
		// print(sg.seg);
		a[p] = b;
		cout << sg.seg[1].F <<'\n';
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
