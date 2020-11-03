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

const long long MAXN = 2e6 +7;
std::vector<ll> p_n;
ll a[MAXN+1] = {0} ,b[MAXN] = {0};

ll createPalindrome(ll input, ll b1, bool isOdd) { 
	ll n = input ,palin = input; 
	if (isOdd)  n /= b1; 
	while (n > 0) { palin = palin * b1 + (n % b1); n /= b1; } 
	return palin; 
} 
void generatePalindromes(ll n) { 
	ll number; 
	for (ll j = 0; j < 2; j++) { 
		ll i = 1; 
		while ((number = createPalindrome(i, 10, j % 2)) < n) { p_n.PB(number); a[number]++; i++;  } 
	} 
	for(ll i = 1; i < n ;i++) a[i] += a[i-1];
} 
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
		for (int i = 2; i < SZ; i++) {
		    b[i] += b[i-1];
			if (pri[i]) {
				pr.push_back(i);
				b[i]++;
			}
		}
	}
};

void check(){
// 	cout << MP(a[1000] ,b[1000]);
    ll p ,q;
	cin >> p >> q;
	ll l = 0 ,r = MAXN-1 ,m ,ans = 0;
	
	auto get = [&](ll x)->bool{
		return (b[x]*q )<= (p*a[x]);
	};

// 	while(l < r){
// 		m = (l + r)/2;
// 		bool f = get(m);
// 		if(f) l = m+1 ,ans = m;
// 		else r = m;
// 	}
	ll ans2 = 0;
	for(ll i = 0 ;i < MAXN ;i++){
	    if(get(i)) ans2 = i;
	}
// 	cout << MP(ans2 ,ans);
    ans = ans2;
	if(ans == 0){cout << "Palindromic tree is better than splay tree";return;}
	cout << ans;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	Sieve<MAXN> Si;
	generatePalindromes(MAXN);
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
