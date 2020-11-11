#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, u, len, i, j, ans = 1, a[1000];
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
 
	for (i = 1; i <= n; ++i) {
		for (u = i, j = 1, len = 0; j <= n; ++j) {
			u = a[u];
 
			if (u == i) {
				len = j;
				break;
			}
		}
 
		if (len == 0) {
			cout << -1 << endl;
			return 0;
		}
 
		if (len % 2 == 0) {
			len /= 2;
		}
 
		ans = ans / __gcd(ans, len) * len; // lcm
	}
 
	cout << ans << '\n';
	return 0;
}
