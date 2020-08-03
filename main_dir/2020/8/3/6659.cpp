#include <iostream>
#include <string>
using namespace std;

bool f(int a, int b, int C[26][1000])
{
    int A[26] = {}, n = 0;

    for (int i = 0; i < 26; ++i)
        n += (C[i][b] - (a ? C[i][a - 1] : 0) + 2) % 2;

    return n <= 1;
}

int main()
{
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        int C[26][1000] = {};
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); ++i)
            C[s[i] - 'a'][i] = 1;

        for (int i = 0; i < 26; ++i)
            for (int j = 1; j < 1000; ++j)
                C[i][j] = (C[i][j] + C[i][j - 1]) % 2;
       
        int c = 0;
        for (int i = 0; i < s.size(); ++i)
            for (int j = i; j < s.size(); ++j)
                c += f(i, j, C);

        cout << "Case " << T << ": " << c << '\n';
    }
}
