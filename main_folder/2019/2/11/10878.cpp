#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t, sol;
    getline(cin, t);
    while (getline(cin, s), s != t)
    {
        int n = 0;
        for (int i = 1; i < s.size() - 1; ++i)
            if (s[i] == 'o')
                n += (1 << (7 - i + 1 + (i > 5 ? 1 : 0)));
        sol += string(1, char(n));
    }
    cout << sol;
}
