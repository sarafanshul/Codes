#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<pair<int, int> > A, B;
        string s;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            for (int j = 0; j < n; ++j)
                if (s[j] == '1')
                    A.emplace_back(i, j);
                else if (s[j] == '3')
                    B.emplace_back(i, j);
        }

        int b = 0;
        for (auto e : A)
        {
            int a = INT_MAX;
            for (auto f : B)
                a = ::min(a, ::abs(e.first - f.first) + ::abs(e.second - f.second));
            b = ::max(b, a);
        }

        cout << b << "\n";
    }

}
