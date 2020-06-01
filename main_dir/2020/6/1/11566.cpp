#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 1000000000

int N, x, T, K, P[200], F[200], memo[200][100 * 11][20];

int val(int ind, int mon, int nr)
{        
    int service = ceil(0.1 * (T + x - mon));
    int paid = T + x - mon + service;

    if (paid > x)
        return -INF;
    if (ind == 2 * K || nr == 2 * N || paid == x)
        return 0;
    if (P[ind] > mon)
        return memo[ind][mon][nr] = val(ind + 1, mon, nr);
    if (memo[ind][mon][nr] != -1)
        return memo[ind][mon][nr];

    return memo[ind][mon][nr] = max(val(ind + 1, mon, nr), F[ind] + val(ind + 1, mon - P[ind], nr + 1));
}

int main()
{
    cout << setprecision(2) << fixed;
    while (cin >> N >> x >> T >> K, N || x || T || K)
    {
        ++N;
        x *= N; T *= N;
        memset(F, 0, sizeof(F));
        memset(memo, -1, sizeof(memo));
        
        for (int i = 0; i < K; ++i)
        {
            cin >> P[2 * i];
            for (int j = 0, tmp; j < N; ++j)
                cin >> tmp, F[2 * i] += tmp;

            P[2 * i + 1] = P[2 * i];
            F[2 * i + 1] = F[2 * i];
        }
        
        cout << val(0, x, 0) / float(N) << '\n';
    }
}
