#include <iostream>
#include <string> 
using namespace std;

int main()
{
    int T, n;
    string s;
    cin >> T;
    for (int c = 1; c <= T; ++c)
    {
        cin >> n >> s;
        int it = 0, res = 0;
        while (it < s.size())
        {
            if (s[it] == '.')
                ++res, it += 3;
            else
                ++it;
        }

        cout << "Case " << c << ": " << res << "\n";
    }
}
