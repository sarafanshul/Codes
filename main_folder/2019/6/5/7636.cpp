#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int h2d(string s)
{
    int r = 0;
    for (char c : s)
        r = 16 * r + (isalpha(c) ? c - 'A' + 10 : c - '0');
    
    return r;
}

int o2d(string s)
{
    int r = 0;
    for(char c : s)
        r = 8 * r + c - '0';
        
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    string s, t;
    int n, a;
    while (cin >> s >> n, n)
    {
        if (s[0] != '0')
            a = stoi(s);
        else if (s.size() > 1 && s[1] == 'x')
            a = h2d(s.substr(2));
        else
            a = o2d(s.substr(1));

        int pts = 0;
        for (int i = 0; i < n; ++i)
        {
            bool f; int diff = 0, b;
            cin >> t >> b;
            if (t == "i++")
                f = a++ == b, diff = 1;
            else if (t == "++i")
                f = ++a == b;
            else if (t == "i--")
                f = a-- == b, diff = -1;
            else if (t == "--i")
                f = --a == b ;
            else
                f = a == b;
            
            pts += f;
            a = b + diff;                
        }
        
        cout << pts << '\n';
    }
}
