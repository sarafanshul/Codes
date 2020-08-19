#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<string> vs;

int main()
{
    int n, x1, x2, y1, y2, c = 1;
    while (cin >> n >> y1 >> x1 >> y2 >> x2, n)
    {
        cout << "Case " << c++ << ":\n";
        vs A(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                A[i][j] = (n - i + j - 1) % 26 + 'a';

        for (int i = 0; i < n; ++i)
        {
            string r = A[i].substr(1);
            reverse(r.begin(), r.end());
            A[i] = r + A[i];
        }

        for (int i = 1; i < n; ++i)
            A.push_back(A[n - i - 1]);

         for (int i = y1; i <= y2; ++i)
         {
             for (int j = x1; j <= x2; ++j)
                 cout << A[i % A.size()][j % A[0].size()];
             cout << '\n';
         }
    }
}
