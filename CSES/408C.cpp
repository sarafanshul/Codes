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

const long long MAXN = 1e5 +7;

ll sq[MAXN] = {0};

void check(){
	ll a ,b;
	cin >> a >> b;
	
	for(ll i = 1; i < 1001 ;i++) sq[i] = i*i;

	ll c = a*a + b*b;
	vector<pair<ll ,ll>> sq_a ,sq_b ,sq_c;

	for(ll i = 1; i < 1001 ;i++){
		for(ll j = 1 ;j < 1001 ;j++){
			ll tp = sq[i] + sq[j];
			if(tp == a*a)sq_a.PB({i ,j}) ,sq_a.PB({-i ,-j}) ,sq_a.PB({i ,-j}) ,sq_a.PB({-i ,j});
			if(tp == b*b)sq_b.PB({i ,j}) ,sq_b.PB({-i ,-j}) ,sq_b.PB({i ,-j}) ,sq_b.PB({-i ,j});
// 			if(tp == c) sq_c.PB({i ,j}) ,sq_c.PB({-i ,-j});
			
		}
	}
// 	cout << sq_a<<"\n"<<sq_b<<"\n";
	for(auto &pa : sq_a){
		for(auto &pb : sq_b){
			ll d = (pa.F - pb.F)*(pa.F - pb.F) + (pa.S - pb.S)*(pa.S - pb.S);
// 			cout << MP(pa ,pb) << d <<"\n";
			if(c == d && (pa.F != pb.F && pa.S != pb.S)){
				cout << "YES\n0 0\n";
				cout << pa.F <<" "<<pa.S<<"\n";
				cout << pb.F <<" "<<pb.S<<"\n";
				return;
			}
		}
	}
	cout << "NO";
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
