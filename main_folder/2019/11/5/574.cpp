#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int A[12], t, n;
vvi res;

void print(vi v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << (i > 0 ? "+" : "") << v[i];
    cout << "\n";
}

void f(int it, vi picked, int sum)
{    
    if (sum == t)
        res.push_back(picked);

    if (sum >= t)
        return;
    
    for (int i = it; i < n; ++i)
    {
        vi r(picked);
        r.push_back(A[i]);
        f(i + 1, r, sum + A[i]);
    }
}

int main()
{
    while (cin >> t >> n, t || n)
    {
        cout << "Sums of " << t << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        res.clear();
        f(0, vi(), 0);
        sort(res.rbegin(), res.rend());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));

        if (res.size())
            for (auto v : res)
                print(v);
        else
            cout << "NONE\n";
    }
}
