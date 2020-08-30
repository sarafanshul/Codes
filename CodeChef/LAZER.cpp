#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())


using namespace std;
using namespace __gnu_pbds; // for rebtree /use segmrnt insted

template <typename T>
using rbtree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 1e5 + 7;
vector<int> res(MAX), in(MAX), par(MAX), a(MAX);
vector<vector<int>> query(MAX,vector<int>(4));
unordered_map<int,vector<int>> height;
rbtree<int> lef, rig;

// ----- rbtree props --------
int root(int u) { 
    return par[u] < 0 ? u : par[u] = root(par[u]); 
}

int merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return u;
    if (v < u) swap(u, v);
    par[u] += par[v];
    return par[v] = u;
}

int count(int l, int r) {
    return lef.order_of_key(r + 1) - rig.order_of_key(l);
}

void update(int p) {
    if (in[p + 1]) {
        int r = root(p + 1);
        lef.erase(r);
        rig.erase(r - par[r] - 1);
        p = merge(p, r);
    }
    if (in[p - 1]) {
        int l = root(p - 1);
        lef.erase(l);
        rig.erase(l - par[l] - 1);
        p = merge(l, p);
    }
    lef.insert(p);
    rig.insert(p - par[p] - 1);
}

// ---end ---

void input(int n , int q){
    a.assign(n, -1);
    res.assign(q, -1);
    query.assign(q,vector<int>(4));
    height.clear();

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        height[a[i]].emplace_back(i + 1);
    }

    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        cin >> l >> r >> y;
        j = i;
    }
}

void hi_low(int n ,int q){
    in.assign(n + 2, 0), par.assign(n + 2, -1);
    lef.clear(), rig.clear();
    int t = 0;
    int out_l = 0;
    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        while (t < a.size() && a[t] < y) {
            for (auto &p : height[a[t]]) {
                update(p);
                in[p] = 1;
            }
            t++;
        }
        res[j] += count(l, r);
    }
}

void hi_high(int n ,int q){
    in.assign(n + 2, 0), par.assign(n + 2, -1);
    lef.clear(), rig.clear();
    int t = a.size() - 1;
    int out_h = n;
    for (int i = q; i--;) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];
        while (t >= 0 && a[t] > y) {
            for (auto &p : height[a[t]]) {
                in[p] = 1;
                update(p);
            }
            t--;
        }
        res[j] += count(l, r);
    }
}

void hi_eq(int n ,int q){
    int t = 0;

    lef.clear(), rig.clear();
    for (int i = 0; i < q; ++i) {
        int &l = query[i][0], &r = query[i][1];
        int &y = query[i][2], &j = query[i][3];

        if (i && y != query[i - 1][2]) {
            lef.clear();
            rig.clear();
        }

        while (t < a.size() && a[t] < y) t++;
        if (t < a.size() && a[t] == y)
            for (auto &p : height[y]) lef.insert(p), rig.insert(p);

        res[j] += count(l, r);
        // write("equal  ", j, count(l, r));
    }
    int out_e = n - t;
}

void please_solve() {
    int n, q;
    cin >> n >> q;
    input(n ,q);

    sort(all(query), [](vector<int> &a,vector<int> &b) { return a[2] < b[2]; });
    sort(all(a));
    uni(a);
    
    // lower tha srt rt.
    hi_low(n ,q);
    // higher than srt rt.
    hi_high(n ,q);
    // same
    hi_eq(n ,q);
    
    for (int i = 0; i < q; ++i) cout << res[i]%2 << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) please_solve();

    return 0;
}
