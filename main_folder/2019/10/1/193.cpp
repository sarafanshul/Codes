#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

typedef vector<__int128> vi;
int best, c;
__int128 res;

void f(vi G, int curr, __int128 col)
{
    if (curr == G.size())
    {
        if (c > best)
        {
            best = c;
            res = col;
        }
        return;
    }

    f(G, curr + 1, col);
    col |= __int128(1) << curr;
    
    if (G[curr] & col)
        return;
    
    c++;
    f(G, curr + 1, col);
    c--;
}

int main()
{
    int m, n, k, u, v;
    cin >> m;
    while (cin >> n >> k)
    {
        vi G(n);
        c = res = best = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> u >> v;
            G[u - 1] |= __int128(1) << (v - 1);
            G[v - 1] |= __int128(1) << (u - 1);
        }

        f(G, 0, 0);
        
        cout << best << "\n";
        bool flag = false;
        for (int i = 0; i < n; ++i)
            if ((__int128(1) << i) & res)
            {
                cout << (flag ? " " : "") << i + 1;
                flag = true;
            }
        cout << "\n";
    }
}
