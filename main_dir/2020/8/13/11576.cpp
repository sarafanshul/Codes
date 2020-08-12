#include <iostream>
#include <string>
using namespace std;

int b[10001];

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
    int T, k, w;
    cin >> T;
    while (T--)
    {
        string res, s;
        cin >> k >> w >> res;
        for (int i = 0; i < w - 1; ++i)
        {
            cin >> s;
            kmpPre(s);
            int j = kmpSearch(res, s);
            res += s.substr(j);
        }
        cout << res.size() << '\n';
    }
}
