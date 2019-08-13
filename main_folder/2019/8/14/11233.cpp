#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string V = "aeiou";
bool notVowel(char c)
{
    for (int i = 0; i < 5; ++i)
        if (c == V[i])
            return false;
    
    return true;
}

bool chckIes(string& s)
{
    return s.size() > 1 && notVowel(s[s.size() - 2])
        && s[s.size() - 1] == 'y';
}

bool chckEtc(string& s)
{
    char l = s[s.size() - 1];
    if (l == 'o' || l == 's' || l == 'x')
        return true;
    if (s.size() > 1)
    {
        string m = s.substr(s.size() - 2);
        return m == "ch" || m == "sh";
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int l, n;
    cin >> l >> n;
    unordered_map<string, string> M;
    string k, v;
    for (int i = 0; i < l; ++i)
    {
        cin >> k >> v;
        M[k] = v;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        auto it = M.find(k);
        if (it != M.end())
            cout << it->second << '\n';
        else if (chckIes(k))
            cout << k.substr(0, k.size() - 1) << "ies\n";
        else if (chckEtc(k))
            cout << k << "es\n";
        else
            cout << k << "s\n";
    }
}
