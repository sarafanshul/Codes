#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, q, d, l;
    char c;
    cin >> n;
    while (n--)
    {
        int A[11] = {}, B[11] = {};
        cin >> q;
        while (q--)
        {
            cin >> d >> l >> c;
            if (c == 'c' && l)
                B[d]++;
            else if (c == 'i' && !l)
                A[d]++;
        }

        for (int i = 0; i < 10; ++i)
            A[i + 1] += A[i];

        int res = 0;
        for (int i = 1; i < 11; ++i)
            res += B[i] * A[i - 1];

        cout << res << '\n';
    }
}
