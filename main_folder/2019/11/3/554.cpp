#include <iostream>
#include <string> 
using namespace std;

int count(string& n, string& hs)
{
    int cnt = 0;
    int f = hs.find(n);
    while (f != string::npos)
        ++cnt, f = hs.find(n, f + 1);

    return cnt;
}

int main()
{
    int it = 0, best = -1;
    string S[100], text, res;
    while (getline(cin, S[it++]), S[it - 1] != "#");
    getline(cin, text);
    for (char& c : text)
        if (c == ' ')
            c = '@';

    for (int i = 1; i <= 26; ++i)
    {
        string txt = text;
        for (char& c : txt)
            c = ((c - '@' + i) % 27) + '@';

        int cnt = 0;
        for (int j = 0; j < it; ++j)
            cnt += count(S[j], txt);

        if (cnt > best)
            best = cnt, res = txt;
    }

    for (char& c : res)
        if (c == '@')
            c = ' ';

    int iter = 0;
    while (iter < res.size())
    {
        int last = res.find_last_of(' ', iter + 60);
        cout << res.substr(iter, last - iter) << '\n';
        iter = last + 1;            
    }
}
