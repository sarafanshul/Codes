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
	ll n ;
	cin >> n ;
	vector<ll> a(n) ;
	multiset<ll , greater<ll>> mst ;

	for(ll &i : a){
		cin >> i ;
		mst.insert( i ) ;
	}

	vector<ll> ans ;
	function< void(ll , ll)> add = [&]( ll st , ll ed ) {
		// [st , end]
		for( ll i = st ; i <= ed ; i++)
			ans.PB( a[i] ) ;
	} ;

	ll j = n - 1 ;
	for( ll i = n - 1 ; i >= 0 ; i-- ){
		ll mx = *mst.begin() ;
		if( mx == a[i] ) {
			add( i , j ) ;
			j = i - 1 ;
		}
		mst.erase( mst.find( a[i] ) ) ;
	}

	for(ll &i : ans){
		cout << i << ' ';
	}
	cout << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
