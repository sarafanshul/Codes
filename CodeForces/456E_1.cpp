// https://codeforces.com/contest/456/problem/E
// 
// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
// header(s)
#include <bits/stdc++.h>
 
// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
 
// namespaces
using namespace std;
 
// global declerations
const size_t MAXN = 3*(1e5 +7);
int N, M, Q, f[MAXN], s[MAXN];
vector<int> g[MAXN];
int root, ans, rec;
 
inline int getfar(int x) {return (f[x] == x) ? x : f[x] = getfar(f[x]);}
 
void link (int u, int v) {
    int x = getfar(u);
    int y = getfar(v);
 
    if (x == y) return;
 
    if (s[x] < s[y]) swap(s[x], s[y]);
    f[y] = x; // updating 
    s[x] = max(s[x], (s[x] + 1) / 2 + (s[y] + 1) / 2 + 1);
}
 
void dfs (int u, int p, int d) {
    f[u] = root;
 
    if (d > ans) {ans = d;rec = u;}
    for(int i : g[u]){
        if (i != p)dfs(i, u, d+1);
    }
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
    int type, u, v;
 
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        f[i] = i;
    }
 
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= N; i++) {
        if (f[i] == i) {
            root = rec = i;
            ans = -1;
            dfs(i, 0, 0);
 
            ans = -1;
            dfs(rec, 0, 0);
            s[i] = ans;
        }
    }
 
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> u;
            v = getfar(u);
            cout << s[v] <<"\n";
        } else {
            cin >> u >> v;
            link(u, v);
        }
    }
	return 0;
}
