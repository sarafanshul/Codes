
// Floyd Warshall APSP Algorithm

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
// #define LONG_LONG_MAX LONG_LONG_MAX
// #define LONG_LONG_MIN LONG_LONG_MIN
#define MP make_pair

using namespace std;
const size_t MAXN = 600;
ll INF = 1e18;
vector<vector<int>> d(MAXN, vector<int>(MAXN, INF));
int n;
void FW(){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[j][i] = d[i][k] + d[k][j];
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, q, u, v, w;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w, u--, v--;
        if (w < d[u][v]) d[u][v] = d[v][u] = w;
    }
   	FW(); 
    while (q--) {
        cin >> u >> v, u--, v--;
        if (u == v) d[u][v] = 0;
        if (d[u][v] == INF) d[u][v] = -1;
        cout << d[u][v] << "\n";
  }
  return 0;
}

