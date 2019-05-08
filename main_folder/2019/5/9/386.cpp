#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int a = 6; a <= 200; ++a)
        for (int b = 2; b < 200; ++b)
            for (int c = b; c < 200; ++c)
            {
                double t =  pow(pow(a, 3) - pow(b, 3) - pow(c, 3), 1/3.0);
                for (int d = max(c, int(t)); d < t + 1; ++d)
                {
                    if (a*a*a == b*b*b + c*c*c + d*d*d)
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c <<  "," << d << ")\n";
                }
            }
}
