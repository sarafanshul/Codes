#include <iostream>
#include <string>
#include <map> 
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        map<char, int> M;
        for (char c : s)
            M[c] += 1;
        string res;
        int best = -1;
        for (int i = 0; i < 26; ++i)
            if (M['A' + i] > best)
                best = M['A' + i], res = string(1, 'A' + i);
            else if (M['A' + i] == best)
                res += string(1, 'A' + i);
        for (int i = 0; i < 26; ++i)
            if (M['a' + i] > best)
                best = M['a' + i], res = string(1, 'a' + i);
            else if (M['a' + i] == best)
                res += string(1, 'a' + i);

        cout << res << ' ' << best << '\n';
    }
}
