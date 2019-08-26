#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define INF 1e9

int dp[11][101], A[11][101], p[11][101], r, c;

int f(int a, int b)
{    
    if (b == c)
        return 0;
    
    if (dp[a][b] != -1)
        return dp[a][b];

    int N[3] = {a ? a - 1 : r - 1, a, a + 1 < r ? a + 1 : 0}, l = INF;
    sort(N, N + 3);
    
    for (int i = 0; i < 3; ++i)
        if (f(N[i], b + 1) < l)
            l = f(N[i], b + 1), p[a][b] = N[i];

    return dp[a][b] = l + A[a][b];
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> r >> c)
    {
        for (int i = 0; i < r * c; ++i)
            cin >> A[i / c][i % c];

        int m = INF, ind;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < r; ++i)
            if (f(i, 0) < m)
                m = f(i, 0), ind = i;
        
        for (int k = 0; k < c; ++k)
            cout << (k ? " " : "") << ind + 1, ind = p[ind][k];
        cout << '\n' << m << '\n';
    }
}
