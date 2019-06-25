#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, M, Hex[10] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        string s = to_string(M);
        int h = 0;
        for (int j = 0; j < s.size(); ++j)
            for (int k = 0; k < 10; ++k)
                if (s[j] == '0' + k)
                    h += Hex[k];
        
        cout << __builtin_popcount(M) << ' ' << h << '\n';
    }
}
