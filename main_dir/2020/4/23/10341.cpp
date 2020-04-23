#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

int p, q, r, s, t, u;
inline float eval(float x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
    cout << fixed << setprecision(4);
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        float left = 0, right = 1, x;
        float l = eval(left), r = eval(right);
        if (l < 1e-3 && l > -1e-3)
            cout << "0.0000\n";
        else if (r < 1e-3 && r > -1e-3)
            cout << "1.0000\n";
        else if (eval(left) * eval(right) < 0)
        {
            bool flag = eval(left) > 0;
            for (int i = 0; i < 30; ++i)
            {
                x = (left + right) / 2;
                bool f = eval(x) < 0;

                if (flag ? !f : f)
                    left = x;
                else
                    right = x;
            }

            cout << x << "\n";
        }
        else
            cout << "No solution\n";
    }
}
