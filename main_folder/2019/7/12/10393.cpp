#include <algorithm>
#include <iostream>
#include <string>
#include <set> 
using namespace std;

string F[] = {"qaz", "wsx", "edc", "rfvtgb", "", "", "yhnujm", "ik", "ol", "p;/"};

int main()
{
    int a, b, c;
    while (cin >> a >> b)
    {
        string s, t;
        bool B[10] = {}, L[26] = {};
        for (int i = 0; i < a; ++i)
            cin >> c, B[--c] = 1;

        for (int i = 0; i < 10; ++i)
            if (!B[i])
                for (char c : F[i])
                    L[c - 'a'] = 1;

        set<string> res;
        for (int i = 0; i < b; ++i)
        {
            cin >> t;
            if ((res.empty() || t.size() >= (*res.begin()).size()) &&
                all_of(t.begin(), t.end(), [&](char c){return L[c - 'a'] == 1;}))
            {
                if (res.empty() || t.size() > (*res.begin()).size())
                    res.clear();
                res.insert(t);
            }
        }

        cout << res.size() << '\n';
        for (string s : res)
            cout << s << '\n';
    }
}
