// This solution is unfeasible in terms of both time and memory. However, the following observation makes it an Accepted solution: there are only 491 values of j that we have to consider, which are d-245,d-244,?d-243,...,d+244 and d+245.

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

const size_t MAXN = 30007;
ll n ,m ,dp[MAXN][250*2] ,d;
bool vis[MAXN][250*2] = {} ;
ll gem[MAXN] = {};


template<typename T = ll>
T go(T frm ,T jmp){
	ll j = jmp - (d-250);
	if(frm >= MAXN) return 0;
	if(vis[frm][j]) return dp[frm][j];
	vis[frm][j] = 1;
	ll res;
	if(jmp == 1){
		res = gem[frm] + max(go(frm+jmp ,jmp) ,go(frm+jmp+1 ,jmp+1));
	} else{
		res = gem[frm] + max({go(frm+jmp-1 ,jmp-1) ,go(frm+jmp ,jmp) ,
				go(frm+jmp+1 ,jmp+1)});
	}
	dp[frm][j] = res;
	return res;
}

void check(){
	cin >> n >> d;
	ll t;
	for(int i = 0; i < n ;i++){
		cin >> t;
		gem[t]++;
	}
	cout << go(d ,d);
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
