#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    for (int i = 1; i + i + i < 2001; ++i)
        for (int j = i; i + j + j + j < 2001; ++j)
            for (int k = j; i + j + k + k < 2001; ++k)
            {
                ll p = i * j * k, s = i + j + k;
                if (p <= 1000000 || (1000000 * s) % (p - 1000000))
                    continue;
                int l = (1000000 * s) / (p - 1000000);
                if (k <= l && s + l < 2001)
                    cout << i * .01 << ' ' << j * .01 << ' ' << k * .01 << ' ' << l * .01 << '\n';
            }
}
