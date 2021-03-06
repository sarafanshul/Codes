
// https://cp-algorithms.com/graph/lca_binary_lifting.html
// https://www.youtube.com/watch?v=MOy4UDjN8DM&list=PLZU0kmvryb_HZpDW2yfn-H-RxAu_ts6xq&index=10&t=1508s
//
// for distance between two nodes we will se lca of two nodes
//      if LCA(n1 ,n2) = a;
//      distance between n1 - n2 = h(n1 - a) + h(n2 - a)
//          (where h is the height array)

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
#define MP make_pair

using namespace std;

const uint64_t MAXN = 1e5 + 7;
vector<vector<int>> adj(MAXN ,vector<int>(0)) ,up;
vector<int> tin, tout ,h;
int timer, n, l;;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;h[v] = h[p]+1;
    for (int i = 1; i <= l; ++i)up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {if (u != p)dfs(u, v);}
    tout[v] = ++timer;
}

inline bool is_ancestor(int u, int v){return tin[u] <= tin[v] && tout[u] >= tout[v];}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {if (!is_ancestor(up[u][i], v))u = up[u][i];}
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n); tout.resize(n);
    h.resize(n); h[root] = 0;
    timer = 0; l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int goUp(int c ,int u){
    while(c >= 0){
        int i; for(i = 0;(i <= l && 1<<i <= c);i++){} 
        u = up[u][i-1];c -= 1<<(i);
    }return u;
}

int dist(int u ,int v ,int c){
    int _lca = lca(u ,v) ,total = ((h[u] - h[_lca]) + (h[v] - h[_lca]));
    if(c >= total) return v;
    if(c <= (h[u] - h[_lca])) return goUp(c ,u);
    return goUp(total-c ,v);        
}

void ck(){
    int m ,q ,u ,v ,c;
    cin >> n;
    for(int i = 0 ;i < n-1 ; i++){ // 0 based
        cin >> u >> v;u--;v--;
        adj[v].PB(u);adj[u].PB(v);
    }
    preprocess(0);
    cin >> q;
    for(int i = 0; i < q ;i++){
        cin >> u >> v>>c;u--;v--;
        cout << dist(u ,v ,c)+1 << "\n"; 
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);ck();
    return 0;
}