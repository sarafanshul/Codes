#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int n, C[101] = {}, r;
double b, v, e, f, dp[101], L[10001];

double ch(int ind)
{
    if (ind == n)
        return 0;
    
    if (dp[ind])
        return dp[ind];
    
    double m = 1e9;
    for (int i = ind + 1; i <= n; ++i)
        m = min(m, L[C[i] - C[ind] - 1] + (ind ? b : 0) + ch(i));

    return dp[ind] = m;
}

int main()
{
    cout << setprecision(4);
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; ++i)
            cin >> C[i];        
        cin >> b >> r >> v >> e >> f;

        for (int i = 0; i <= C[n]; ++i)
            L[i] = 1.0 / (v - (i >= r ? e : f) * abs(i - r));
        
        for (int i = 1; i <= C[n]; ++i)
            L[i] += L[i - 1];

        memset(dp, 0, sizeof(dp));
        cout << fixed << ch(0) << '\n';
    }
}
