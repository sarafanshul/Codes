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


const int N=20;
ll a[N];

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,m;
    while(~scanf("%lld%lld",&n,&m)){
    	for(ll i=0;i<m;i++) scanf("%lld",&a[i]);

    	ll end=(1<<m);
    	ll sum=0;
    	for(ll i=1;i<end;i++) {
    		ll tmp=1,num=0;
    		for(ll j=0;j<m;j++){
    			if((1<<j)&i) tmp=lcm(tmp,a[j]),num++;
    			if(tmp>n) break;
    		}
    		if(num%2==1) sum+=n/tmp;
    		else sum-=n/tmp;
    	}
    	printf("%lld\n",n-sum);
    }
    return 0;
}
