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

const long long MAXN = 1e5 +7;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
template<class F>
ll ternSearch(ll a, ll b, F f) {
	assert(a <= b);
	while (b - a >= 5) {
		ll mid = (a + b) / 2;
		if (f(mid) < f(mid+1)) a = mid; // (A)
		else b = mid+1;
	}
	rep(i,a+1,b+1) if (f(a) < f(i)) a = i; // (B)
	return a;
}

void check(){
	ll n; 
	cin >> n ;
	vector<ll> a(n) ;
	map<ll ,ll> cnt ;
	for(ll &i : a){
		cin >> i ;
		cnt[i]++ ;
	}
	vector<ll> srt ;
	for(auto it : cnt){
		srt.PB( it.S ) ;
	}
	sort(ALL(srt)) ;

	ll F = srt.size() ;
	ll ans = n ;

	print(srt , F) ;

	for(ll i = 0 ; i < F ; i++){
		ans = min( ans , n - (F - i)*srt[i] ) ;
		print( i , srt[i]  ,(F - i)*srt[i] ,  n - (F - i)*srt[i] ) ;
	}
	cout << ans << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
