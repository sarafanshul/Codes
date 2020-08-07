// Link: https://medium.com/@aiswaryamathur/find-the-n-th-permutation-of-an-ordered-string-using-factorial-number-system-9c81e34ab0c8

#include <algorithm>
#include <iostream>
#include <stack> 
#include <string>
using namespace std;

int main()
{
    int n;
    long long m;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s >> m;
        sort(s.begin(), s.end());
        // Convert m into factorial number system
        stack<int> F;
        int div = 1;
        while (m > 0)
        {
            F.push(m % div);
            m /= div++;
        }
        int diff = s.size() - F.size();
        for (int i = 0; i < diff; ++i)
            F.push(0);

        while (!F.empty())
        {
            int t = F.top(); F.pop();
            cout << s[t];
            s.erase(t, 1);
        }
        cout << '\n';
    }
}
