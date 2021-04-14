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
const long long MAXN = 5e6 +7;

ar<bool ,MAXN> v { } ;
ar< pair<ll ,ll> , MAXN > mp ;

void check(){
	ll n;
	cin >> n ;
	vector<ll> a( n ) ;
	for(ll &i : a)
		cin >> i ;

	for( ll i = 0 ; i < n ; i++ ){
		for( ll j = 0 ; j < i ;j++ ){
			ll sm = a[i] + a[j] ;
			if( !v[ sm ] ){
				v[ sm ] = 1 ; mp[ sm ] = { i , j } ;
			}else{
				if( j == mp[ sm ].F || i == mp[ sm ].S || i == mp[ sm ].F || j == mp[ sm ].S ) continue ;
				cout << "YES\n" ;
				cout << mp[ sm ].F + 1 << ' ' << mp[ sm ].S + 1 << ' '<< i + 1 << ' ' << j + 1 << '\n' ;
				return ;
			}
		}
	}
	cout << "NO\n" ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
