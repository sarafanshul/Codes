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

set<ll> st; 
ll op = 0;
void go(ll n ,vector<bool> v ,ll num ){
	op++;
	if(op > 1e6)return ;
	if(n == 0){
		// print(num);
		st.insert( num) ;
		return ;
	}
	for(ll i = 1 ; i < 10 ; i++){
		if(v[i]) continue ;
		if(n >= i){
			v[i] = 1;
			go(n - i ,v , num*10 + i );
			v[i] = 0;
		}
	}
}
map<ll ,ll> ans ;

void check(){
	ll n;
	cin >> n;
	if(n > 45){
		cout << "-1\n";
		return;
	}
	if(ans.count(n)){
	    cout << ans[n] <<'\n';
	    return ;
	}
	st.clear() ;
	vector<bool> v(10 ,0);
	op  = 0 ;
	go(n ,v ,0);
    
	if(st.size()) {
	    cout << *st.begin() <<'\n';
	    ans[n] = *st.begin() ;
	}
	else {
	    cout << -1 <<'\n';
	    ans[n] = -1;
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