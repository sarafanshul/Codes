#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        size_t m = s.find_first_of('M');
        size_t e = s.find_first_of('E');
        if (m == string::npos || e == string::npos || m == 0 || e > s.size() - 3 ||
            e - m < 2 || count(s.begin(), s.end(), '?') != s.size() - 2)
        {
            cout << "no-theorem\n";
            continue;
        }

        if (e - 1 == s.size() - 1 - e)
            cout << "theorem\n";
        else
            cout << "no-theorem\n";
    }
}

