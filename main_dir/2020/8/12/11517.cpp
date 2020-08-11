#include <algorithm> 
#include <iostream>
#include <cstring>
using namespace std;
#define INF 1000000000

int main()
{
    int n, m, p, A[100], dp[20000];
    cin >> n;
    while (n--)
    {
        cin >> p >> m;
        for (int i = 0; i < m; ++i)
            cin >> A[i];

        for (int i = 0; i < 20000; ++i)
            dp[i] = INF;
        dp[0] = 0;
        
        for (int j = 0; j < m; ++j)
            for (int i = 20000 - A[j]; i >= 0; --i)
            // Note: Iterating from 0 would use the same coin multiple times.
                if (dp[i] < INF)                    
                    dp[i + A[j]] = min(dp[i + A[j]], dp[i] + 1);

        int res = find_if(dp + p, dp + 20000, [](int x){return x < INF;}) - dp;
        cout << res << ' ' << dp[res] << '\n';
    }
}
