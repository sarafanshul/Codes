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

vector<ll> D , a(MAXN);
ll n ;

void go( ll l  , ll r  , ll dt){
	if ( l > r) return ;
	ll mx = distance( a.begin() , max_element(a.begin() + l , a.begin() + r + 1) ) ;
	D[ a[mx] ] = dt + 1 ;
	print( l , r , mx , dt + 1 ) ;
	go( l , mx - 1 , dt + 1) ;
	go( mx + 1 , r , dt + 1) ;
}

void check(){
	cin >> n;
	D.assign( n+1 , -1 ) ;
 	for(ll i = 0 ; i < n ; i++)
 		cin >> a[i] ;

	go( 0 , n-1 , -1);

	for(ll i = 0 ; i < n ; i++ )
		cout << D[ a[i] ] << " \n"[i == n-1] ; 
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
