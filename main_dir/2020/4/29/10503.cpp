#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>


using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

bool f(vii& A, ii last, vb used, int max, ii end)
{
    int on = count(used.begin(), used. end(), true);
    
    if (on == max && last.second == end.first)
        return true;

    if (on >= max)
        return false;

    for (int i = 0; i < A.size(); ++i)
    {
        if (!used[i] && last.second == A[i].first)
        {
            vb u(used);
            u[i] = true;
            bool res = f(A, A[i], u, max, end);
            if (res)
                return res;
        }
        else if (!used[i] && last.second == A[i].second)
        {
            vb u(used);
            u[i] = true;
            bool res = f(A, make_pair(A[i].second, A[i].first), u, max, end);
            if (res)
                return res;
        }
    }

    return false;
}

int main()
{
    int m, n, s1, s2, e1, e2;
    while (cin >> n >> m, n)
    {
        vii A(m);
        cin >> s1 >> s2 >> e1 >> e2;
        for (int i = 0; i < m; ++i)
            cin >> A[i].first >> A[i].second;

        if (f(A, make_pair(s1, s2), vb(m), n, make_pair(e1, e2)))
            cout << "YES\n";
        else
            cout << "NO\n";            
    }
}
