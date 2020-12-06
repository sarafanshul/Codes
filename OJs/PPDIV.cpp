#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const int kMod = 1e9 + 7;
const ll inv6 = 166666668;

ll dp_sto[10001];

struct customInt {
	long long n;
	customInt(long long n = 0) : n(n % kMod) {}
	customInt operator+(const customInt& oth) { return n + oth.n; }
	customInt operator-(const customInt& oth) { return n - oth.n; }
	customInt operator*(const customInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};

customInt sumsqr(ll n) {
	customInt ans = n;
	ans = ans * (n + 1);
	ans = ans * (2 * n + 1);
	ans = ans * inv6;
	return ans;
}

customInt sqrfre(ll n ,ll _vis){
	ll tmp, j, k;
	ll N = cbrtl(n);
	customInt ans = n;
	ll dvmd = 0;
	customInt sqrN = sumsqr(N);
	vector<bool> DP(N + 1, false);
	DP[0] = DP[1] = true;

	for (ll i = 1; i <= N; i++) {
		ld up = ((ld)n * 1.0) / i;
		tmp = sqrtl(up);
		if (tmp > N){
			ans = ans + sumsqr(tmp) - sqrN;
			dvmd++; }
		if (DP[i]) continue;
		j = 1, k = 1;
		while (true) {
			if ((ld)j > up) break;
			else j *= i, k *= i;
			if ((ld)j > up) break;
			else j *= i;
			if (k > N) break;
			if (j <= N) DP[j] = true;
			tmp = n / j;
			dvmd = min(tmp ,ans.get());
			ans = ans + tmp * j;
			_vis = max(_vis ,ans.get());
		}
		j = i;
		while (true) {
			if ((ld)j > up) break;
			else j *= i;
			if ((ld)j > up) break;
			else j *= i;
			if (j <= N) DP[j] = true;
			tmp = n / j;
			dvmd = min(tmp ,ans.get());
			ans = ans + tmp * j;
			_vis = max(_vis ,ans.get());
		}
	}
	dp_sto[N] = ans.get();
	return ans;
}

void solve() {
	ll n ;
	cin >> n;
	ll _vis = -1;
	cout << sqrfre(n ,_vis).get() << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; 
	cin >> t;
	while (t--) solve();
}