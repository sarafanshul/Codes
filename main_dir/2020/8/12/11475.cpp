#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

int b[100001];
void kmpPre(string& s)
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < s.size())
    {
        while (j >= 0 && s[i] != s[j])
            j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

int kmpSearch(string& t, string& s)
{
    int i = 0, j = 0;
    while (i < t.size())
    {
        while (j >= 0 && t[i] != s[j])
            j = b[j];

        ++i; ++j;
    }
    return j;
}

int main()
{
    string s, t;
    while (cin >> s)
    {
        t = s;
        reverse(t.begin(), t.end());
        kmpPre(t);
        int mtch = kmpSearch(s, t);
        string res = s.substr(0, s.size() - mtch);
        reverse(res.begin(), res.end());
        cout << s << res << '\n';
    }
}
