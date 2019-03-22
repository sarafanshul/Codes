#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

vi T, N;
vs E;

bool ok(int x)
{
    int c = N[0] * 10, l = 0, curr = x;
    for (int i = 1; i < T.size(); ++i)
    {
        curr -= (T[i] - T[i - 1]) * (c + l);
        if (curr < 0) return false;            
        
        if (E[i] == "Fuel consumption")
            c = N[i] * 10;
        else if (E[i] == "Leak")
            l += 1000;
        else if (E[i] == "Gas station")
            curr = x;
        else if (E[i] == "Mechanic")
            l = 0;
    }
    
    return curr >= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(3);
    int t, c; string s, _s;
    cin >> t >> s;
    while (cin >> _s >> c, c > 0)
    {
        T.assign(1, t); N.assign(1, c); E.assign(1, s + " " + _s);
        
        while (true)
        {
            cin >> t >> s;
            if (t == 0 && s == "Fuel")
                break;
            _s = "";
            if (s == "Fuel" || s == "Gas")
                cin >> _s;

            T.push_back(t);
            E.push_back(s + (_s.size() ? " " + _s : ""));
            if (s == "Fuel")
                cin >> t, N.push_back(t);
            else
                N.push_back(0);
        }
        
        int lo = 0, hi = 1e9;
        while (lo != hi)
        {
            int m = (lo + hi) / 2;
            if (ok(m))
                hi = m;
            else
                lo = m + 1;
        }
        cout << lo / 1000.0 << '\n';
    }
}
