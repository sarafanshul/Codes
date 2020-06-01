#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        int A[26] = {};
        string s;
        getline(cin, s);
        for (char c : s)
            if (isalpha(c))
                A[tolower(c) - 'a']++;

        int m = *max_element(A, A + 26);
        for (int i = 0; i < 26; ++i)
            if (A[i] == m)
                cout << char('a' + i);
        cout << '\n';
    }
}
