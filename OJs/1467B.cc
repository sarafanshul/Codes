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
	ll n;
	cin >> n ;
	vector<ll> a(n) ;
	for(ll&i : a)
		cin >> i ;

	vector<ll> now(n) ;

	auto get = [&]( ll idx) -> ll {
		ll ret = 0 ;
		if( idx <= 0 || idx >= n-1 ) return 0 ;
		assert( idx > 0 && idx < n - 1 ) ;
		ret += (a[idx] > a[idx + 1]) && (a[idx] > a[idx - 1]) ;
		ret += (a[idx] < a[idx + 1]) && (a[idx] < a[idx - 1]) ;
		return ret ;
	} ;

	ll sm = 0 ;
	for(ll i = 0 ; i  < n ; i++){
		now[i] = get( i ) ;
		sm += now[i] ;
	}

	ll ans = sm ;
	for(ll i = 0 ; i < n ; i++){
		set<ll> st ;
		for(ll j = max(i - 1 , 1LL) ; j <= min(i + 1 , n - 2) ; j++){
			st.insert( a[j] );
			st.insert( a[j] + 1 ) ;
			st.insert( a[j] - 1 ) ;
		}
		ll org = a[i] ;
		ll cur = sm - get( i - 1 ) - get( i ) - get( i + 1 );
		for(const auto val : st ){
			a[i] = val ;
			ans = min( ans , cur + get( i - 1 ) + get( i ) + get( i + 1 ) ) ;
		}
		print(ans , sm) ;
		a[i] = org ;
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
