#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef pair<double, double> dd;
typedef vector<dd> vdd;

int main()
{
    int n, l, w, a, r;
    while (cin >> n >> l >> w)
    {
        vdd A;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> r;           

            if (2.0 * r > w)
            {
                double dx = sqrt((double)r * r - .25 * w * w);
                A.emplace_back(a - dx, a + dx);
            }
        }

        sort(A.begin(), A.end(), [](dd x, dd y)
             {
                 return x.first < y.first || (x.first == y.first && x.second > y.second);
             });

        int cnt = 0, i = 0;
        double tail = 0;
        while (tail < l)
        {
            double m = tail;
            while (i < A.size() && A[i].first <= tail)
                m = max(m, A[i++].second);

            if (m - tail < 1e-9)
            {
                cnt = -1;
                break;
            }
                
            tail = m;
            ++cnt;
        }
                
        cout << cnt << endl;        
    }
}
