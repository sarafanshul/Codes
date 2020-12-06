// sparse_table

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 505000;
const int MAXLOG = 25;


int table[MAXLOG][MAXN];
int logs[MAXN];

void computeLogs() {
  	for (int i = 2; i < MAXN; i++) {
		logs[i] = logs[i / 2] + 1;
  	}
}

void buildSparseTable(vector<int> &a ,int n) {
	int curLen;
  	for (int i = 0; i <= logs[n]; i++) {
		curLen = 1 << i;
		for (int j = 0; j + curLen <= n; j++) {
	  		if (curLen == 1) {
				table[i][j] = a[j];
	  		} else {
				table[i][j] = min(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
	  		}
		}
  	}
}

int getMin(int l, int r) {
  	int p = logs[r - l + 1];
  	int pLen = 1 << p;
  	return min(table[p][l], table[p][r - pLen + 1]);
}

int32_t main() {
	computeLogs();
	int n ,qn ,l ,r;
	cin >> n >> qn;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	buildSparseTable(a ,n);

	while(qn--) {
		cin >> l >> r;
		cout << getMin(l-1, r-1) << "\n";
	}
	
	return 0;
}