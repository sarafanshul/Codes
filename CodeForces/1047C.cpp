#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

const long long MAXN = 1e6 +7;
const long long M = 1.5e7;

ll n ,mindiv[M] ,a[MAXN] ,p[MAXN] ,tot ,num[M] ,g ,dat;

void pre(){
	for(ll i = 2 ; i < M ;i++){
		if(!mindiv[i])mindiv[i] = p[++tot] = i;
		for(ll j = 1 ,y ;( j <= tot && p[j] <= mindiv[i] && (y = p[j]*i) < M) ; j++){
			mindiv[y] = p[j];
		}
	}
}

void check(){
	cin >> n;
	for(ll i = 0 ; i < n ;i++) cin >> a[i] ,g = g?(__gcd(g ,a[i])):a[i];
	for(ll i = 0 ;i < n ;i++) a[i] /= g;
	
	for(ll i = 0 ; i < n; i++){
		while(a[i] != 1){
			ll pp = mindiv[a[i]];
			num[pp]++;
			while(a[i]%pp == 0) a[i] /= pp;
		}
	}
	
	ll ans = 0;
	for(ll i = 0 ;i <= tot ; i++) ans = max(ans ,num[p[i]]);
	cout << (ans ? n- ans : -1);
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;
	
	pre();	
	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
