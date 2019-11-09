#include <iostream>
using namespace std;

int main()
{
    int l, d, i;
    cin >> l;
    while (cin >> d >> i, d != -1)
    {
        int res = 1;
        for (int j = 0; j < d - 1; ++j)
        {
            if (i % 2)
            {
                res = res * 2;
                i = (i + 1) / 2;
            }
            else
            {
                res = res * 2 + 1;
                i = i / 2;
            }
        }

        cout << res << "\n";
    }
}
