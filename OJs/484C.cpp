
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, ans;
vector<int> G[MAXN];


int dfs(int u, int fa) {
    int cnt = 1;
    for (int i = 0; i < G[u].size(); i++) if(G[u][i] != fa) {
        cnt += dfs(G[u][i], u);
    }
    if (!(cnt&1)) ans += 1;
    return cnt;
}

int main(){
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (n&1) cout << "-1";
    else {
        int t = dfs(1, 0);
        cout << ans - 1;
    }
	return 0;
}
