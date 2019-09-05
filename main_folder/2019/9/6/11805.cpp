#include <iostream>
using namespace std;

int main()
{
    int T, n, k, p;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> k >> p;
        cout << "Case " << t << ": " << ((k - 1 + p) % n) + 1 << endl;
    }
}
