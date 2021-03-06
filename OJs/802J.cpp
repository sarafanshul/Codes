#include<bits/stdc++.h>
 
using namespace std;
 
bool visited[101] = {false};
vector<int>adj[101];
int cost[101][101];
 
int dfs(int v ,int c ,int par) {
	visited[v] = true;
	int temp = 0;
	for (int u : adj[v]) {
		if (!visited[u])
		   temp = max(temp ,dfs(u ,c ,v) + cost[u][v]);
	}
	return c + temp;
}
 
int main(){
	ios::sync_with_stdio(false);
	int n ,u ,v ,c;
	cin >> n;
	cost[0][0] = 0;
	while (n--){
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cost[u][v] = c;
		cost[v][u] = c;
	}
	cout << dfs(0 ,0 ,0);
	return 0;
}