#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[81][81];
string s;

int f(int l, int r)
{
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    int len = r - l + 1;
    int res = len;
    for (int i = l; i < r; ++i)
        res = min(res, f(l, i) + f(i + 1, r));

    // Split [l..r] into equal pieces
    for (int d = 1; d <= len / 2; ++d)
    {
        if (len % d == 0)
        {
            bool flag = true;
            for (int i = l + d; i <= r && flag; i += d)
                for (int j = 0; j < d && flag; ++j)
                    if (s[i + j] != s[l + j])
                        flag = false;

            if (flag)
                res = min(res, f(l, l + d - 1));
        }
    }

    return dp[l][r] = res;
}

int main()
{
    while (cin >> s, s != "*")
    {
        memset(dp, -1, sizeof(dp));
        cout << f(0, s.size() - 1) << endl;
    }
}
