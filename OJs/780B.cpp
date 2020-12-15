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
	ll n;
	cin >> n;
	ll a[n + 1] ,sp[n + 1];
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin >> sp[i];
	}

	auto get = [&] (double x) -> bool {
		double mn = 1e10;
		double mx = -1e10;
		for(ll i = 0 ; i < n ; i++){
			mn = min(mn , a[i] + sp[i]*x);
			mx = max(mx , a[i] - sp[i]*x);
		}
		return mn <= mx;
	};
	double l = 0 , r = 1e10;
	double m ;
	for(ll t = 0 ; t < 100 ; t++){
		m = (l + r) / 2;
		if(get(m)){
			l = m;
		}else{
			r = m;
		}
	}
	cout << fixed << setprecision(6) << m <<'\n' ;
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
