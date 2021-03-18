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

const long long MAXN = 2e5 +7;

void check(){
	ll n ,m ;
	cin >> n >> m; 
	vector<ll> a( n ) , pos( n ) ;
	for(ll&i : a)
		cin >> i , i-- ;

	for(ll i = 0 ; i < n ; i++)
		pos[ a[i] ] = i ;

	ll ans = 1 ;
	for(ll i = 1 ; i < n ; i++)
		ans += ( pos[i] < pos[i - 1] ) ;

	set<pair<ll ,ll>> st ;

	auto add = [&](ll i ) { 
		if( a[i] > 0 )
			st.insert( { a[i] - 1 , a[i] } ) ;
		if( a[i] < n - 1 ) 
			st.insert( { a[i] , a[i] + 1 } ) ;
	} ;

	while( m-- ){
		ll i ,j ; cin >> i >> j ; i-- , j-- ;
		add(i) ; add(j) ;

		ll lst = 0 , nw = 0 ;
		for(const auto &[ x0 , x1 ] : st)
			lst += pos[ x1 ] < pos[ x0 ] ;
		
		swap( a[i] , a[j] ) ; swap( pos[ a[i] ] , pos[ a[j] ] ) ;

		for(const auto &[ x0 , x1 ] : st)
			nw += pos[ x1 ] < pos[ x0 ] ;

		print( "VAL" , ans , lst , nw ) ;
		ans = ans - lst + nw ;
		cout << ans << '\n' ;
		st.clear() ;
	}
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
