#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int C[40], IT[40], memo[40][300][300][40], m, S;

int cc(int idx, int c, int it, int cnt)
{
    float val = sqrt(c * c + it * it);
    if (val == S)
        return cnt;
    if (val > S)
        return 1e9;
    if (idx == m)
        return 1e9;
    if (memo[idx][c][it][cnt] != -1)
        return memo[idx][c][it][cnt];
    
    return memo[idx][c][it][cnt] = min(cc(idx, c + C[idx], it + IT[idx], cnt + 1), cc(idx + 1, c, it, cnt));
}

int main()
{
    int T, tmp;
    cin >> T;
    while (T--)
    {

        memset(C, -1, sizeof(C));
        memset(IT, -1, sizeof(IT));
        memset(memo, -1, sizeof(memo));
        cin >> m >> S;
        for (int i = 0; i < m; ++i)
            cin >> C[i] >> IT[i];
        
        if (tmp = cc(0, 0, 0, 0), tmp < int(1e9))
            cout << tmp << '\n';
        else
            cout << "not possible\n";           
    }
}
