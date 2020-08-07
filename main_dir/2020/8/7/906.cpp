#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c, d;
    double n;
    while (cin >> a >> b >> n)
    {        
        for (d = 1; ; ++d)
        {
            c = (long double)(a * d) / b;
            while (a * d >= b * c)
                ++c;

            if ((long double)(c) / d - (long double)(a) / b < n)
            {
                cout << c << ' ' << d << '\n';
                break;
            }
        }
    }
}
