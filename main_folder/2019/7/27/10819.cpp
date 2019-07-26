#include <iostream>
#include <cstring>
using namespace std;

int P[100], F[100], memo[100][10001], m, n;

int val(int idx, int s)
{
    if ((s > m && s <= 1800) || s > m + 200)
        return -6;
    if (idx == n && s > m && s <= 2000)
        return -6;
    if (idx == n)
        return 0;
    
    if (memo[idx][s] != -1)
        return memo[idx][s];

    return memo[idx][s] = max(val(idx + 1, s), F[idx] + val(idx + 1, s + P[idx]));
}

int main()
{
    while (cin >> m >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i] >> F[i];

        memset(memo, -1, sizeof(memo));
        cout << val(0, 0) << '\n';
    }
}
