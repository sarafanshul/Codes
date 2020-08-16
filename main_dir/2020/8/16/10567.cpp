#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

inline int ind(char c)
{
    return isupper(c) ? c - 'A' + 26 : c - 'a';
}

int main()
{
    int n;
    string s, q;
    cin >> s >> n;

    vvi A(52);    
    for (int i = 0; i < s.size(); ++i)
        A[ind(s[i])].push_back(i);

    while (n--)
    {
        cin >> q;
        int it = -1;
        bool flag = true;
        for (char c : q)
        {
            int idx = ind(c);
            auto ub = upper_bound(A[idx].begin(), A[idx].end(), it);
            if (ub == A[idx].end())
            {
                flag = false;
                break;
            }
            else
                it = *ub;
        }

        int first = A[ind(q[0])][0];
        if (flag)
            cout << "Matched " << first << " " << it << "\n";
        else
            cout << "Not matched\n";
    }
}
