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
	vector<ll> X[2] ;
	ll n;
	cin >> n;
	vector<ll> a(2*n);
	for(ll i = 0 ; i < 2*n ; i++ ){
		cin >> a[i] ;
		X[ a[i]%2 ].PB( i ) ;
	}
	n-- ;
	ll i = 0 , j = 0 ;
	while(n){
		n-- ;
		if( i + 1 < X[0].size() ){
			cout << X[0][i++] + 1 <<' '<< X[0][i++] + 1 <<'\n';
		}
		else if( j + 1 < X[1].size() ){
			cout << X[1][j++] + 1 <<' '<< X[1][j++] + 1 <<'\n';	
		}
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
