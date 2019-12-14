#include <cstring>
#include <iostream>
#include <string> 
using namespace std;

int main()
{
    string s;
    int A[30] = {}, curr = 0;
    bool carry = false;
    while (getline(cin, s))
    {
        if (s[0] == '#')
        {
            A[curr]++; curr = 0; carry = false;
            for (int i = 1; i < 30; ++i)
                if (A[i])
                    cout << i << ' ' << A[i] << '\n';
            cout << '\n';
            
            memset(A, 0, sizeof(A));
            continue;
        }

        if (!carry)
            A[curr]++, curr = 0;
        else
            carry = false;
        for (char c : s)
            if (c == ' ' || c == '?' || c == '!' || c == ',' || c == '.')
                A[curr]++, curr = 0;
            else if (isalpha(c))
                curr++;


        if (!isalpha(s[s.size() - 1]) && curr)
            carry = true;
    }
}
