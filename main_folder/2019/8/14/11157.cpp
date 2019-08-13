#include <iostream>
using namespace std;

int main()
{
    int T, N, D, A[200], e;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> D;
        char c, d;
        int it = 0;
        A[it++] = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> c >> d >> e;
            A[it++] = e;
            if (c == 'B')
                A[it++] = e;
        }
        A[it++] = D;

        int res = 0;
        for (int i = 2; i < it; i += 2)
            res = max(res, A[i] - A[i - 2]);
        for (int i = 3; i < it; i += 2)
            res = max(res, A[i] - A[i - 2]);
            
        cout << "Case " << t << ": " << res << "\n";
    }
}
