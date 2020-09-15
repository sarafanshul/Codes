/*
We can think about the problem as follows: 
	we want to order the ai to create the longest possible 
	nonnegative prefix of pn,pn−1,…,p1 
		(in other words, the smallest possible 
		k such that pn≥0,pn−1≥0,…,pk≥0).

Notice that pn=a1+⋯+an is fixed. 
We can also see pn−1=pn−an, pn−2=pn−an−an−1, etc. 
So we should make an as small as possible (assuming it is unlocked), 
then an−1, and so on. 
In other words the unlocked ai should be sorted in decreasing order from left to right. 
To prove this, you can use an exchange argument: 
	if you consider an arrangement of the ai where two consecutive unlocked 
	values are not in decreasing order, we can swap them with each other. 
	This swap does not make any of the pi smaller (it can only make some pi bigger). 
	Thus we can start with the optimal ordering and repeatedly apply swaps until 
	the unlocked values are sorted, without making anything worse.
// by neal
*/
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

const size_t MAXN = 1e3 +7;

void check(){
	ll n ;
	cin >> n;
	vector< ll > a(n) ,l(n) ,v;v.reserve(MAXN);
	for(int i = 0; i < n ;i++) cin >>a[i];
	for(int i = 0; i < n ;i++) cin >>l[i];

	for(int i = 0; i < n ;i++) if(! l[i]) v.PB(a[i]);

	sort(ALL(v));reverse(ALL(v));
	ll idx = 0;
	for(ll i = 0; i < n ;i++)
		if(! l[i]) a[i] = v[idx++];

	for(int i = 0; i < n ;i++) cout << a[i]<<" ";
	cout << "\n";
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
