#include <algorithm> 
#include <iostream>
#include <string>
using namespace std;

bool in(string A[6], int col, int c)
{
    for (int i = 0; i < 6; ++i)
        if (A[i][col] == c)
            return true;

    return false;
}

int main()
{
    int T, k;
    cin >> T;
    while (T--)
    {
        cin >> k;
        string A[6], B[6];
        for (int i = 0; i < 6; ++i)
            cin >> A[i];
        for (int i = 0; i < 6; ++i)
            cin >> B[i];

        string in_both[5];
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 26; ++j)
                if (in(A, i, 'A' + j) && in(B, i, 'A' + j))
                    in_both[i].push_back('A' + j);
        
        int max = 1;
        for_each(in_both, in_both + 5, [&](string s){max *= s.size();});
        for_each(in_both, in_both + 5, [](string& s){sort(s.begin(), s.end());});
        
        if (k-- > max)
            cout << "NO\n";
        else
        {
            string res;
            for (int i = 0; i < 5; ++i)
            {                
                max /= in_both[i].size();
                res += in_both[i][k / max];
                k = k % max;
            }
            cout << (res + "\n");
        }
    }
}
