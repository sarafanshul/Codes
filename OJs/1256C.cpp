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
	ll n , m, d;
	cin >> n >> m >> d;
	vector<ll> c(m + 1);
	ll tot = 0 ;

	for(ll i = 1 ; i <= m ; i++){
		cin >> c[i];
		tot += c[i];
	}

	ll cur = 0 ;
	vector<ll> ans(n + 1) ;

	for(ll i = 1 ; i <= m ; i++){
		if(cur + d + tot > n + 1 ){
			for(ll j = cur + 1 ; j < cur + c[i] + 1 ; j++)
				ans[j] = i ;
			cur += c[i] , tot -= c[i]; 
		}else{
			for(ll j = cur + d ; j < cur + d + c[i] ; j++)
				ans[j] = i ;
			cur += d + c[i] - 1 ,tot -= c[i];
		}
	}
	if(cur + d >= n + 1){
		cout << "YES\n";
		for(ll i = 1 ; i <= n ; i++)
			cout << ans[i] << " \n"[i == n];
	}else{
		cout << "NO\n";
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
