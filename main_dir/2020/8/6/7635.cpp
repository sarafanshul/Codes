#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;;

double dist(ii& a, ii& b)
{
    int x = a.first - b.first, y = a.second - b.second;
    return sqrt(x * x + y * y);
}

int main()
{
    ios::sync_with_stdio(false);
    cout << setprecision(2) << fixed;
    int n, q, r;

    while (cin >> n >> q, n || q)
    {
        vii A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i].first >> A[i].second;

        vi D(40000);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                D[ceil(dist(A[i], A[j]))] += 2;

        int c = 0;
        for (int k = 0; k < 40001; ++k)
            c = D[k] += c;
        
        while (q--)
        {
            cin >> r;
            
            // Include the carrier of the bomb, i.e. add 1 victim.
            cout << double(D[r]) / n + 1 << '\n';
        }
        
        cout << '\n';
    }
}
