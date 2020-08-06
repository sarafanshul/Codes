#include <iostream>
#include <unordered_map>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, c = 1, n, a;
    cin >> N;
    while (N--)
    {
        unordered_map <int, int> M;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a, M[a]++;

        string s = "(";
        int it = 1, len = n;
        while (n--)
        {
            if (!M[it])
                break;

            M[it]--;
            if (M[it + 1])
                ++it, s += "(";
            else if (M[it - 1])
                --it, s += ")";
            else
                break;
        }
        
        cout << "Case " << c++ << ": " << (s.size() == len && it == 0 ? s : "invalid") << "\n";
    }
}
