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

const long long MAXN = 1e7;

#define int long long
const ll N = MAXN;
int prim[10000005];
bool mark[10000005];
int a[1000005];
int cnt=0;
int sum[10000005];
int res[10000005];

void init() {
	for(int i=2;i<=N;i++) {
		if(mark[i]==false) {
			prim[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++) {
			if(i*prim[j]>N) {
				break;
			}
			mark[i*prim[j]]=true;
			if(i%prim[j]==0) {
				break;
			}
		}
	}
}

void check() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sum[a[i]]++;
	}
	init();
	for(int i=1;i<=cnt;i++) {
		for(int j=1;prim[i]*j<=N;j++) {
			res[prim[i]]+=sum[prim[i]*j];
		}
	}
	
	for(int i=1;i<=N;i++) {
		res[i]+=res[i-1];
	}
	
	int m;
	cin>>m;
	ll l,r;
	while(m--){
	    cin >> l>> r;
	    cout << res[min(N ,r)] - res[min(N ,l-1)]<<'\n';
	}
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
