#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

bool slump(string s)
{
    if (s.size() > 2 && (s[0] == 'D' || s[0] == 'E') && s[1] == 'F')
    {
        size_t last_f = s.find_first_not_of('F', 1);
        if (last_f == string::npos)
            return false;
        return (s[last_f] == 'G' && last_f + 1 == s.size()) || slump(s.substr(last_f));
    }

    return false;
}

bool slimp(string s)
{
    if (s == "A" || s == "AH")
        return true;

    if (s.size() > 1 && s.substr(0, 2) == "AB" && s[s.size() - 1] == 'C')
        return slimp(s.substr(2, s.size() - 3));
    if (s.size() > 0 && s[0] == 'A' && s[s.size() - 1] == 'C')
        return slump(s.substr(1, s.size() - 2));
    
    return false;
}

bool slurpy(string s)
{    
    size_t fst = s.find_first_of('A');
    size_t c = s.find_last_of('C');
    if (c == string::npos)
        c = 0;
    size_t snd = s.find_first_of("DE", c + 1);
    
    if (fst == string::npos || fst > 0 || snd == string::npos)
        return false;
    
    return slimp(s.substr(fst, snd)) && slump(s.substr(snd));
}

int main()
{
    ios::sync_with_stdio(false);
    cout << "SLURPYS OUTPUT\n";
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        cout << (slurpy(s) ? "YES\n" : "NO\n");
    }
    cout << "END OF OUTPUT\n";    
}
