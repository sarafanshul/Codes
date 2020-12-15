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
	unordered_map<ll ,vector<pair<ll ,ll> >> mp;
	cin >> n;

	ll a[n];
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll x = 0;
		for(ll j = i ; j >= 0; j--){
			x += a[j];
			mp[x].PB(MP( j ,i ));
		}
	}
	ll mx = 0;
	vector<pair<ll ,ll>> out;
	for(auto  it : mp){
		// print(it.F ,it.S);
		vector<pair<ll ,ll> > ans;
		for(const auto &v : it.S){
			if(ans.size()){
				if(ans.back().S >= v.F) continue;
				ans.PB(v);
			}else{
				ans.PB(v);
			}
		}
		if(ans.size() > mx){
			out = ans;
			mx = ans.size();
		}
		print(it.F ,ans);
	}
	print();
	cout << mx<<'\n';
	for(const auto &pi: out){
		cout << pi.F + 1 <<' '<<pi.S+1<<'\n';
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
