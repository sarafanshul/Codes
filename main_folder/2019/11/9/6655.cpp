#include <iostream>
using namespace std;

int main()
{
    int t, x1, y1, x2, y2;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int p1 = x2 - x1, p2 = y2 - y1;
        int r1 = -p2, r2 = p1, q1 = 0, q2 = 0;
        
        if (r1 < 0)
            q1 = -r1, r1 = 0;
        if (r2 < 0)
            q2 = -r2, r2 = 0;

        cout << "Case " << T << ": " << r1 << ' ' << r2 << ' ' << q1 << ' ' << q2 << '\n';
    }
}
