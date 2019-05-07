#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int sumdiv(int a)
{
    if (a == 1)
        return 0;
    
    int r = 1;
    for (int i = 2; i * i < a; ++i)
        if (!(a % i))
            r += i + a / i;

    if (sqrt(a) == int(sqrt(a)))
        r += sqrt(a);

    return r;
}

int main()
{
    cout << "PERFECTION OUTPUT\n";
    int a;
    while (cin >> a, a)
    {
        int d = sumdiv(a);
        if (d == a)
            cout << setw(5) << a << "  PERFECT\n";
        else if (d > a)
            cout << setw(5) << a << "  ABUNDANT\n";
        else
            cout << setw(5) << a << "  DEFICIENT\n";
    }
    cout << "END OF OUTPUT\n";
}
