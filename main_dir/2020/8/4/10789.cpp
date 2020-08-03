#include <cmath> 
#include <iostream>
#include <map> 
#include <string>
using namespace std;

bool prime(int x)
{
    if (x < 2)
        return false;
    
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        string s;
        cin >> s;
        map<char, int> M;
        for (char c : s)
            M[c]++;

        string res;
        bool flag = false;
        for (auto& el : M)
            if (prime(el.second))
                res += string(1, el.first), flag = true;
        
        cout << "Case " << i << ": " << (flag ? res : "empty") << '\n';
    }
}
