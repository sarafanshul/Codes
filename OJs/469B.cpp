#pragma GCC optimize("Ofast")  
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

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const size_t MAXN = 1e5 +7;
template<typename T = ll>
inline bool can(T a ,T b ,T c ,T d){
    if(c <= a && d >= b ) return 1;
	if(c <= a && d <= b && d >= a) return 1;
	if(c >= a && d <= b) return 1;
	if(c >= a && d >= b && c <= b) return 1;
	return 0;
}

void check(){
	ll p ,q ,l ,r;
	cin >> p >> q >> l >> r;
	vector<pair<ll ,ll>> pa(p) ,qa(q);
	for(int i = 0; i < p ;i++) cin >> pa[i].F >> pa[i].S;
	for(int i = 0; i < q ;i++) cin >> qa[i].F >> qa[i].S;
	ll ans = 0;
	bool vis[1009] = {0};
	for(pair<ll ,ll>& pi : pa){
		for(pair<ll ,ll>& qi : qa){
			for(int i = l ;i <= r ;i++){
				if(can(pi.F ,pi.S ,qi.F+i ,qi.S+i)) vis[i] = 1;
			}
		}
	}
    for(int i = 0; i < 1009 ; i++) if(vis[i]) ans++;
	cout << ans;    
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
