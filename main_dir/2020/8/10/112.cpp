#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int n;

bool tree(string s, int sum)
{
    if (s == "()")
        return false;
    
    int it = 1;
    bool neg = false;
    if (s[it] == '-')
        ++it, neg = true;

    string num;
    while (isdigit(s[it]))
        num += s[it++];

    int start = it++; // '('
    int le = 1, ri = 0;
    while (le != ri)
    {
        le += s[it] == '(';
        ri += s[it] == ')';
        ++it;
    }

    int val = stoi(num) * (neg ? -1 : 1);
    string t1 = s.substr(start, it - start), t2 = s.substr(it, s.size() - it - 1);

    if (t1 == "()" && t2 == "()")
        return sum + val == n;
    
    return tree(t1, sum + val)
        || tree(t2, sum + val);
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        int le = 0, ri = 0;
        string s, t;
        
        do
        {
            cin >> t;
            s += t;
            for (char c : t)
                le += c == '(', ri += c == ')';

        } while (le != ri);
        
        cout << (tree(s, 0) ? "yes\n" : "no\n");        
    }
}
