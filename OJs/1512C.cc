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
using ld = long double ; // or double, if TL is tight
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
	ll A , B ;
	cin >> A >> B ;
	string  s ;
	cin >> s ;
	ll n = s.size() ;

	for(ll i = 0 ; i < n ; i++){
		if( s[i] == '1' ) B-- ;
		else if( s[i] == '0' ) A-- ;
	}

	for(ll i = 0 ; i < n / 2 ; i++){
		if( s[i] == '?' && s[n - i - 1] != '?' ){
			if( s[n - i - 1] == '0' )
				s[i] = '0' , A-- ;
			else s[i] = '1' , B-- ;
		}
		else if( s[ i ] != '?' && s[ n - i - 1]== '?' ){
			if( s[i] == '0' )
				s[ n - i - 1 ] = '0' , A-- ;
			else s[ n - i - 1 ] = '1' , B-- ;
		}
	}
	if( A < 0 || B < 0  ){
		cout << -1 <<'\n' ;
		return ;
	}
	for(ll i = 0 ; i <= n / 2 ; i++){
		if( s[i] == '?' && s[ n - i - 1] == '?' ){
			if( A >= B )
				s[i] = s[ n - i - 1] = '0' , A -= ( i != n - i - 1 ) + 1 ;
			else 
				s[i] = s[ n - i - 1] = '1' , B -= ( i != n - i - 1 ) + 1 ;
		}
	}

	function <bool(string) > ispalin = [ ](string x) -> bool {
		for( ll i = 0 ; i < x.size() / 2 ; i++) 
			if( x[i] != x[x.size() - i - 1] )
				return 0 ;
		return 1 ; 
	} ;

	if( A < 0 || B < 0 || ! ispalin( s ) ){
		cout << -1 <<'\n' ;
		return ;
	}
	cout << s << '\n' ;
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
