#include <cctype>
#include <algorithm> 
#include <iostream>
#include <string> 
using namespace std;
#define ERR -1e9

int expr(string s);

int fact(string s)
{
    if (s.size() && all_of(s.begin(), s.end(), ::isdigit))
        return stoi(s);
    
    size_t le = s.find_first_of('('), ri = s.find_last_of(')');
    if (le == 0 && ri == s.size() - 1 &&
        count(s.begin(), s.end(), '(') == count(s.begin(), s.end(), ')'))
        return expr(s.substr(1, s.size() - 2));

    return ERR;
}

int comp(string s)
{
    size_t mult = s.find_first_of('*');

    while (mult != string::npos)
    {
        int a = fact(s.substr(0, mult)), b = comp(s.substr(mult + 1));
        if (a != ERR && b != ERR)
            return a * b;
        mult = s.find_first_of('*', mult + 1);
    }

    return fact(s);
}

int expr(string s)
{
    size_t plus = s.find_first_of('+');

    while (plus != string::npos)
    {
        int a = comp(s.substr(0, plus)), b = expr(s.substr(plus + 1));
        if (a != ERR && b != ERR)
            return a + b;
        plus = s.find_first_of('+', plus + 1);
    }

    return comp(s);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int res = expr(s);
        if (res != ERR)
            cout << res << '\n';
        else
            cout << "ERROR\n";               
    }
}
