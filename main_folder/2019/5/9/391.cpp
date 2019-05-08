#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    bool p = true;
    while (getline(cin, s))
    {
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '\\')
            {
                // Command
                if (p)
                {
                    // Processing of markup is on
                    if (s[i + 1] == 'b' || s[i + 1] == 'i')
                    {
                        ++i;
                    }
                    else if (s[i + 1] == 's')
                    {
                        ++i;
                        int dots = 0;
                        while (i + 1 < s.size() && (isdigit(s[i + 1]) || (dots < 1 && s[i + 1] == '.')))
                            ++i, dots += s[i] == '.' ? 1 : 0;
                    }
                    else if (s[i + 1] == '*')
                    {
                        ++i, p = false;
                    }
                    else if (i + 1 < s.size())
                    {
                        res += s[++i];
                    }
                }
                else if (!p && i + 1 < s.size() && s[i + 1] == '*')
                {
                    ++i;
                    p = true;
                }
                else
                {
                    res += s[i];
                }
            }
            else
                res += s[i];
        }

        cout << res << '\n';
    }
}
