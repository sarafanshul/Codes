#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi V;
int dp[21][201], M, C;

int buy(int ind, int val)
{
    if (val < 0) return 201 * 21;
    if (ind == C) return val;
    if (dp[ind][val] != -1) return dp[ind][val];

    int m = 201*21;
    for (int k = 0; k < V[ind].size(); ++k)
        m = min(m, buy(ind + 1, val - V[ind][k]));

    return dp[ind][val] = m;
}

int main()
{
    ios::sync_with_stdio(false);
    int T, k;
    cin >> T;
    while (T--)
    {
        cin >> M >> C;
        V.assign(C, vi());
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < C; ++i)
        {
            cin >> k;
            V[i].resize(k);
            for (int j = 0; j < k; ++j)
                cin >> V[i][j];
        }

        int c = buy(0, M);
        cout << (c <= M ? to_string(M - c) : "no solution")<< '\n';            
    }
}
