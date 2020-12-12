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

	vector<ll> go(vector<ll> &a){
		ll n = a.size() ;
		vector<ll > res(n + 1 ,0);
		ll i = 0 ;
		while (i < n ){
			if(a[i] == 0){
				i++;
				continue ;
			}
			ll j = i;
			while (j < n && a[j] == 1) j++;

			for(ll l = 1 ; l <= j - i ; l++){
				res[ l ] += j - i - l + 1;
			}
			i = j;
		}
		return res ;
	}

	void check(){
		ll n ,m ,k;
		cin >> n >> m >> k;

		vector<ll> a(n) ,b(m);
		for(ll i = 0 ; i < n ; i++) cin >> a[i];
		for(ll i = 0 ; i < m ; i++) cin >> b[i];

		ll ans = 0 ;
		auto a1 = go( a );
		auto b1 = go( b );
		print(a1 ,b1);
		for(ll i = 1 ;i < a1.size() ; i++ ){
			if( k % i == 0 && k / i <= m ){
				ans += a1[i] * b1[k / i];
			}
		}
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
