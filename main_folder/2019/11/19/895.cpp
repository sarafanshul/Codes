#include <iostream>
#include <map> 
#include <string>
using namespace std;

bool check(string& s, map<char, int> M)
{
    for (char c : s)
        if (M[c] > 0)
            --M[c];
        else
            return false;

    return true;
}

int main()
{
    int it = 0;
    string S[1001], t;
    while (getline(cin, S[it++]), S[it - 1] != "#");
    while (getline(cin, t), t != "#")
    {
        map<char, int> M;
        for (char c : t)
            M[c]++;

        int res = 0;
        for (int i = 0; i < it; ++i)
            res += check(S[i], M);

        cout << res << '\n';
    }
    
}
