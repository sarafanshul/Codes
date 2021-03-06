#include<bits/stdc++.h>
 
using namespace std;

const int maxn = 1e5 + 10;
int N, K;
int cnt, head[maxn], dp[maxn][2];

struct E {
	int v, w, next;
}G[maxn * 2];

void add(int u, int v, int w) {
	G[cnt].v = v;
	G[cnt].w = w;
	G[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int u, int p, int last) {
	dp[u][0] += last;
	dp[u][1] += last;
	vector< pair<int, int> > tmp;
	for (int i = head[u]; i != -1; i = G[i].next) {
		int v = G[i].v;
		int w = G[i].w;
		if (v == p) continue;
		dfs(v, u, w);
		tmp.push_back(make_pair(dp[v][1], v));
	}
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());

	int ans = 0;
	int max_tmp = 0;
	for (int i = 0; i < K - 1 && i < tmp.size(); i++) {
		dp[u][1] += tmp[i].first;
	} 
	for (int i = 0; i < K && i < tmp.size(); i++) ans = ans + tmp[i].first;
	for (int i = 0; i < tmp.size(); i++) {
		if (i < K)
			max_tmp = max(max_tmp, ans - tmp[i].first + dp[tmp[i].second][0]);
		else
			max_tmp = max(max_tmp, ans - tmp[K - 1].first + dp[tmp[i].second][0]);
	}
	dp[u][0] += max_tmp;
}

int main() {
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(dp, 0, sizeof(dp));
	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(0, -1, 0);
	cout >> dp[0][0];
	return 0;
}
