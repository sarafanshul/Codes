#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

int check(string s, string w)
{
    if (::abs(s.size() - w.size()) > 1)
        return 2;
    
    int diff = 0, i = 0, j = 0;
    for (; i < s.size() && j <  w.size() && diff < 2; ++i, ++j)
    {
        if (s[i] != w[j])
        {
            ++diff;
            if (s.size() == w.size() && s[i + 1] == w[j] && w[j + 1] == s[i])
                ++i, ++j;
            else if (w.size() < s.size() && s[i + 1] == w[j])
                --j;
            else if (s.size() < w.size() && s[i] == w[j + 1])
                --i;
        }
    }
    
    return diff + s.size() - i + w.size() - j;
}

int main()
{
    int n, q;
    cin >> n;
    string A[10000], s;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> s;
        if (find(A, A + n, s) != A + n)
        {
            cout << s << " is correct\n";
            continue;
        }
        
        for (int j = 0; j < n; ++j)
        {
            int res = check(s, A[j]);
            if (res == 1)
            {
                cout << s << " is a misspelling of " << A[j] << '\n';
                break;
            }
            else if (j == n - 1)
                cout << s << " is unknown\n";
        }
    }        
}
