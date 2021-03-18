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
	ll sm = 0 ;
	vector<ll> a(n) , O , T ;
	for(ll&i : a){
		cin >> i ;
		sm += i ;
	}
	for(ll i = 0 ; i < n ; i++){
		ll x ; cin >> x ;
		if( x == 2) T.PB( a[i] ) ;
		else O.PB( a[i] ) ;
	}
	
	if( sm < m ){
		cout << -1 << '\n' ;
		return ;
	}

	sort( T.rbegin() , T.rend() ) ;
	sort( O.rbegin() , O.rend() ) ;

	ll n1 = O.size() , n2 = T.size() ;
	ll ans = 1e18 ;

	sm = 0 ;
	for(ll&i : T)
		sm += i ;

	ll j = 0 ;
	for(ll i = n2 ; i >= 0 ; i--){
		while( j < n1 && sm < m ){
			sm += O[j] ;
			j++ ;
		}
		if(sm >= m){
			ans =  min(ans ,2 * i + j) ;
		}
		if( i > 0 ){
			sm -= T[i - 1] ;
		}
	}
	cout << ans << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
