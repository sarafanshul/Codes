#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, h, f, c = 0;
    cin >> n;
    while (n--)
    {
        if (c++)
            cout << '\n';
        cin >> h >> f;

        string pat, res;
        for (int i = 1; i <= h; ++i)
            pat += string(i, char('0' + i)) + "\n";
        for (int i = h - 1; i >= 1; --i)
            pat += string(i, char('0' + i)) + "\n";

        
        for (int i = 0; i < f; ++i)
            res += (i > 0 ? "\n" : "") + pat;

        cout << res;
    }
}
