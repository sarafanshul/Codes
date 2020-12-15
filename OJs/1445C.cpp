The idea is that ans will be largest divisor of p for which the following holds: for at least one prime divisor i of q, the exponent of i in ans will be less than that in q (so that q does not divide ans). My solution:


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

// Prime factorizes n in worst case O(sqrt n).
vector<pair<long long, long long>> prime_factorize(long long n) {
	assert(n >= 1);
	vector<pair<long long, long long>> result;
 
	for (long long p = 2; p * p <= n; p++)
		if (n % p == 0) {
			result.emplace_back(p, 0);
 
			do {
				n /= p;
				result.back().second++;
			} while (n % p == 0);
		}
 
	if (n > 1)
		result.emplace_back(n, 1);
 
	return result;
}

long long get_multiplicity(long long n, long long p) {
    long long m = 0;
 
    while (n % p == 0) {
        m++;
        n /= p;
    }
 
    return m;
}

void check(){
	#define int long long
	int p ,q;
	cin >> p >> q;
	auto prime_factors = prime_factorize(q);

	int best = 1;

	for(pair<int ,int> &pf : prime_factors){
		int a = pf.F;
		int mult = get_multiplicity(p ,a);
		int candidate = p;
		while(mult >= pf.S){
			candidate /= a;
			mult--;
		}
		best = max(best ,candidate);
	}
	cout << best <<"\n";
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
