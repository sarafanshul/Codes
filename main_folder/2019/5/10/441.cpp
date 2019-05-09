#include <iostream>
using namespace std;

int main()
{
    int n, A[13] = {};
    while (cin >> n, n)
    {
        if (A[0] != 0)
            cout << "\n";
        
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        for (int a = 0; a < n - 4; ++a)
            for (int b = a + 1; b < n - 3; ++b)
                for(int c = b + 1; c < n - 2; ++c)
                    for (int d = c + 1; d < n - 1; ++d)
                        for (int e = d + 1; e < n; ++e)
                            for (int f = e + 1; f < n; ++f)
                                cout << A[a] << " " << A[b] << " " << A[c] << " " << A[d] << " " << A[e] << " " << A[f] << "\n";
    }
}
