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

const long long MAXN = 1e5 +7;

void check(){
	ll n , m ;
	cin >> n >> m ;
	vector<ll> A(m) , B(m) ;

	for(ll i = 0 ; i < m ; i++){
		cin >> A[i] >> B[i] ;
		A[i]-- , B[i]-- ;
	}
	ll k ;
	cin >> k ;
	vector<ll> C(k) , D(k) ;

	for(ll i = 0 ; i < k ; i++){
		cin >> C[i] >> D[i] ;
		C[i]-- , D[i]-- ;
	}

	ll ans = 0 ;

	for(ll i = 0 ; i < ( 1 << k ) ; i++){
		vector<ll> x(n , 0) ;
		for(ll j = 0 ; j < k ; j++){
			if( i >> j & 1 )
				x[ C[j] ]++ ;
			else 
				x[ D[j] ]++ ;
		}
		ll cnt = 0 ;
		for(ll j = 0 ; j < m ; j++){
			if( x[ A[j] ] && x[ B[j] ] )
				cnt++ ;
		}
		ans = max( ans , cnt ) ;
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
