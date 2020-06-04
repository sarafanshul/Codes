#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    string s;
    while (t--)
    {
        getline(cin, s);
        int dp[1000][1000] = {}, size = s.size();

        for (int i = 0; i < size; ++i)
            dp[i][i] = 1;
        
        for (int i = 0; i < size - 1; ++i)
            dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;


        for (int d = 2; d < size; ++d)
        {
            for (int dd = 0; dd < size - d; ++dd)
            {
                int i = dd, j = d + dd;
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        
        int M = 0;
        for (int i = 0; i < size; ++i)
            for (int j = i; j < size; ++j)
                M = max(M, dp[i][j]);
        cout << M << '\n';
    }
}
