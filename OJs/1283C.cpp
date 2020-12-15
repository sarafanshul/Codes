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
	vector<ll> a(n + 1) ,b;
	set<ll> st ,st1;
	
	for(ll i = 1 ; i <= n ; i++) {
		st.insert(i);
		st1.insert(i);
	}

	for(ll i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] == 0) continue ;
		st.erase(st.find(a[i]));
		st1.erase(st1.find(a[i]));
	}
	b = a;

	for(ll i = 1 ; i <= n ; i++){
		if(a[i] != 0) continue ;
		if(i == *st.begin()){
			a[i] = *st.rbegin();
			st.erase(*st.rbegin());
		}else{
			a[i] = *st.begin();
			st.erase(st.begin());
		}
	}
	for(ll i = n ; i > 0 ; i--){
		if(b[i] != 0) continue ;
		if(i == *st1.begin()){
			b[i] = *st1.rbegin();
			st1.erase(*st1.rbegin());
		}else{
			b[i] = *st1.begin();
			st1.erase(st1.begin());
		}
	}
	
	for(ll i = 1 ; i <= n ; i++){
		if(a[i] == i){
			a = b ;
			break ;
		}
	}

	for(ll i = 1 ; i <= n ; i++) 
		cout << a[i] <<' ';
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
