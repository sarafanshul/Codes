#include <cstring>
#include <iostream>
#include <tuple>
using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
int m, n, t; ii dp[10001];

inline bool cmp(ii& a, ii& b)
{
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

ii f(int time)
{
    if (dp[time].first != -1)
        return dp[time];

    ii x = time - m >= 0 ? f(time - m) : ii(time, 0);
    ii y = time - n >= 0 ? f(time - n) : ii(time, 0);
    
    if (cmp(x, y))
        return dp[time] = ii(x.first, x.second + 1);
    else
        return dp[time] = ii(y.first, y.second + 1);
}

int main()
{
    while (cin >> m >> n >> t)
    {
        memset(dp, -1, sizeof(dp));
        ii a = f(t); --a.second;
        cout << a.second  << (a.first ? " " + to_string(a.first) : "") << '\n';
    }
}
