#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int in(int a, int b)
{
    int r = 0;
    for (int i = 0; i < 20; ++i)
        if (((1 << i) & a) == ((1 << i) & b) && (1 << i) & a)
            ++r;

    return r;
}

int main()
{
    int n, m, sol, loc, t, v, o, C = 1;
    while (cin >> n >> m, n + m)
    {
        vii A;        
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            A.emplace_back(1 << i, t);
        }
        
        cin >> o;
        while (o--)
        {
            cin >> t;
            int bm = 0;
            for (int i = 0; i < t; ++i)
                cin >> v, bm |= (1 << --v);
            cin >> v;
            A.emplace_back(bm, v);
        }

        sol = -1;
        for (int a = 1; a < (1 << n); ++a)
            if (__builtin_popcount(a) == m)
            {
                int r = 0;
                for (int i = 0; i < n; ++i)
                    if (a & A[i].first)
                        r += A[i].second;
                
                for (int i = n, d; i < A.size(); ++i)
                    if (d = in(A[i].first, a), d > 0)
                        r -= (d - 1) * A[i].second;
    
                if (r > sol)
                    sol = r, loc = a;
            }
        
        cout << "Case Number  " << C++ << '\n'
             << "Number of Customers: " << sol << '\n'
             << "Locations recommended:";
        for (int i = 0; i < 20; ++i)
            if (loc & (1 << i))
                cout << ' ' << i + 1;
        cout << "\n\n";
    }
}
