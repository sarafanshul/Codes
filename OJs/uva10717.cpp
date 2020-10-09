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

vector<ll> low_c ,arr(MAXN);
template<typename T = ll>
inline T lcm(T a ,T b){ return (a / __gcd(a ,b))*b;}
template<typename T = long long >
inline T __ceil(T a ,T b){return (a + b - 1)/b;}


void calc(const vector<ll> & v){
    ll tmp = 1;
    for(const ll &i : v) tmp = lcm(tmp ,i);
    low_c.PB(tmp);
}

void recur(vector<ll> &out, ll i, ll k){
	if (k == 0) {calc(out);return;}
	if (i < 0) return;
	out.push_back(arr[i]);
	recur(out, i - 1, k - 1);
	out.pop_back();		// backtrack
	//while (i > 0 && arr[i] == arr[i-1]) i--; // if sorted
	recur(out, i - 1, k);
}

void check(ll n ,ll m){
	vector<ll> th(n) ,tb(m);
	arr.clear();
	for(int i = 0 ;i < n ;i++) cin >> arr[i];
	vector<ll> tmp;
	recur(tmp ,n-1 ,4);
	ll x ,y;
	for(int i = 0 ; i < m ;i++){
		cin >> tb[i];
	    x = 0LL ,y = LONG_LONG_MAX;
	    for(ll &lc : low_c){
	        x = max(tb[i]/lc * lc ,x);
	        y = min(y , __ceil<ll>(tb[i] ,lc)*lc );
	    } cout << x <<" "<<y <<"\n";
	}
	low_c.clear(); // FUCKING CLEAR IT
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	ll n ,m;
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0)return 0;
		check(n ,m);
	}
	return 0;
}
