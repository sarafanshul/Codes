#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    int b, s, c = 1, B[10000], S[10000];
    while (cin >> b >> s, b || s)
    {        
        for (int i = 0; i < b; ++i)
            cin >> B[i];

        for (int i = 0; i < s; ++i)
            cin >> S[i];

        sort(B, B + b);

        if (b <= s)
            cout << "Case " << c++ << ": 0\n";
        else
            cout << "Case " << c++ << ": " << b - s << " " << B[0] << "\n";
    }
}
