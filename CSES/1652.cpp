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

const size_t MAXN = 1007;
int a[MAXN][MAXN];
int n ,m ,q;

// int sum(int x, int y) {
//     int ret = 0;
// 	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
// 		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
// 			ret += bit[i][j];
// 	return ret;
// }

// void add(int x, int y, int delta) {
// 	for (int i = x; i < n; i = i | (i + 1))
// 		for (int j = y; j < m; j = j | (j + 1))
// 			bit[i][j] += delta;
// }

int32_t main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
	cin >> n >> q;m=n;
	int w ,x ,y ,z;
	string s;
	for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[j - 1] == '*');
    }
    while (q--)
        cin >> w >> x >> y >> z, cout << a[y][z] - a[y][x - 1] - a[w - 1][z] + a[w - 1][x - 1] << "\n";
}
