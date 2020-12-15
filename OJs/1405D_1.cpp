#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define x first
#define y second
#define int int long long // 2e9 & 9e18
using namespace std; const int inf = numeric_limits<int>::max();
struct __io{__io(){ios_base::Init i; ios_base::sync_with_stdio(0); cin.tie(0);}} __io; // fast I/O
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
 
int n, a, b, da, db;
vector<vector<int>> g;
vector<int> vis, d;
 
void bfs(int v) {
    vis.assign(n, 0);
    vis[v] = 1;
    d.assign(n, 0);
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front(); q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
}
 
int diameter() {
    bfs(0);
 
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (d[l] < d[i]) {
            l = i;
        }
    }
 
    bfs(l);
    
    l = 0;
    for (int i = 0; i < n; ++i) {
        if (d[l] < d[i]) {
            l = i;
        }
    }
    return d[l];
}
 
int distance() {
    bfs(a);
    return d[b];
}
 
signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        a--, b--;
        g.assign(n, {});
        int u, v;
        for (int i = 0; i < n-1; ++i) {
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        int dia = diameter();
        int dist = distance();
 
        cout << (db > da * 2 && dia > da * 2 && dist > da ? "Bob" : "Alice") << '\n';
    }
}