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
	ll n ,k ;
	cin >> n >> k ;
	vector<ll > a( n ) ;
	map<ll ,set<ll>> pos ;

	for(ll i = 0 ; i < n; i++){
		cin >> a[i] ;
		pos[ a[i] ].insert( i ) ;
	}

	sort( ALL(a) ) ;

	auto idx = [&](ll v) -> ll {
		ll val = *pos[ v ].begin() ;
		pos[v].erase( pos[ v ].begin() ) ;
		return ++val ;
	} ;

	ll l , r ;
	for(ll i = 0 ; i + 2 < n ; i++){
		l = i + 1 ;
		r = n - 1 ;
		while( l < r ){
			if( a[i] + a[l] + a[r] == k ){
				cout << idx(a[l]) <<' ' << idx(a[r]) << ' ' << idx(a[i]) << '\n' ;
				return ;
			}
			else if ( a[i] + a[l] + a[r] < k ) l++ ;
			else r-- ;
		}
	}
	
	cout << "IMPOSSIBLE\n" ;
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
