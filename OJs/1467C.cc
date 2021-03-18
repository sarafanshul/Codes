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
	ll n[3] ;
	cin >> n[0] >> n[1] >> n[2] ;
	vector<vector<ll>> bags(3) ;

	for(ll i = 0 ; i < 3 ; i++){
		for(ll j = 0 ; j < n[i] ; j++){
			ll x ; cin >> x ; bags[i].PB( x ) ;
		}
		sort(ALL(bags[i])) ;
	}

	ll best = -1e18 ;

	for(ll i = 0 ; i < 3 ; i++){
		ll sm = 0 ; 
		for(ll b = 0 ; b < 3 ; b++){
			for(ll &v : bags[b])
				sm += ( b == i ? -1 : 1 )*v ;
		}
		best = max( best , sm ) ;
	}

	for(ll x = 0 ; x < 3 ; x++){
		for(ll y = x + 1 ; y < 3 ; y++){
			ll sm = 0 ;

			for(ll b = 0 ; b < 3 ; b++)
				for(ll&v : bags[b])
					sm += v ;

			sm -= 2* ( bags[x].front() + bags[y].front() ) ;
			best = max( best , sm ) ;
		}
	}
	cout << best << '\n' ;

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
