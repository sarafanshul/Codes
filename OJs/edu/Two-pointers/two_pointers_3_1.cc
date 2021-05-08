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

template<typename T = long long >
inline T __ceil(T a ,T b){return (a + b - 1)/b;}

void check(){
	ll n , P ;
	cin >> n >> P ;
	vector<ll> a( 2 * n ) ;
	ll sm = 0 ;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i] ;
		a[n + i] = a[i] ;
		sm += a[i];
	}

	ll cycles = __ceil( P , sm ) ;
	cycles = max( 0LL , cycles - 1 ) ;
	P -= cycles * sm ;
	ll ans = 1e18 , l = 0, idx = 0 ;
	ll cur = 0 ;

	for(ll i = 0 ; i < 2*n ; i++){
		cur += a[i] ;
		while( l < n && cur - a[l] >= P ) cur -= a[l++] ;

		if( cur >= P && ans > ( i - l + 1 ) ){
			ans = i - l + 1 ;
			idx = l + 1 ;
		}
	}

	ans += cycles * n ;
	cout << idx << ' ' << ans ;

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
