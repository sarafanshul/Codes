#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long n, l, u;
    while (cin >> n >> l >> u)
    {
        long res = 0;
        for (int i = 32; i >= 0; --i)
        {
            long status = (long(1) << i) & n;
            if (status)
            {
                // we want to have the i-th bit OFF
                long tmp = status - 1;
                tmp |= res; // highest possible without turning the i-th bit ON
                if (tmp < l)
                    res |= status;
            }
            else
            {
                // we want to have the i-th bit ON
                long tmp = res;
                tmp |= (long(1) << i);
                if (tmp <= u)
                    res = tmp;
            }
        }
        
        cout << res << "\n";
    }
}
