#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    for (int c = 1; c <= n; ++c)
    {
        int M[26] = {};
        
        cin >> s;
        for (char ch : s)
            M[ch - 'a']++;

        cout << "Case " << c << ": " << *min_element(M, M + 26) << '\n';
    }
}
