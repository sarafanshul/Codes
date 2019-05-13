#include <iostream>
#include <string>
using namespace std;

int check(string& s, int i)
{
    for (int j = 0; j < s.size() / i; ++j)
        if (s.substr(j * i, i) != s.substr(0, i))
            return 0;

    return i;
}

int main()
{
    int T;
    cin >> T;
    string s;
    while (T--)
    {
        cin >> s;
        int b = 0;
        for (int i = 1; !b && i <= s.size(); ++i)
            if (!(s.size() % i))
                b = check(s, i);

        cout << b << '\n';
        if (T)
            cout << '\n';
    }
}
