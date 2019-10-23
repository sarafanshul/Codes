#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        int sum = 0;
        for (char c : s)
        {
            if (isdigit(c))
                sum += c - '0';
            else if (c == '!')
                cout << '\n';
            else
                cout << string(sum, c == 'b' ? ' ' : c), sum = 0;
        }

        char c = s.back();
        cout << string(sum, c == 'b' ? ' ' : c) << '\n';            
    }
}
