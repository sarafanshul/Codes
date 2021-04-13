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
	vector<ll> a(3) ;
	cin >> a[0] >> a[1] >> a[2] ;
	vector<ll> idx({ 0 , 1 , 2 , 0 , 2 , 1 , 0 }) ;
	ll full = min( { a[0] / 3 , a[1] / 2 , a[2] / 2 } ) ;
	a[0] -= full * 3 ;
	a[1] -= full * 2 ;
	a[2] -= full * 2 ; 
	ll ans = 0 ;
	for(ll st = 0 ;st < 7 ; st++){
		ll dy = st ;
		auto b = a ;
		ll cur = 0;
		while( b[ idx[dy] ] > 0 ){
			--b[ idx[dy] ] ;
			dy = (dy + 1) % 7 ;
			++cur ;
		}
		ans = max( ans , full*7 + cur ) ;
	}
	cout << ans << '\n';
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
