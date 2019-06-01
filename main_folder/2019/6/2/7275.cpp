#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int m, n, c = 0;
    while (cin >> m >> n)
    {
        if (c++)
            cout << '\n';
        
        int A[41] = {};
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                A[i + j]++;

        int m = *max_element(A, A + 41);
        for (int i = 0; i <= 40; ++i)
            if (A[i] == m)
                cout << i << '\n';
    }
}
