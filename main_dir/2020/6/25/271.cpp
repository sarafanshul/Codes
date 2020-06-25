#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string trimN(string s)
{
    string res;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'N')
        {
            while (i + 1 < s.size() && s[i + 1] == 'N')
                ++i;
            if (s[i + 1] == 'p')
                res += "p", ++i;
            else
                res += "N";
        }
        else
            res += s[i];
    }
        
    return res;
}

string trimC(string s)
{
    string res;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'C' && i < s.size() - 2 && s[i + 1] == 'p' && s[i + 2] == 'p')
            res += "p", i += 2;
        else res += s[i];

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s)
    {
        for (char& c : s)
            if (islower(c))
                c = 'p';
            else if (c != 'N')
                c = 'C';

        string t = trimC(trimN(s));
        while (s != t)
            s = t, t = trimC(trimN(s));

        if (t == "p")
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

