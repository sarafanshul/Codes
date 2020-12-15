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

int n,i,a[100500],rez,l;
int check(){
    cin >> n >> l;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    rez = 2*max(a[0],l-a[n-1]);
    for (i = 0; i < n-1; i++) rez = max(rez, a[i+1]-a[i]);
    printf("%.10f\n",rez/2.);
    return 0;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
// 	cin.exceptions(cin.failbit);
	int t =1 ;//	cin >> t;
	while(t--)check();
	return 0;
}
