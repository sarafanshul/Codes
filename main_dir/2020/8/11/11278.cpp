#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string qw = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? \\";
    string dv = "`123qjlmfp/[]456.orsuyb;=789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" \\";
    map<char, char> M;
    for (int i = 0; i < qw.size(); ++i)
        M[qw[i]] = dv[i];
    
    string s;
    while (getline(cin, s))
    {
        for (char c : s)
            cout << M[c];
        cout << '\n';
    }
}
