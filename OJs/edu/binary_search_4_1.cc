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

void check(){
	ll n , d ;
	cin >> n >> d ;
	vector<ll> a(n) ;
	for(ll &i : a)
		cin >> i; 
	
	vector<ll> pre( n + 1 , 0) ;
	for(ll i = 0 ; i < n ; i++)
		pre[i + 1] = pre[i] + a[i] ;

	ll L , R ;
	auto can = [&]( ld x ) -> bool {
		bool ret = 0;
		pair<ld , ll> best = MP( 1000 , -1 ) ;
		for( ll i = d ; i <= n ; i++){
			ld t = pre[i - d] - (i - d)*x ;
			best = min( best , MP( t , i - d ) ) ;
			ld c = pre[i] - i*x ;
			ret |= c >= best.F ;
			if( c >= best.F ) L = best.S , R = i ;
		}
		return ret ;
	} ;

	ld l = 0 , r = 107 , m ;
	for(ll i = 0 ; i < 100 ; i++){
		m = (l + r) / 2 ;
		if( can( m ) ) l = m ;
		else r = m ;
	}
	print(r , L , R) ;
	cout << ++L << " " << R ;
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
