#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace __gnu_pbds;
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

typedef tree<
	pair<ll ,ll> , // Key type
	null_type, // Mapped-policy
	less<pair<ll ,ll> >, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> // A policy for updating node invariants
ordered_set;

const long long MAXN = 1e5 +7;

void check(){
	ll n;
	cin >> n;
	ordered_set l ,r ;
	ll x , y ;
	vector<pair<ll ,ll>> a(n) ;
	for(ll i = 0 ; i < n ; i++){
		cin >> x >> y;
		l.insert({x , i}) ;
		r.insert({y , i}) ;
		a[i] = {x , y} ;
	}

	auto get = [&](ll i) -> ll {
		ll less_l_r = r.order_of_key( {a[i].F ,-1} );
		// for comparing use large number for second if we need upper bound ;
		ll greater_r_l = n - l.order_of_key( {a[i].S ,(ll)1e18} );
		print(a[i] ,less_l_r ,greater_r_l ) ;
		return less_l_r + greater_r_l ;
	}; 

	ll ans = 1e10 ; 
	for(ll i = 0 ; i < n ; i++){
		ll cnt = get( i ) ;
		ans = min(cnt ,ans );
	}
	cout << ans <<'\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
