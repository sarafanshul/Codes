#include <iostream>
#include <cstring>
using namespace std;

int T, n, m, b, X[11], Y[11], memo[11][1 << 10];
int taxi(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int tsp(int idx, int mask)
{
    if (mask == (1 << b) - 1)
        return taxi(X[0], Y[0], X[idx], Y[idx]);

    if (memo[idx][mask] != -1)
        return memo[idx][mask];
    
    int res = 1e9;
    for (int i = 1; i <= b; ++i)
        if (!(mask & (1 << i - 1)))
            res = min(res, taxi(X[idx], Y[idx], X[i], Y[i]) + tsp(i, mask | (1 << i - 1)));

    return memo[idx][mask] = res;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> X[0] >> Y[0] >> b;
        for (int i = 1; i <= b; ++i)
            cin >> X[i] >> Y[i];

        memset(memo, -1, sizeof(memo));
        cout << "The shortest path has length " << tsp(0, 0) << '\n';
    }
}
