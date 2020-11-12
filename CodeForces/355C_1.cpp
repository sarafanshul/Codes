
#include <bits/stdc++.h>
using namespace std;

int A[100001];

int main() {
	int a, l, m = INT_MAX, n, r, q1, q2;
	cin >> n >> l >> r >> q1 >> q2;
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for (int i = 0; i <= n; ++i) {
		a = A[i] * l + (A[n] - A[i]) * r;
		if (i < n - i) {
			a += ((n - i) - i - 1) * q2;
		}
		if (i > n - i) {
			a += (i - (n - i) - 1) * q1;
		}
		if (a < m) m = a;
	}
	cout << m << endl;
	return 0;
}
