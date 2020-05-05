#include <iostream>
#include <cstring>
using namespace std;

int LUT[200][10][39], A[200], n, d;

int val(int id, int rem, int w)
{
    if (rem == 0) return w == 0;
    if (id == n) return 0;
    if (LUT[id][rem][w] != -1) return LUT[id][rem][w];
    
    return LUT[id][rem][w] = val(id + 1, rem, w) + val(id + 1, rem - 1, (w + A[id]) % d);
}

int main()
{
    int q, m, st = 1;
    while (cin >> n >> q, n || q)
    {
        cout << "SET " << st++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        for (int i = 0; i < q; ++i)
        {
            memset(LUT, -1, sizeof(LUT));
            cin >> d >> m;
            cout << "QUERY " << i + 1 << ": " << val(0, m, 0) << '\n';
        }
    }
}
