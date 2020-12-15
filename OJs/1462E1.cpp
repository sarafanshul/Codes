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

const long long MAXN = 2e5 +7;

using mod_int = long long  ;


mod_int go(vector<ll>& cnt , ll n ,ll m ,ll k){
	vector<ll> prefix(n + 1 ,0);
	for(ll i = 0 ; i < n ; i++){
		prefix[i + 1] = prefix[i] + cnt[i] ;
	}
	mod_int ret = 0;
	for(ll i = -k ; i < n ; i++){
		ll count = prefix[ min(i + k + 1 ,n) ] - prefix[max(i ,0LL)];
		ret += count * (count - 1) * (count - 2) / 6;
	}
	return ret ;
}

void check(){
	ll n ,m = 3 ,k = 2;
	cin >> n;
	vector<ll> a(n) ,cnt(n ,0); 
	for(ll&i : a){
		cin >> i;
		i--;
		cnt[i]++;
	}
	mod_int ans = go( cnt ,n ,m ,k ) - go(cnt , n ,m ,k-1);
	cout << ans << '\n';
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
