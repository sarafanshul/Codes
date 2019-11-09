#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    ll a, b;
    string s;
    while (cin >> a >> b >> s)
    {
        ll r = 0, c = a / (a - b);
        int mid = count(s.begin(), s.end(), 'B');
        int rhs = count(s.begin() + mid, s.end(), 'B');

        vi ri, le;
        for (int i = 0; i < c; ++i)
        {
            if (mid + i < s.size() && s[mid + i] == 'B')
                ri.push_back(mid + i);
            if (mid - i - 1 >= 0 && s[mid - i - 1] == 'W')
                le.push_back(mid - i - 1);
        }
        
        for (int i = 0; i < ri.size(); ++i)
            for (int j = 0; j < le.size(); ++j)
                if ((ri[i] - le[j]) * (a - b) < a)
                {
                    r = r + (ri[i] - le[j]) * (a - b);
                    --rhs; le[j] = -1e9;
                    break;
                }

        cout << (r + rhs * a) << '\n';
    }
}
