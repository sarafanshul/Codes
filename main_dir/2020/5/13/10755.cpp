#include <iostream>
using namespace std;

int main()
{
    int T, a, b, c;
    cin >> T;
    while (T--)
    {
        long A[20][20][20];
        long best = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                for (int k = 0; k < c; ++k)
                {
                    cin >> A[i][j][k];
                    best += A[i][j][k];
                    if (i > 0)
                        A[i][j][k] += A[i - 1][j][k];
                    if (j > 0)
                        A[i][j][k] += A[i][j - 1][k];
                    if (i > 0 && j > 0)
                        A[i][j][k] -= A[i - 1][j - 1][k];
                    if (k > 0)
                        A[i][j][k] += A[i][j][k - 1];
                    if (i > 0 && k > 0)
                        A[i][j][k] -= A[i - 1][j][k - 1];
                    if (j > 0 && k > 0)
                        A[i][j][k] -= A[i][j - 1][k - 1];
                    if (i > 0 && j > 0 && k > 0)
                        A[i][j][k] += A[i - 1][j - 1][k - 1];
                }
        
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                for (int k = 0; k < c; ++k)
                    for (int m = i; m < a; ++m)
                        for (int n = j; n < b; ++n)
                            for (int o = k; o < c; ++o)
                            {
                                long val = A[m][n][o];
                                if (i > 0)
                                    val -= A[i - 1][n][o];
                                if (j > 0)
                                    val -= A[m][j - 1][o];
                                if (i > 0 && j > 0)
                                    val += A[i - 1][j - 1][o];
                                if (k > 0)
                                {
                                    val -= A[m][n][k - 1];
                                    if (i > 0)
                                        val += A[i - 1][n][k - 1];
                                    if (j > 0)
                                        val += A[m][j - 1][k - 1];
                                    if (i > 0 && j > 0)
                                        val -= A[i - 1][j - 1][k - 1];
                                }

                                best = max(best, val);
                            }
        cout << best << "\n";
        if (T)
            cout << "\n";
    }
}
