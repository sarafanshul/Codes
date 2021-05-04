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
using db = long double ; // or double, if TL is tight
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

void check(){
	string s; 
	cin >> s ;
	ll n = s.size() ;
	ar<ll , 3> a{ } ;
	for(ll i = 0 ; i < n ; i++){
		if( s[i] == 'B' ) a[0]++ ;
		else if( s[i] == 'S' ) a[1]++ ;
		else a[2]++ ;
	}
	ll nb , ns , nc ;
	cin >> nb >> ns >> nc ;

	ll pb , ps , pc , cost;
	cin >> pb >> ps >> pc  >> cost ;

	auto total = [&] (ll c) -> ll {
		ll br = max(0LL ,a[0]*c - nb);
		ll sc = max(0LL ,a[1]*c - ns);
		ll ch = max(0LL ,a[2]*c - nc);
 
		ll pr = br*pb + sc*ps + ch*pc;
		return pr;
	} ;

	ll l = 0 , r = cost + 1e5 , m ;

	while( l + 1 < r ){
		m = (l + r) / 2;
		ll tot = total( m ) ;
		if( tot == cost ) {l = m ; break ;}
		else if( tot > cost ) r = m ;
		else l = m ;
	}

	cout << l ;

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
