#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

double res;
vii A;

double dist(int i, int j)
{
    return hypot(A[i].first - A[j].first, A[i].second - A[j].second);
}

void f(int seen, double acc)
{
    int p = -1;
    for (int i = 0; i < A.size() && p == -1; ++i)
        if (!((1 << i) & seen))
            p = i;

    if (acc > res)
        return;
    
    if (p == -1)
    {
        res = min(res, acc);
        return;
    }

    int _seen = seen | (1 << p);
    for (int i = 0; i < A.size(); ++i)
        if (!((1 << i) & _seen))
            f(_seen | (1 << i), acc + dist(p, i));
}

int main()
{
    cout << fixed << setprecision(2);
    int n, c = 1;
    string s;
    while (cin >> n, n)
    {
        n *= 2;
        A.assign(n, ii());
        for (int i = 0; i < n; ++i)
            cin >> s >> A[i].first >> A[i].second;

        res = 1e9;
        f(0, 0);
        cout << "Case " << c++ << ": " << round(res * 100) / 100 << '\n';
    }
}
