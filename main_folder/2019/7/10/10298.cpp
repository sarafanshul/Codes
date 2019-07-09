#include <algorithm> 
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s, s != ".")
    {
        map<char, int> M;
        for (char c : s)
            M[c]++;

        bool flag = true;
        for (int i = s.size(); i > 0 && flag; --i)
            if (!(s.size() % i) && all_of(M.begin(), M.end(), [&](pair<char, int> a){return !(a.second % i);}))
            {
                int d = s.size() / i;
                bool a = true;
                for (int j = 0; j < i && a; ++j)
                    if (s.substr(j * d, d) != s.substr(0, d))
                        a = false;
                    
                if (a)
                    cout << i << '\n', flag = false;
            }
    }
}
