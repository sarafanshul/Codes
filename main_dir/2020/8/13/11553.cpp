#include <iostream>
using namespace std;

int T, n, A[8][8], res;

void f(int bs, int c, int sum)
{
    if (c == n)
    {
        res = min(res, sum);
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if ((1 << i & bs) == 0)
            f(1 << i | bs, c + 1, sum + A[i][c]);

    }
    
}

int main()
{
    cin >> T;
    while (T--)
    {
        res = 8001;
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
        
        f(0, 0, 0);
            // bitset, curr_col, cumulative_sum

        cout << res << "\n";
    }

}
