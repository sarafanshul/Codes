#include <iostream>
#include <cstring>
using namespace std;

int Q[50], n, q, dp[52][52];

int f(int a, int b)
{
    if (a > b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];
    
    int m = 50000;
    for (int i = a; i <= b; ++i)        
        m = min(m, f(a, i - 1) + f(i + 1, b) + Q[b + 1] - Q[a - 1]);

    return dp[a][b] = m;
}

int main()
{
    while (cin >> n >> q)
    {
        for (int i = 1; i <= q; ++i)
            cin >> Q[i];
        Q[q + 1] = n; // Sentry

        memset(dp, -1, sizeof(dp));
        cout << "The minimum cutting is " << f(1, q) << ".\n";
    }
}
