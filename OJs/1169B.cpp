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

const long long MAXN = 3e5 +7;
ll a[MAXN] ,b[MAXN];
ll n ,m;

bool ok(ll x ,ll y){
	for(ll i = 0 ; i < m ; i++){
		if( a[i] == x || a[i] == y || b[i] == x || b[i] == y) continue;
		if(y == -1){
			return ok(x ,a[i]) || ok(x ,b[i]);
		}
		else return false;
	}
	return true;
}

void check(){
	cin >> n >> m;
	for(ll i = 0 ; i < m ; i++){
		cin >> a[i] >> b[i];
	}	
	if( ok( a[0] ,-1 ) || ok( b[0] ,-1 ) ){
		cout << "YES\n"; return ;
	}
	cout << "NO\n";
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
