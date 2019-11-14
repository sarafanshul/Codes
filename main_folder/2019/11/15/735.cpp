#include <iostream>
using namespace std;

inline int cmb(int i, int j, int k)
{
    if (i == j && j == k)
        return 1;
    if (i == j || i == k || j == k)
        return 3;
    return 6;
}

int main()
{
    ios::sync_with_stdio(false);
    int A[43] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33,
                 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60}, n;
    
    while (cin >> n, n > 0)
    {
        int c = 0, p = 0;
        for (int i = 0; i < 43; ++i)
            for (int j = i; j < 43; ++j)
                for (int k = j; k < 43; ++k)
                    if (A[i] + A[j] + A[k] == n)
                        ++c, p += cmb(A[i], A[j], A[k]);

        if (c)
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << ".\n"
                 << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << ".\n";
        else
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        cout << string(70, '*') << '\n';
    }
    cout << "END OF OUTPUT\n";
}
