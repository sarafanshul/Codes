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

ll get(ll x){
	ll ret = 0;
	while(x){
		ret += x%10;
		x /= 10;
	}
	return ret; 
}
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
	ll a ,b ,c;
	vector<ll > ans;
	cin >> a >> b >> c;

	for(ll sx = 1 ; sx <= 81 ; sx++){
		ll x = b*fastExpo(sx ,a) + c;
		if( x > 0 && x < 1e9 && get(x) == sx) ans.PB(x);
	}
	cout << ans.size()<<'\n';
	for(ll &i :ans) cout << i <<' ';
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
