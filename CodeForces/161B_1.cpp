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

pair<ll ,ll> ss[MAXN];
ll pen[MAXN] ,S = 0 ,P = 0;

void check(){
	ll n ,k ,mn = 1e10;
	cin >> n >> k;
	double sum = 0;
	for(ll i = 0 ; i < n ; i++){
		ll c ,t;
		cin >> c >> t;
		sum += c;
		if(t == 1) ss[S++] = {c ,i+1};
		else pen[P++] = i+1;
		mn = min(mn ,c);
	}
	sort(ss ,ss + S);
	reverse(ss ,ss + S);

	for(ll i = 0; i < min(k-1 , S) ; i++){
		sum -= 0.5 * ss[i].F;
	}
	if(k - 1 < S) sum -= 0.5*mn;

	cout<<fixed<<setprecision(1)<<sum<<'\n';

	for(ll i = 0 ;i < k - 1 ; i++){
		if(i < S) cout << 1 <<' '<< ss[i].S<<'\n';
		else cout << 1 << ' ' <<pen[--P]<<'\n';
	}
	if(k <= S){
		cout << S + 1 - k + P;
		for(ll i = k-1 ; i < S; ++i) cout<<' '<<ss[i].S;
	}else{
		cout << P;
	}
	for(ll i = 0 ; i < P ; i++) cout << ' '<< pen[i];
	cout << '\n';
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
