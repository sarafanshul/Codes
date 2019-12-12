#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    while (getline(cin, a), getline(cin, b))
    {
        int A[26] = {}, B[26] = {};
        for (char c : a)
            A[c - 'a']++;

        for (char c : b)
            B[c - 'a']++;

        string res;
        for (int i = 0; i < 26; ++i)
            res += string(min(A[i], B[i]), char('a' + i));

        cout << res << '\n';
    }
}
