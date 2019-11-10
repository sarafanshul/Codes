#include <algorithm>
#include <iostream>
using namespace std;

inline int dist(int a, int b)
{
    return min(abs(a - b), 24 - abs(a - b));
}

int main()
{
    int n, A[1001];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        sort(A, A + n);
        int r = 0;
        for (int i = 0; i < n; i += 2)
            r += dist(A[i], A[i + 1]);

        int q = dist(A[0], A[n - 1]);
        for (int i = 1; i < n - 1; i += 2)
            q += dist(A[i], A[i + 1]);

        cout << min(r, q) << '\n';
    }
}
