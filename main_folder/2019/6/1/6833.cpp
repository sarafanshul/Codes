#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;

vs op(vs A, string c)
{
    vs B(A);
    for (int i = 1; i < B.size(); i += 2)
    {
        if (B[i] == c)
        {            
            vs C(B);
            C.erase(C.begin() + i - 1, C.begin() + i + 1);
            int l = stoi(B[i - 1]), r = stoi(B[i + 1]);
            C[i - 1] = to_string(c == "+" ? l + r : l * r);
            B = C;
            i -= 2;
        }
    }

    return B;
}

string it(vs A)
{
    int res = stoi(A[0]);
    for (int i = 1; i < A.size(); i += 2)
        res = A[i] == "+" ? res + stoi(A[i + 1]) : res * stoi(A[i + 1]);

    return to_string(res);
}

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        vs A(s.size());
        for (int i = 0; i < s.size(); ++i)
            A[i] = string(1, s[i]);
        
        string m = op(op(A, "*"), "+")[0];
        string n = it(A);

        if (m == t && n == t)
            cout << "U\n";
        else if (m == t)
            cout << "M\n";
        else if (n == t)
            cout << "L\n";
        else
            cout << "I\n";
    }
}
