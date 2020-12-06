
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

const size_t MAXN = 2*(1e5 + 7);
vector<int> t(MAXN);
int n;

void add(int k, ll x) {
  	while (k <= n) t[k] += x, k += k & -k;
}

void add(int a, int b, ll x) {
  	add(a, x), add(b + 1, -x);
}

ll sum(int k) {
  	ll s = 0;
  	while (k) s += t[k], k -= k & -k;
  	return s;
}

int32_t main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int q, p, x, y = 0, z;
  	cin >> n >> q;
  	for (int i = 1; i <= n; i++) cin >> x, add(i, x - y), y = x;
  	while (q--) {
    	cin >> p;
    	if (p == 1) cin >> x >> y >> z, add(x, y, z);
    	else cin >> x, cout << sum(x) << "\n";
  	}
}
