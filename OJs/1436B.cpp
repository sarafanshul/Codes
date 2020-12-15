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


template<long long SZ> struct Sieve {
        bitset<SZ> pri;
        vector<long long> pr;
        Sieve() {
                pri.set();
                pri[0] = pri[1] = 0;
                for (int i = 4; i < SZ; i += 2) {
                        pri[i] = 0;
                }
                for (int i = 3; i * i < SZ; i += 2) {
                        if (pri[i]) {
                                for (int j = i * i; j < SZ; j += 2 * i) {
                                        pri[j] = 0;
                                }
                        }
                }
                for (int i = 0; i < SZ; i++) {
                        if (pri[i]) {
                                pr.push_back(i);
                        }
                }
        }
};


int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	Sieve<MAXN> Si;
	for(int i = 1 ; i <= t ;i++){
		// (n-1) + x = prime;
		ll n;
		cin >> n;
		ll x = 0;
		for(ll i = 0; i < MAXN ;i++){
			if(n-1 +i == 1)continue;
			if(Si.pri[i]) continue;
			if(Si.pri[n-1 + i]) {x = i;break;}
		}
		for(ll i = 0 ;i < n ;i++){
			for(ll j = 0 ;j < n ;j++){
				if(j == i) cout << x <<" ";
				else cout << "1 ";
			}
			cout <<"\n";
		}
		
	}
	return 0;
}
