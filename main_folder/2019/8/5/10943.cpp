#include <iostream>
using namespace std;

int dp[101][101];

int f(int n, int k)
{
    if (k == 1) return 1;

    if (dp[n][k])
        return dp[n][k];
    
    int m = 0;
    for (int i = 0; i <= n; ++i)
        m = (m + f(n - i, k - 1)) % 1000000;

    return dp[n][k] = m;
}

int main()
{
    int n, k;    
    while (cin >> n >> k, n + k)
        cout << f(n, k) << endl;   
}
