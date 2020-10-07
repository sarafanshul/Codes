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

const long long MAXN = 20000007;

vector<ll> ans;
void pre(){
	ans.reserve(MAXN);
	vector<bool> is_prime(MAXN + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAXN; i++) {
    	if (is_prime[i]) {
        	for (int j = i * i; j <= MAXN; j += i)
            	is_prime[j] = false;
    	}
	}
	for(ll i = 1 ;i < MAXN-2 ;i++){
		if(is_prime[i] && is_prime[i+2])
			ans.PB(i);
	}
}

void check(ll n){
	// ll n ;
	// cin >> n ;
	printf("(%d, %d)\n" ,(int)ans[n-1] ,(int)ans[n-1]+2);
}

int32_t main(){
	#ifndef CUST_DEBUG
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
  pre();
	// cin.exceptions(cin.Failbit);
	int t;	
	// cin >> t;
	// for(int i = 1 ; i <= t ;i++){
	// 	// cout << "Case "<< i << ":\n";
	// 	check();
	// }
  while (scanf("%d",&t)==1){
    check((ll)t);
  }
	return 0;
}
