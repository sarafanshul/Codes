/*
The simplest solution is simply doing a breadth-first search. 
 Construct a graph with numbers as vertices and edges leading 
 from one number to another if an operation can be made to change 
 one number to the other. We may note that it is never reasonable 
 to make the number larger than 2m, so under provided limitations 
 the graph will contain at most 2·104 vertices and 4·104 edges, 
 and the BFS should work real fast.

There is, however, an even faster solution.
 The problem can be reversed as follows: 
 we should get the number n starting from m using the 
 operations "add 1 to the number" and "divide the number by 2 if it is even".

Suppose that at some point we perform two operations 
 of type 1 and then one operation of type 2; 
 but in this case one operation of type 2 and one operation of 
 type 1 would lead to the same result, and the sequence would 
 contain less operations then before. That reasoning implies that 
 in an optimal answer more than one consecutive operation of type 
 1 is possible only if no operations of type 2 follow, that is, the 
 only situation where it makes sense is when n is smaller than m and 
 we just need to make it large enough. Under this constraint, there is 
 the only correct sequence of moves: if n is smaller than m, we just add 
 1 until they become equal; else we divide n by 2 if it is even, or add 
 1 and then divide by 2 if it is odd. The length of 
 this sequence can be found in .

*/

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

using namespace std;
int n ,m;
vector<int> adj[200001];
bool visited[200001];
int deg[200001];
vector<int> comp;

void dfs(int v){
	visited[v] = true;
	comp.PB(v);
	for (int u : adj[v]){
		if (!visited[u])
			dfs(u);
	}
}

int bfs(int x ,int y){
	queue<int> q ,p;
	q.push(x);
	visited[x] = 1;
	p.push(0);

	while(!q.empty()){
		int num = q.front();
		int ceng = p.front();
		q.pop();
		p.pop();
		if (num == y ) return ceng;
		if (num*2 <= 10000 && !visited[num*2]){
			q.push(num*2);
			visited[num*2] = 1;
			p.push(ceng+1);
		}
		if (num - 1 > 0 && !visited[num-1]){
			q.push(num-1);
			visited[num-1] = 1;
			p.push(ceng+1);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(visited ,0 ,sizeof(visited));
	cin >> n >> m;
	cout << bfs(n ,m);
	return 0;
}