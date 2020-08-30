/*
All these observations are made under one assumption: 
 The given graph is a tree- that means for two nodes 
 there are only ONE(non-backward) path between them.

I will take the editorial's example,
 assume that we have some nodes right here:

A — B .... C — D

Obviously for A we will try to get C or D,
  so does B... The question is: How do we determine if we are
  going to guarantee that there is such point C and D on
  the other side for A and B to connect?

Here's an idea- we will try to find a point that has 
 K universities on one side, and another K universities on 
 the other side- In this way every link is going to pass 
 through to point, and the total cost will be the total 
 distance of all points from this central point.

But don't be fooled! During a dfs search there are only 
 children's — you can't determine if those children can be 
 splitted into two sides. That's why we should be 
 finding the point with the LEAST amount of child which 
 has AT LEAST K children has a universities. 
 In this way we can guarantee it is the central point we need.

Now you should notice there is one thing left - 
	Where is the root of the tree? 
 	 Just pick any leaf of the tree and assume it is the root. 
 	 That will do the job for searching the central point.
*/


#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

const int MAXN = 200010;
bool uni[MAXN] = {0};
vector<int> adj[MAXN];
int n ,k ,best = INT_MAX ,res = 0 ,root1 ,root2;

int dfs1(int now ,int prev){
	int cnt = uni[now];
	for(int u:adj[now]){
		if(u - prev) cnt += dfs1(u ,now);
	}
	if(cnt >= k && cnt < best){root2 = now;best = cnt;}
	return cnt;
}

void dfs2(int now ,int prev ,int d){
	if(uni[now]) res += 1*d;
	for(int u :adj[now]){
		if(u - prev) dfs2(u ,now ,d+1);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	int val ,u ,v;
	for(int i = 0; i<2*k ;i++){
		cin >> val;
		uni[val] = 1;
	}
	for(int i = 0; i<n-1;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i = 0 ;i < n; i++){
		if(adj[i].size() == 1){root1 = i;break;}
	}
	int sink = dfs1(root1 ,-1);
	dfs2(root2 ,-1 ,0);
	cout << res;
	
	return 0;
}