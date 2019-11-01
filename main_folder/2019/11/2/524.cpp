#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi sol;

int A[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool prime(int a)
{
    return find(A, A + 10, a) != A + 10;
}

void f(int last, vi picked)
{
    if (!count(picked.begin(), picked.end(), 0) && prime(last + 1))
        sol.push_back(picked);

    for (int i = 0; i < picked.size(); ++i)
    {
        if(!picked[i] && prime(last + i + 1))
        {
            vi r(picked);
            r[i] = r.size() - count(r.begin(), r.end(), 0) + 1;
            f(i + 1, r);

        }
    }
}

int main()
{
    int n, cnt = 1;
    while (cin >> n)
    {
        if (cnt > 1)
            cout << "\n";
        
        cout << "Case " << cnt++ << ":\n";
        sol.clear();
        vi v(n);
        v[0] = 1;
        f(1, v);
        
        for (auto& s : sol)
        {
            vi tmp(n);
            for (int i = 0; i < s.size(); ++i)
                tmp[s[i] - 1] = i + 1;
            
            for (int i = 0; i < s.size(); ++i)
                cout << (i > 0 ? " " : "") << tmp[i];
            cout << "\n";
        }
    }
}
