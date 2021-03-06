// topological sort khan's Algorithm 
// priority_queue -> (lexicographically sorted)->O(Vlog(V) + E)
// queue -> simple -> O(V+E)
//change the queue to priority queue for lexicographically sorted order
//

// for priority queue workround |
// http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/#:~:text=Instead%20of%20a%20strict%20FIFO,one%20with%20the%20highest%20priority.&text=A%20user%2Dprovided%20compare%20can,appear%20as%20the%20top().
// 
//
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
// #define int long long
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;

vector<vector<int>> adj(MAXN ,vector<int>(0));
vector<int> indeg(MAXN ,0) ,top_sort;
int n ,m;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	top_sort.reserve(MAXN);
	int a, b;
	cin >> n;
	cin >> m;
	for (int i = 0; i< m ;i++) {
		cin >> a >> b;
		a--;b--; // 0 based indexing
		adj[a].push_back(b); // DAG
		indeg[b]++;
	}
	priority_queue<int ,vector<int> ,greater<int> > q;
	for(int i = 0; i < n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.top();q.pop();
		top_sort.PB(v+1);
		for(int u :adj[v]){
			indeg[u]--;
			if(indeg[u] == 0){q.push(u);}
		}
	}
	if(top_sort.size() != n ){
		cout << "IMPOSSIBLE";return 0;
	}
	for(size_t i = 0 ;i < top_sort.size(); i++){cout << top_sort[i] << " ";}
	cout << "\n";
	return 0;
}

