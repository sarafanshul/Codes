#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
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
	ll n , m;
	cin >> n >> m;
	vector<vector<ll>> pre(n + 2 , vector<ll>(m + 2 , 0)) ;
	bool a[n + 2][m + 2];
	for(ll i = 1 ; i <= n ; i++){
		string s ;
		cin >> s;
		for(ll j = 1 ; j <= m ; j++)
			a[i][j] = s[j - 1] - '0' ;
	}

	ll q;
	cin >> q;
	ll x1 , y1 , x2 , y2 ;
	for(ll i = 0 ; i < q ; i++){
		cin >> x1 >> y1 >> x2 >> y2 ;
		pre[ x1 ][ y1 ]++ ; 
		pre[ x2 + 1 ][y1]-- ;
		pre[ x1 ][ y2 + 1 ]-- ;
		pre[ x2 + 1 ][ y2 + 1]++ ;
	}

	for(ll i = 1 ; i <= n+1 ; i++ ){
		for(ll j = 1 ; j <= m + 1 ; j++){
			pre[ i ][ j ] += pre[ i - 1 ][ j ] ; 
		}
	}
	for(ll i = 1 ; i <= n+1 ; i++ ){
		for(ll j = 1 ; j <= m + 1 ; j++){
			pre[ i ][ j ] += pre[ i ][ j - 1  ] ;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++ ){
		for(ll j = 1 ; j <= m ; j++){
			if( pre[i][j] % 2 ) a[i][j] ^= 1 ;
			cout << a[i][j] ;
		}
		cout << '\n';
	}
	
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
