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
	ll k ,n;
	cin >> n >> k;
	ll l = 0 ,r = n+1 ,m ,ans = 1e10;

	ll pwk[100];
	pwk[0] = 1;
	for(ll i = 1 ; i < 100 ; i++){
		pwk[i] = pwk[i-1] * k;
	}

	auto get = [&](ll v) -> ll {
		ll ret = 0 ,i = 0;
		while(1){
			if(v / pwk[i] == 0)break;
			ret += v / pwk[i];
			i++;
		}
		return ret;
	};

	while(l < r){
		m = (l + r)/ 2;
		ll x = get(m);
		if(x >= n){
			ans = min(m ,ans);
			r = m;
		}else {
			l = m + 1;
		}
	}
	cout << ans;
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
