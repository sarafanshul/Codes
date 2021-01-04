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

ll modInverse(ll a, ll m)  { 
	ll m0 = m; 
	ll y = 0, x = 1; 
	if (m == 1)  return 0; 
	while (a > 1) { 
		ll q = a / m; 
		ll t = m; 
 		m = a % m, a = t; 
		t = y; 
		y = x - q * y; 
		x = t; 
	} 
	if (x < 0)  x += m0; 
	return x; 
} 

void check(){
	ll n , s , k ;
	cin >> n >> s >> k ;
	ll g = gcd( k , n ) ;
	if( (n - s) % g )
		cout << "-1\n" ;
	else {
		n /= g , k /= g , s /= g; 
		ll x = modInverse( k , n );
		cout << x * ( n - s )%n <<'\n';
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
