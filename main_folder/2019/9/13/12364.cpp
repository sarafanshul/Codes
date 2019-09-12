#include <iostream>
#include <string>
using namespace std;

string S1[] = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
string S2[] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};

int main()
{
    int n;
    char s;
    string t, u, v;
    while (cin >> n >> s, cin.ignore(), n)
    {
        if (s == 'S')
        {
            getline(cin, t);
            string s1, s2, s3;
            for (int i = 0; i < n; ++i)
            {
                s1 += (i == 0 ? "" : " ") + S1[t[i] - '0'];
                s2 += (i == 0 ? "" : " ") + S2[t[i] - '0'];
                s3 = s3 + (i == 0 ? "" : " ") + "..";
            }
            cout << s1 << '\n' << s2 << '\n' << s3 << '\n';
        }
        else
        {
            getline(cin, t);
            getline(cin, u);
            getline(cin, v);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j <= 9; ++j)
                    if (t.substr(3 * i, 2) == S1[j] && u.substr(3 * i, 2) == S2[j])
                        cout << j;
            cout << '\n';
        }
    }
}
