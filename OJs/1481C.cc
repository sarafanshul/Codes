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
	ll n , m ;
	cin >> n >> m ;
	vector<ll> a(n) , b(n) , c(m) ;

	map<ll , vector<ll>> to ;

	for(ll &i : a)
		cin >> i ;
	for(ll i = 0 ; i < n ; i++){
		cin >> b[i] ;
		if( a[i] != b[i] )
			to[ b[i] ].PB( i ) ; 
	}
	for(ll&i : c)
		cin >> i ;

	ll last = -1 ;
	if( to[ c[m - 1] ].size() > 0 ){
		last = to[ c[m - 1] ].back() ;
		to[ c[m - 1] ].pop_back() ;
	}
	else {
		for(ll i = 0; i < n ;i++){
			if( b[i] == c[m - 1] ){
				last = i ;
				break ;
			}
		}
	}
	if( last == -1 ){
		cout << "NO\n" ;
		return ;
	}

	vector<ll> ans( m ) ;
	ans[ m - 1 ] = last ;

	for(ll i = 0 ; i < m - 1 ; i++){
		if( to[ c[i] ].size() == 0 )
			ans[ i ] = last ;
		else {
			ans[i] = to[ c[i] ].back() ;
			to[ c[i] ].pop_back() ;
		}
	}
	bool f = 1 ;
	for(ll i = 1 ; i <= n ; i++)
		f &= to[ i ].size() == 0 ;

	if( !f ){
		cout << "NO\n" ;
	}else {
		cout << "YES\n" ;
		for(ll i = 0 ; i < m ; i++)
			cout << ++ans[ i ] << " \n"[ i + 1 == m ] ;
	}

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
