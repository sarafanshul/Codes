#include <iostream>
using namespace std;

int main()
{
    int n, a, b, c;
    while (cin >> n, n)
    {
        int m = 0, v = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> c;
            if (c > m || (c == m && v < a * b * c))
                m = c, v = a * b * c;
        }

        cout << v << '\n';            
    }
}
