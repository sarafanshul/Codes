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


void check(){
	ll n;
	cin >> n;
	vector<ll> a(n) ,b(n);
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}
	for(int i = n-1 ;i >= 0; i--){
		cin >> b[i];
	}
	int x=0,y=n-1;
	for(int i = 0 ;i < n ;i++){
		if(a[i]==b[i]){
            if(x<n&&b[x]!=a[i]&&a[x]!=b[i]) swap(b[i],b[x++]);
            else if(0<=y&&b[y]!=a[i]&&a[y]!=b[i]) swap(b[i],b[y--]);
            else{
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << '\n';
    for(int i = 0; i < n ;i++) cout << b[i] << " ";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
