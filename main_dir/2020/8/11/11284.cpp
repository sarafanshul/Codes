#include <iomanip>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;

int A[51][51], dp[52][(1 << 12) + 1];
vii S;

int home(int mask)
{
    int p = 0;
    for (int i = 0; i < S.size(); ++i)
        if (!(mask & (1 << i)))
            p += S[i].second;

    return p;
}

int tsp(int ind, int mask)
{
    if (mask == (1 << S.size()) - 1)
        return A[ind][0];

    if (dp[ind][mask] != -1)
        return dp[ind][mask];

    int m = INF;
    for (int i = 0; i < S.size(); ++i)
        if (!(mask & (1 << i)))
            m = min(m, A[ind][S[i].first] + tsp(S[i].first, mask | (1 << i)));

    return dp[ind][mask] = min(m, home(mask) + A[ind][0]);
}

int read_price()
{
    string s;
    cin >> s;
    int d = s.find('.');
    return stoi(s.substr(0, d)) * 100 + stoi(s.substr(d + 1));
}

int main()
{
    cout << fixed << setprecision(2);
    int T, n, m, p;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                A[i][j] = i == j ? 0 : INF;

        int u, v, w;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v;
            int w = read_price();
            A[u][v] = A[v][u] = min(w, A[u][v]);
        }
        
        for (int k = 0; k <= n; ++k)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= n; ++j)
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

        cin >> p;
        S.assign(p, ii());
        for (int i = 0; i < p; ++i)
        {
            cin >> S[i].first;
            S[i].second = read_price();
        }

        for (int i = 0; i < 52; ++i)
            for (int j = 0; j < (1 << 12) + 1; ++j)
                dp[i][j] = -1;
        
        int opt = home(0) - tsp(0, 0), d = opt / 100;
        string cs = to_string(opt % 100);
        cs = string(2 - cs.size(), '0') + cs;
        if (opt <= 0)
            cout << "Don't leave the house\n";
        else
            cout << "Daniel can save $" << d << '.' << cs << '\n';
    }
}
