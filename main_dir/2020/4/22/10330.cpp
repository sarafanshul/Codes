#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi P;
int R[202][202], s, t, n, m, u, v, w;

void process(int a, int b, int w)
{
    R[a][b] += w;
    G[a].push_back(b);
    G[b].push_back(a);
}

bool ap()
{
    P.assign(2 * n + 2, -1);
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int top = Q.front(); Q.pop();
        if (top == t)
            return true;

        for (int x : G[top])
            if (P[x] == -1 && R[top][x] > 0)
                Q.push(x), P[x] = top;
    }

    return false;
}

int main()
{
    int T = 0;
    while (cin >> n)
    {
        ++T;

        memset(R, 0 , sizeof(R));
        s = 2 * n, t = s + 1;
        G.assign(2 * n + 2, vi());

        for (int i = 0; i < n; ++i)
            cin >> w, process(i, i + n, w);

        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> u >> v >> w, --u, --v, process(u + n, v, w);

        cin >> u >> v;
        for (int i = 0; i < u; ++i)
            cin >> w, process(s, --w, INF);
        
        for (int i = 0; i < v; ++i)
            cin >> w, process(--w + n, t, INF);

        int mf = 0;
        while (ap())
        {
            int aug = INF;
            for (int it = t; it != s; it = P[it])
                aug = min(aug, R[P[it]][it]);

            for (int it = t; it != s; it = P[it])
                R[P[it]][it] -= aug, R[it][P[it]] += aug;

            mf += aug;
        }
        
        cout << mf << "\n";
    }
}
        
