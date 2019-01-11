#include <iostream>
#include <string>
#include <map> 
using namespace std;

int main()
{
    string E = "234567890-=ertyuiop[]dfghjkl;'#cvbnm,./ ";
    string F = "`1234567890qwertyuiopasdfghjkl;zxcvbnm, ";
    map<char, char> M;
    for (int i = 0; i < E.size(); ++i)
        M[E[i]] = F[i];

    string s;
    while (getline(cin, s))
    {
        for (char c : s)
            cout << M[tolower(c)];
        cout << '\n';
    }
}
