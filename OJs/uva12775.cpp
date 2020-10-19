// #pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
// #pragma GCC target("avx,avx2,fma") 
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
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

// ax + by = gcd(x,y)
template<typename T = long long>
T exgcd(T x ,T y ,T &a ,T &b){
	bool f = 0;
	T t ,la = 1 ,lb = 0 ,ra = 0 ,rb = 1;
	while(x%y){
		if(!f){
			la -= x/y*ra ,lb-= x/y*rb;
		} else{
			ra -= x/y*la ,rb -= x/y*lb;
		}
		t = x ,x = y ,y = t%y;
		f ^= 1;
	}
	if(!f) a = ra ,b = rb;
	else a = la ,b = lb;
	return y;
}

ll count_s(ll n1 ,ll n2 ,ll n){
	ll a, b, g;
    g = exgcd<ll>(n1, n2, a, b); // a*n1 + b*n2 = gcd(n1,2)
    if(n%g) return 0;
	ll k = n/g, k1, k2;
    a *= k, b *= k;// a*n1 + b*n2 = n
    // (a+F)*n1 + (b+G)*n2 = n =>  Fn1 + Gn2 = 0,
    //F = lcm(n1, n2)/n1 * i, G = lcm(n1, n2)/n2 * i
    k1 = n1*n2/g/n1, k2 = n1*n2/g/n2;
    if(a < 0) { // adjust a >= 0
        k = -(a/k1) + (a%k1 != 0);
        a += k*k1, b -= k*k2;
    }
    if(b < 0) { // adjust b >= 0
        k = -(b/k2) + (b%k2 != 0);
        a -= k*k1, b += k*k2;
    }
    if(a < 0 || b < 0) return 0;
    ll x1, x2, y1, y2;
    // minimize a, maximize b
    k = a/k1;
    a -= k*k1;
    b += k*k2;
    x1 = a, y1 = b;
    // maximize a, minimize b
    k = b/k2;
    a += k*k1;
    b -= k*k2;
    x2 = a, y2 = b;
    return (x2 - x1) / k1 + 1;
}

void check(){
	ll a ,b ,c ,p ,ret ,ta ,tb;
	cin >> a >> b >> c >> p;
	ll g = exgcd<ll>(exgcd<ll>(a ,b ,ta ,tb) ,c ,ta ,tb);
	
	ret = 0;
	p /= g ,a /= g ,b /= g ,c /= g;
	
	for(ll i = 0 ; p-c*i >= 0 ;i++){
		ret += count_s(a ,b ,p-c*i);
	}
	cout << ret <<"\n";
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		cout << "Case "<< i << ": ";
		check();
	}
	return 0;
}
