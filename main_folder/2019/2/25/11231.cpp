#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m, c;
    while (cin >> n >> m >> c, n || m || c)
    {
        int wRows = (n - 8) / 2 + 1;
        int bRows = floor((n - 9) / 2.0) + 1;
        int wCols = floor((m - 8 - !c) / 2.0) + 1;
        int bCols = floor((m - 9 - !c) / 2.0) + 1;
        
        if (n > 8 && m > 8)
            cout << wRows * wCols + bRows * bCols + (c ? 0 : bRows) << "\n";
        else if (m > 8 || n > 8)
        {
            int w = (max(m, n) - 8) / 2 + 1;
            int b = (max(m, n) - 9) / 2 + 1;
            cout << (c ? w : b) << "\n";
        }
        else
            cout << c << "\n";
    }
}
