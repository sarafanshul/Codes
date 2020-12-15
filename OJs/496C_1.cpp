#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 106;
 
int n, m;
char mat[N][N];
int ok[N];
 
int main() {
	scanf("%d %d", &n, &m);
 
	for(int i = 0; i < n; i++) scanf(" %s", mat[i]);
 
	int ans = 0;
 
	for(int j = 0; j < m; j++) {
		bool good = true;
		for(int i = 0; i + 1 < n; i++) if(!ok[i]) {
			good &= mat[i][j] <= mat[i + 1][j];
		}
		if(!good) ans++;
		else {
			for(int i = 0; i + 1 < n; i++) {
				ok[i] |= mat[i][j] < mat[i + 1][j];
			}
		}
	}
 
	printf("%d\n", ans);
}
