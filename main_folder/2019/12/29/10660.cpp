#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int find_nb(int u, int G[5])
{
    unsigned m = -1, res = -1, tmp;
    for (int i = 0; i < 5; ++i)
        if (tmp = abs(u / 5 - G[i] / 5) + abs(u % 5 - G[i] % 5), tmp < m)
            m = tmp, res = i;

    return res;
}

int main()
{
    int n, m, x, y, z;
    cin >> n;
    while (n--)
    {
        int A[25] = {}, R[5];
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> z;
            A[5 * x + y] += z;
        }

        unsigned best = -1;
        for (int i = 0; i < 25; ++i)
            for (int j = i + 1; j < 25; ++j)
                for (int k = j + 1; k < 25; ++k)
                    for (int l = k + 1; l < 25; ++l)
                        for (int m = l + 1; m < 25; ++m)
                        {
                            unsigned tmp = 0;
                            int B[5] = {i, j, k, l, m};
                            for (int a = 0; a < 25; ++a)
                            {
                                int nb = find_nb(a, B);
                                tmp += A[a] * (abs(B[nb] / 5 - a / 5) + abs(B[nb] % 5 - a % 5));
                            }

                            if (tmp < best)
                                best = tmp, copy(B, B + 5, R);
                        }

        sort(R, R + 5);
        cout << R[0] << " " << R[1] << " " << R[2] << " " << R[3] << " " << R[4] << "\n";
                                
    }
}
