#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
    int n;
    while (cin >> n)
    {
        vi A(n * n);
        for (int i = 0; i < n * n; ++i)
        {
            cin >> A[i];
            if (i % n) A[i] += A[i - 1];
            if (i >= n) A[i] += A[i - n];
            if (i % n && i >= n) A[i] -= A[i - n - 1];
        }

        int m = -1e9;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = i; k < n; ++k)
                    for (int l = j; l < n; ++l)
                    {
                        int s = A[k * n + l];
                        if (i - 1 >= 0) s -= A[(i - 1) * n + l];
                        if (j - 1 >= 0) s -= A[k * n + j - 1];
                        if (i - 1 >= 0 && j - 1 >= 0) s += A[(i - 1) * n + j - 1];
                        m = max(m, s);
                    }
        cout << m << '\n';
    }
}
