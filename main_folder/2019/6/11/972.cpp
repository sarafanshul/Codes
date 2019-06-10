#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define eps 1e-6
typedef pair<double, double> dd;

int main()
{
    ios::sync_with_stdio(false);
    cout << setprecision(3) << fixed;
    int n;
    while (cin >> n)
    {
        double x, y, res = 1e9;
        vector<dd> A[2];
        vector<double> X;
        for (int k = 0; k < 2; ++k)
        {
            if (k) cin >> n;
            double s = 0;
            for (int i = 0; i < n; ++i)
            {
                cin >> y >> x;
                A[k].emplace_back(s + x, y);
                s += x;
                X.emplace_back(s);
            }
        }
            
        sort(X.begin(), X.end());
        int i = 0, j = 0;
        for (double x : X)
        {
            while (A[0][i].first + eps < x && i + 1 < A[0].size()) ++i;
            while (A[1][j].first + eps < x && j + 1 < A[1].size()) ++j;
            res = min(res, max(A[0][i].second, A[1][j].second));
        }
        
        cout << res << '\n';
    }
}
