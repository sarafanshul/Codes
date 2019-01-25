#include <iostream>
#include <map> 
#include <string>
using namespace std;

int main()
{
    int T, r, q, it;
    cin >> T;
    while (T--)
    {
        cin >> r;
        cin.ignore();
        map<char, string> R;
        string s;
        for (int i = 0; i < r; ++i)
        {
            getline(cin, s);
            R[s[0]] = s.substr(3);
        }

        cin >> q;
        char c;
        for (int i = 0; i < q; ++i)
        {
            cin >> s >> c >> it;
            map<char, unsigned long long> Q;
            for (char c : s)
                Q[c]++;
            
            for (int i = 0; i < it; ++i)
            {
                map<char, unsigned long long> _Q;
                for (auto& el : Q)
                    if (R[el.first].size())
                        for (char c : R[el.first])
                            _Q[c] += el.second;
                    else
                        _Q[el.first] += el.second;

                Q = _Q;
            }
            cout << Q[c] << '\n';
        }
    }
}

