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

const long long MAXN = 1e5 +7;
vector<ll> primes;
template <long long N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (int i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (int i = 2; i < N; i++)
            if (is_prime[i]) {
                for (int j = 2 * i; j < N; j += i) {
                    is_prime[j] = false;
                }
            }
    }
};
 
bool is_prime(long long n) {
    static constexpr Sieve<MAXN> s;
    return s.is_prime[n];
}
void pre(){
	primes.reserve(MAXN+1);
	for(ll i = 2 ;i < MAXN ;i++) if(is_prime(i)) primes.PB(i);
}

void check(){
	ll n ,m;
	cin >> n >> m;
	vector<vector<ll>> a(n ,vector<ll>(m));
	vector<ll> col(m ,0) ,rw(n ,0) ,mv_c(m ,0) ,mv_r(n ,0);
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m ;j++){
			cin >> a[i][j];
			if(!is_prime(a[i][j])){ rw[i]++; col[j]++;}
		}
	}
	// in 1 move change all the nonprimes to primes
	// store the diff
	for(int i = 0; i < n ; i++){
		for(int j = 0 ;j < m ; j++){
			if(is_prime(a[i][j])) continue;
			rw[i]-- ,col[j]--;
			auto near_p = upper_bound(ALL(primes) ,a[i][j]) - primes.begin();
			ll price = primes[near_p] - a[i][j];
// 			cout << MP(primes[near_p] ,a[i][j])<<":";
			mv_r[i] += price;
			mv_c[j] += price;
		}
	}
	ll mn = LONG_LONG_MAX;
	for(int i = 0;i < n ; i++) mn = min(mn ,mv_r[i]);
	for(int i = 0;i < m ; i++) mn = min(mn ,mv_c[i]);
// 	cout << mv_r <<" \n"<<mv_c;
	cout << mn;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	pre();
	int t = 1;
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
