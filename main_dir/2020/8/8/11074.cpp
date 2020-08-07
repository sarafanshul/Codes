#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;

int main()
{
    int n, m, k, c = 1;
    while (cin >> n >> m >> k, n * m * k)
    {
        vs A((n + m) * k + m, string((n + m) * k + m, '*'));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                for (int x = 0; x < n; ++x)
                    for (int y = 0; y < n; ++y)
                        A[(n + m) * i + m + y][(n + m) * j + m + x] = '.';            

        cout << "Case " << c++ << ":\n";
        for (string& a : A)
            cout << a << '\n';
        cout << '\n';
    }
}
