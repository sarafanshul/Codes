#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int cnt = 0;
    while (getline(cin, s))
    {
        size_t op = s.find_first_of("+-");
        size_t eq = s.find_first_of("=");
        int a = stoi(s.substr(0, op)), b = stoi(s.substr(op + 1, eq - op - 1));
        string c = s.substr(eq + 1);
        if (c == "?")
            continue;
        if (s[op] == '+')
            cnt += a + b == stoi(c);
        else
            cnt += a - b == stoi(c);
    }

    cout << cnt << '\n';
}
