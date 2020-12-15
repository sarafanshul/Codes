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


template<long long SZ> struct Sieve {
	bitset<SZ> pri; vector<long long> pr;
	Sieve() {
		pri.set(); pri[0] = pri[1] = 0;
		for (int i = 4; i < SZ; i += 2) { pri[i] = 0; }
		for (int i = 3; i * i < SZ; i += 2) { if (pri[i]) { for (int j = i * i; j < SZ; j += 2 * i) { pri[j] = 0; } } }
		for (int i = 2; i < SZ; i++) { if (pri[i]) { pr.push_back(i); } }
	}
};

void check(){
	Sieve<MAXN> Si;
	string s;
	cin >> s;
	ll cnt[100] = {0} ,m = 0 ,n = s.size();
	for(char i : s){
		cnt[i - 'a']++;
	}
	for(ll i = 0 ; i < 30 ; i++) if(cnt[i] > cnt[m]) m = i;

	char t[1001] ;	t[n] = 0;
	ll q = 0;
	for(ll i = 1 ; i <= n ;i++){
		if(i == 1 || (i > n/2 && Si.pri[i])){
			// first letter which is not max
			while(q < 26 && (cnt[q] == 0 || q == m))q++;
			
			if(q == 26){
				cnt[m]--;
				t[i-1] = m + 'a';
			}else {
				cnt[q]--;
				t[i-1] = q + 'a';
			}
		}else {
			if(cnt[m] == 0){cout << "NO\n";return;}
			else{
				cnt[m]--;
				t[i-1] = m + 'a';
			}
		}
	}
	cout << "YES\n" <<t;

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
