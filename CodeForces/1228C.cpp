/*
* Basically we need to prime factorize x. And iterate on them.
* For each prime pi we need the contribution of pi, pi**2, pi**3...
* to numbers in [1, n] . Number of multiple of pi will give how many times pi has contributed.
* Eg: 1-30 p = 2:
* 2^1 contributes: (2^1)^(30/2)
* 2^2 contributes: (2^2)^(30/2^2): But they are already once counted with 2^1
* So the total contribution of above two is: (2^1)^(30/2)*(2^1)^(30/20^2)
* similary for 3rd power. Therefore, net contri = (2^1)^(30/2)*(2^1)^(30/20^2)*(2^1)^(30/2^3)
* similarly for 4th, therefore net: (2^1)^(30/2)*(2^1)^(30/20^2)*(2^1)^(30/2^3)*(2^1)^(30/2^4)
*/
 
/*
* Proof: Say contri of p^(i-1) = (n/p^(i-1)) ---->c1
* contri of p^(i) = n/(p^i). But that has contri of
* p^(i-1) too. Net contri of p^(i-1) = (n/p^(i-1))-(n/p^(i))---->c2
* Therefore the result for them both can be written as
* (p^(i-1))^(c1))*(p^i)^c2 == p^((i-1)*(n/p^(i-1)) * p^((i-1)*n/p^(i))
* This is valid for all i
*/

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
const ll MOD = 1e9 + 7;

template<typename T = long long >
T fastExpo(T a, T n) {
	T ans = 1;
	while(n >= 1) {
		if(n % 2 == 0) { a = (1LL * a * a) % MOD; n /= 2; }
		else { ans = (1LL * ans * a) % MOD; n--; }
	}
	return ans;
}

void check(){
	ll x ,n ,ans = 1;
	cin >> x >> n;

	auto cal = [&] (ll p){
		for(ll i = 1 , s = 1 ; n/s >= p ; i++){
			s *= p;
			ans = 1LL*ans*fastExpo(p ,n/s)%MOD;
		}
	};

	for(ll i = 2 ; i*i <= x ; i++){
		if(x % i == 0){
			cal(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) cal(x);

	cout << ans <<'\n';
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
