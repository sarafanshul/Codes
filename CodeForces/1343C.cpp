
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;

inline bool sgn(int x){return (x>0)?1:0;}

void check(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		int j = i;
		while (j < n && sgn(a[i]) == sgn(a[j])) {
			cur = max(cur, a[j]);
			++j;
		}
		sum += cur;
		i = j - 1;
	}
	cout << sum << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){check();}
	return 0;
} 		