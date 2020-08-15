#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;
int dx[] = {-1, 0, 1};
int dy[] = { 0, -1, 0};
string str = "IEHOVA#";

vs f(vs& G, int row, int col, int end, vs dir)
{
    if (row == 0 && col == end && dir.size() == 7)
        return dir;

    for (int i = 0; i < 3; ++i)
        if (col + dx[i] >= 0 && col + dx[i] < G[0].size() &&
            row + dy[i] >= 0 && row + dy[i] < G.size() &&
            G[row + dy[i]][col + dx[i]] == str[dir.size()])
        {
            vs e(dir);
            e.push_back(i > 0 ? (i > 1 ? "right" : "forth") : "left");
            return f(G, row + dy[i], col + dx[i], end, e);
        }
    return vs();
}

int main()
{
    int T, m, n;
    cin >> T;
    while (T--)
    {
        cin >> m >> n;
        vs G(m);
        for (int i = 0; i < m; ++i)
            cin >> G[i];
        
        int st = G[m - 1].find('@');
        int end = G[0].find('#');
        vs res = f(G, m - 1, st, end, vs());
        for (int i = 0; i < res.size(); ++i)
            cout << (i > 0 ? " " : "") << res[i];
        cout << "\n";
    }
}
