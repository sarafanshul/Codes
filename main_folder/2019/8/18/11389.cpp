#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    int n, d, r, A[100], B[100], tmp;
    while (cin >> n >> d >> r, n || d || r)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        sort(A, A + n);
        sort(B, B + n);

        int res = 0;        
        for (int i = 0; i < n; ++i)
            if (tmp = A[i] + B[n - i - 1] - d, tmp > 0)
                res += tmp * r;

        cout << res << "\n";
    }
}
