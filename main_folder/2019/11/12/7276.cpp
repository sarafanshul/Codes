#include <iostream>
#include <cstring>
using namespace std;

long A[2000], n, dp[2001][2001];
long MOD = 2147483647;

long f(long i, long s)
{
    if (i == n + 1)
        return 1;

    if (dp[i][s] != -1)
      return dp[i][s];
    
    long m = min(A[i - 1], s), M = max(A[i - 1], s);
    if (A[i] < m)
        return dp[i][s] = f(i + 1, M);
    if (A[i] > M)
        return dp[i][s] = f(i + 1, m);
    return dp[i][s] = (f(i + 1, m) + f(i + 1, M)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; ++i)
            cin >> A[i];

        cout << f(2, A[0]) << endl;
    }
}
