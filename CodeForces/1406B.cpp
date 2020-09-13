#pragma GCC optimize("Ofast")  
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
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 1e5 +7;
long long ans,a[100005];

void check(){
	int n;
	long long mx = -1e9;
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i],mx=max(mx,a[i]);

	sort(a+1,a+n+1,[](long long x,long long y){return abs(x)>abs(y);});
	
	if(mx<0){cout<<a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]<<'\n';return;}
	
	ans=a[1]*a[2]*a[3]*a[4]*a[5];
	for(int i=6;i<=n;i++){
	    for(int j=1;j<=5;j++){
	        long long tmp=a[i];
	        for(int k=1;k<=5;k++){
	            if(k!=j)tmp*=a[k];
	        }
	        ans=max(ans,tmp);
	    }
	}
	
	cout << ans <<"\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
