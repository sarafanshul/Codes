#include <iostream>
#include <string> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s, S[8];
        cin >> s;
        for (int k = 0; k < 8; ++k)
            cin >> S[k];
        cin >> s;

        string res;
        for (int j = 1; j < S[0].size() - 1; ++j)
        {
            int x = 0;
            for (int k = 0; k < 8; ++k)
                if (S[k][j] == '\\')
                    x += 1 << k;
            res += char(x);
        }

        cout << res << '\n';
    }
}
