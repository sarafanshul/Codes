#include <iostream>
using namespace std;

int main()
{
    int T, n, A[1000];
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        int sum = 0, cnt = 0;
        for (int i = 0; i < n - 1; ++i)
            if (sum + A[i] < A[i + 1])
                sum += A[i], ++cnt;

        cout << cnt + 1 << endl;
    }
}
