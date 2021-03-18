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

const long long MAXN = 2e5 +7;

template<long long SZ> struct Sieve {
	bitset<SZ> is_prime;
	vector<long long> primes;
	Sieve() {
		is_prime.set();
		is_prime[0] = is_prime[1] = 0;
		for (int i = 4; i < SZ; i += 2) { is_prime[i] = 0; }
		for (int i = 3; i * i < SZ; i += 2) {
			if (is_prime[i]) {
				for (int j = i * i; j < SZ; j += 2 * i) { is_prime[j] = 0; }
			}
		}
		for (int i = 0; i < SZ; i++) { if (is_prime[i]) { primes.push_back(i); } }
	}
};

void check(Sieve<MAXN> &S){
	ll d;
	cin >> d ;
	ll p = *lower_bound( ALL(S.primes) , d + 1 ) ;
	ll q = *lower_bound( ALL(S.primes) , p + d ) ;
	cout << min( p * p * p , p * q ) <<'\n'; 
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	Sieve<MAXN> S ;
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check( S ); }
	return 0;
}
