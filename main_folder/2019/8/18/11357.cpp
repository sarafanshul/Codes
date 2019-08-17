#include <iostream>
#include <map>
#include <string>
using namespace std;

bool f(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            bool block = true;
            map<char, int> M1, M0;
            while (s[++i] != ')')
            {
                if (s[i] == '&' || !block)
                {
                    continue;
                }
                if (s[i] == '~')
                {
                    M0[s[++i]] = 1;
                    if (M1.count(s[i]))
                        block = false;
                }
                else
                {
                    M1[s[i]] = 1;
                    if (M0.count(s[i]))
                        block = false;
                }
            }
            if (block)
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        cout << (f(s) ? "YES\n" : "NO\n");
    }
}
