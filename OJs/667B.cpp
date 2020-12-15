// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
#define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;

template<typename T>
inline T diff(T a ,T b ,T x ,T y ,T n){
	a -= x;b -= y;
	int d = n - a;
	a = max(0LL ,a - n);
	if(d > 0)b = max(0LL ,b - d);
	return (a+x)*(b+y);
}

void check(){
	int a ,b ,x ,y ,n;
	cin >> a >> b >> x >> y >> n;
	int ret = min(diff(a ,b ,x ,y ,n) ,diff(b ,a ,y ,x ,n));
    cout << ret <<"\n";
}
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	// cin.exceptions(cin.failbit);

	int t;
	cin >> t;

	while(t--){
		check();
	}

	return 0;
}
