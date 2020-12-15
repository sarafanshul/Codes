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
	ll n ,sm = 0;
	cin >> n;
	vector<ll> a(n);
	for(ll& i : a){ 
		cin >> i;
		sm += i ;
	}

	auto can = [&](ll ln) -> bool {
		if(sm != ln*(sm/ln))return 0; // vaules need to be whole
		vector<ll > b(n ,0);
		ll to = sm / ln , j = 0;

		for(ll i = 0 ; i < ln ; i++){
			while(j < n && b[i] < to) b[i] += a[j] ,j++;
		}
		bool f = 1;
		// print(ln ,b ,to);
		for(ll i = 0 ; i < ln ; i++){
			f &= (b[i] == to) ;
		}
		return f; 
	};

	for(int i = n ; i >= 1 ; i--){
		if (can(i)){
			cout << n-i << '\n';
			return ;
		}
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
