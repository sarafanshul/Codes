#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t, r, h;
    while (cin >> t >> r >> h)
    {
        int T[20][21], R[20][21], H[20][21];
        for (int i = 0; i < t; ++i)
            for (int j = 0; j < r + 1; ++j)
                cin >> T[i][j];

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < h + 1; ++j)
                cin >> R[i][j];

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < t + 1; ++j)
                cin >> H[i][j];

        int res = INT_MAX, ind[3];
        for (int i = 0; i < t; ++i)
            for (int j = 0; j < r; ++j)
                if (!T[i][j + 1])
                    for (int k = 0; k < h; ++k)
                        if (!R[j][k + 1] && !H[k][i + 1] && T[i][0] + R[j][0] + H[k][0] < res)
                        {
                            res = T[i][0] + R[j][0] + H[k][0];
                            ind[0] = i; ind[1] = j; ind[2] = k;
                        }

        if (res != INT_MAX)
            cout << ind[0] << " " << ind[1] << " " << ind[2] << ":" << res << "\n";
        else
            cout << "Don't get married!\n";
    }

}
