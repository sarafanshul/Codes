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

const long long MAXN = 2e6 + 7;

inline ll sum_AP( ll a , ll n ){ return ( n ) * ( 2*a + (n - 1)) / 2 ; }

void check(){
	ll n ;
	cin >> n ;
	ll ans = 0 ;

	for(ll len = 1 ; len <= MAXN ; len++ ){
		
		ll low = 1 , high = n , mid ;
		while( low <= high ){
			mid = ( low + high ) / 2 ;
			ll Sn = sum_AP( mid , len ) ;
			if( Sn == n ){
				ans += 2 ;
				break ;
			}else if ( Sn < n )	
				low = mid + 1 ;
			else 
				high = mid - 1;
		}
	}

	cout << ans << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
