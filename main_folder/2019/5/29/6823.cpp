#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

inline int rem(int a)
{
    if (a == 1) return 2;
    if (a == 2) return 1;
    return 0;
}

ll f(string t)
{
    ll r = 0, A[3] = {};
    for (int i = 0; i < t.size(); ++i)
    {
        rotate(A, A + rem(t[i] % 3), A + 3);
        A[t[i] % 3]++;
        r += A[0];
    }

    return r;
}

int main()
{
    string s;
    while (cin >> s)
    {
        ll r = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                int j = i;
                while (j + 1 < s.size() && isdigit(s[j + 1]))
                    ++j;

                string t = s.substr(i, j - i + 1);
                r += f(t);                
                i = j;
            }
        }

        cout << r << endl;
    }
}
