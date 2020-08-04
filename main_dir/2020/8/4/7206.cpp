#include <iostream>
using namespace std;

int C[] = {1, 10, 100, 1000, 10000};

int main()
{
    int n, m, b;
    while (cin >> n >> m)
    {
        int t = 0;
        for (int k = 0; k < m; ++k)
        {
            int d, o = 0, tmp;
            cin >> b >> d;
            
            for (int i = 1; i < n; ++i)
                cin >> tmp, o += tmp;

            int r = 0;
            for (int c : C)
                if (o + c <= b)
                    r = max(r, c);

            if (r > d)
                t += (r - d);
            else if (r < d)
                t += r;
        }

        cout << t << '\n';
    }
}
