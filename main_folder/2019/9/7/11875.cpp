#include <iostream>
using namespace std;

int main()
{
    int T, n, k;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n;
        cout << "Case " << t << ": ";
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            if (i == n / 2)
                cout << k << '\n';
        }
    }
}
