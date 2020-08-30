#include <bits/stdc++.h>
#define N 300010
using namespace std;

typedef long long LL;

priority_queue<int, vector<int>, greater<int> > Q;
vector<int> e[N];
vector<int> seq;
bool vis[N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	vis[1] = true;
	Q.push(1);
	while (!Q.empty()){
		int now = Q.top();
		Q.pop();
		seq.push_back(now);
		for (auto p : e[now]){
			if (!vis[p]){
				Q.push(p);
				vis[p] = true;
			}
		}
	}
	
	for (auto p : seq){
		printf("%d ", p);
	}
	puts("");
	return 0;
}